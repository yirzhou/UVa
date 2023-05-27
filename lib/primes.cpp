#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

#define MAXN 1000010

bitset<MAXN> bs;
ll _sieve_size;
vi primes;

void sieve(ll upperbound)
{
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; ++i)
    {
        if (bs[i])
        {
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.pb((int)i);
        }
    }
}

bool is_prime(ll n)
{
    if (n <= _sieve_size) return bs[n];
    for (int i = 0; i < primes.size(); ++i)
    {
        if (primes[i] * primes[i] > n) return true;
        if (n % primes[i] == 0) return false;
    }
    return true;
}

void factor(int num, unordered_map<int, int> &f)
{
    ll idx = 0, pf = primes[idx];
    while (pf * pf <= num)
    {
        ll power = 0;
        while (num % pf == 0) num /= pf, power++;
        if (power != 0) f[pf] += power;
        pf = primes[++idx];
    }
    if (num != 1) f[num]++;
}

void factor(ll num)
{
    ll z = 2;

    while (z * z <= num)
    {
        if (num % z == 0)
        {
            // TODO: do stuff with z
            num /= z;
        }
        else { z++; }
    }

    if (num > 1)
    {
        // TODO: do stuff with num
    }
}
