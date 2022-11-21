#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;

#define MAXN 1000010

bitset<MAXN> bs;
ll _sieve_size;
vi primes;

vll phis;

void sieve(ll upperbound)
{
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.pb((int)i);
        }
    }
}

ll EulerPhi(ll N)
{
    ll idx = 0, pf = primes[idx], ans = N;
    while (pf * pf <= N) {
        if (N % pf == 0)
            ans -= ans / pf;
        while (N % pf == 0)
            N /= pf;
        pf = primes[++idx];
    }
    if (N != 1)
        ans -= ans / N;
    return ans;
}

void pre_EulerPhi(ll N)
{
    phis = vll(N + 1, 0);
    for (int i = 2; i <= N; ++i) {
        phis[i] = EulerPhi(i);
    }
}

vll memo;
ll dp(ll num)
{
    if (num == 1)
        return 0;
    if (memo[num] != -1)
        return memo[num];
    return memo[num] = 1 + dp(phis[num]);
}

void init(int N)
{
    memo.assign(N + 1, -1);
    memo[1] = 0;
    for (int i = 2; i <= N; ++i)
        memo[i] = dp(i);
    for (int i = 3; i <= N; ++i)
        memo[i] += memo[i - 1];
}

const int MAX = 2000000;

int main()
{
    sieve(MAXN);
    pre_EulerPhi(MAX + 5);
    init(MAX);
    int N, m, n;
    cin >> N;
    while (N--) {
        cin >> m >> n;
        cout << memo[n] - memo[m - 1] << endl;
    }
}