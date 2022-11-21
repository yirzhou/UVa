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

ll num_div(ll N)
{
    ll idx = 0, pf = primes[idx], ans = 1;
    while (pf * pf <= N) {
        ll power = 0;
        while (N % pf == 0) {
            N /= pf, power++;
        }
        ans *= (power + 1);
        pf = primes[++idx];
    }
    if (N != 1)
        ans *= 2;
    return ans;
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

int main()
{
    ll n;
    sieve(MAXN);
    while (cin >> n && n) {
        ll res = EulerPhi(n);
        printf("%lld\n", res);
    }
}