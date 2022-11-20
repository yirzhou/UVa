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

#define MAXN 10000010

bitset<MAXN> bs;
ll _sieve_size;
vi primes;

int n;

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

bool is_prime(ll n)
{
    if (n <= _sieve_size)
        return bs[n];
    for (int i = 0; i < primes.size(); ++i) {
        if (primes[i] * primes[i] > n)
            return true;
        if (n % primes[i] == 0)
            return false;
    }
    return true;
}

ll solve(ll N)
{
    ll maxp = 2;
    N = abs(N);
    ll PF_idx = 0, PF = primes[0];
    ll cnt = 0;

    while (PF * PF <= N) {
        bool counted = false;
        while (N % PF == 0) {
            N /= PF;
            cnt = !counted ? cnt + 1 : cnt;
            counted = true;
            maxp = max(maxp, PF);
        }

        PF = primes[++PF_idx];
    }

    if (N != 1)
        cnt++, maxp = max(maxp, N);
    return cnt > 1 ? maxp : -1;
}

int main()
{
    sieve(MAXN);
    ll N;
    while (cin >> N && N) {
        ll res = solve(N);
        cout << res << endl;
    }
}