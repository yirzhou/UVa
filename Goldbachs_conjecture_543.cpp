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

ii solve(int target)
{
    int lo = 0, hi = primes.size() - 1;
    while (lo <= hi) {
        int sum = primes[lo] + primes[hi];
        if (sum == target)
            return { primes[lo], primes[hi] };
        else if (sum < target)
            lo++;
        else
            hi--;
    }
    return { 0, 0 };
}

int main()
{
    primes.clear();
    sieve(MAXN);
    while (si(n) && n) {
        ii res = solve(n);
        if (res.first)
            printf("%d = %d + %d\n", n, res.first, res.second);
        else
            printf("Goldbach's conjecture is wrong.\n");
    }
}