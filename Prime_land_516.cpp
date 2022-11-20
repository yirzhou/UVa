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

#define MAXN 32767

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

void solve(ll num)
{
    vector<ii> factors;
    ll idx = 0, pf = primes[idx];
    while (pf * pf <= num) {
        ll power = 0;
        while (num % pf == 0)
            num /= pf, power++;
        if (power != 0)
            factors.pb({ pf, power });
        pf = primes[++idx];
    }
    if (num != 1)
        factors.pb({ num, 1 });
    for (int i = factors.size() - 1; i >= 0; --i)
        printf(i == 0 ? "%d %d\n" : "%d %d ", factors[i].first, factors[i].second);
}

int main()
{
    string s;
    sieve(MAXN);
    while (getline(cin, s) && s != "0") {
        std::istringstream sstr(s);
        vi v;
        ll val, num = 1;
        while (sstr >> val)

            v.pb(val);
        for (int i = 1; i < v.size(); i += 2)
            num *= (int)pow(v[i - 1], v[i]);
        num -= 1;
        solve(num);
    }
}