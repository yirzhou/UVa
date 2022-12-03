#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define pll(a, b) printf("%lld %lld\n", a, b)
#define plll(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
#define precision(a) \
    cout << fixed;   \
    cout.precision(a)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vll;

ii D[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

#define MAX 2703665

bitset<INT_MAX> bs;
ll _sieve_size;
vi p;

int NumPF[MAX + 10] = { 0 };
int N;

void sieve(ll upperbound = MAX)
{
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            p.pb((int)i);
        }
    }
}

void modified_sieve(ll upper = MAX)
{
    for (int i = 2; i <= upper; ++i) {
        if (NumPF[i] == 0) {
            for (int j = i; j <= upper; j += i)
                ++NumPF[j];
        }
    }
}

int numPF(ll N)
{
    int ans = 0;
    for (int i = 0; (i < (int)p.size()) && (p[i] * p[i] <= N); ++i)
        while (N % p[i] == 0) {
            N /= p[i];
            ++ans;
        }
    return ans + (N != 1);
}

void pre(ll upper = MAX)
{
    for (int i = 2; i <= upper; ++i) {
        if (!NumPF[i])
            NumPF[i] = 1;
        for (int j = 2; j <= i && i * j < upper; ++j) {
            NumPF[j * i] = NumPF[j] + NumPF[i];
        }
    }

    for (int i = 2; i <= upper; ++i)
        NumPF[i] += NumPF[i - 1];
}

void pre2(ll upper = MAX)
{
    for (ll i = 2; i <= upper; ++i) {
        NumPF[i] = numPF(i);
    }

    for (ll i = 2; i <= upper; ++i)
        NumPF[i] += NumPF[i - 1];
}

int main()
{
    fastio;
    sieve();
    pre2();

    int caseno = 1;
    while (cin >> N && N >= 0) {
        auto it = lower_bound(NumPF, NumPF + MAX, N);
        cout << "Case " << caseno++ << ": ";
        if (*it != N)
            cout << "Not possible.";
        else
            cout << it - NumPF << "!";
        cout << endl;
    }
    return 0;
}