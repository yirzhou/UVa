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

ll sum_div(ll N)
{
    ll PF_idx = 0, PF = primes[0], ans = 1;
    while (PF * PF <= N) {
        ll power = 0;
        while (N % PF == 0)
            N /= PF, power++;
        ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);
        PF = primes[++PF_idx];
    }
    if (N != 1)
        ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1);
    return ans;
}

int main()
{
    ll S;
    int caseno = 1;
    sieve(MAXN);
    while (cin >> S && S) {
        printf("Case %d: ", caseno++);
        if (S == 1)
            printf("%lld", S);
        else {

            ll res = 0;
            for (ll i = 2; i <= 1000; ++i) {
                if (sum_div(i) == S) {
                    res = i;
                }
            }
            if (!res)
                printf("%d", -1);
            else
                printf("%lld", res);
        }

        printf("\n");
    }
}