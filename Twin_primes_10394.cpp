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

#define MAXN 20000009
#define MAXM 100000

bitset<INT_MAX> bs;
ll _sieve_size;
vll primes;

vector<ii> twins;

int n;

void sieve(ll upperbound = INT_MAX)
{
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.pb(i);
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

ii solve(int n)
{
    if (n < twins.size())
        return twins[n];
    int j = twins.size(), i = twins.back().second;
    for (; i < INT_MAX - 1 && j < n; ++i) {
        if (is_prime(i) && is_prime(i + 2)) {
            twins.pb({ i, i + 2 });
            j++;
        }
    }
    return twins.back();
}

void precalc(int N)
{
    for (ll i = 3; i < MAXN && twins.size() < N; ++i) {
        if (is_prime(i) && is_prime(i + 2)) {
            twins.pb({ i, i + 2 });
        }
    }
}

int main()
{
    int S;
    sieve(MAXN);
    precalc(100000);
    while (cin >> S) {
        ii res = solve(S - 1);
        printf("(%d, %d)\n", res.first, res.second);
    }
}