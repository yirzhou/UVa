#include <algorithm>
#include <assert.h>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define oo INT_MAX
#define UNVISITED -1
#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define pll(a, b) printf("%lld %lld\n", a, b)
#define plll(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define fastio                                                                 \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(0)
#define precision(a)                                                           \
    cout << fixed;                                                             \
    cout.precision(a)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

#define MAXN 1000010

bitset<MAXN> bs;
ll _sieve_size;
vi primes;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.pb((int)i);
        }
    }
}

bool is_prime(ll n) {
    if (n <= _sieve_size) return bs[n];
    for (int i = 0; i < primes.size(); ++i) {
        if (primes[i] * primes[i] > n) return true;
        if (n % primes[i] == 0) return false;
    }
    return true;
}

ll num_div(ll N) {
    ll idx = 0, pf = primes[idx], ans = 1;
    while (pf * pf <= N) {
        ll power = 0;
        while (N % pf == 0) { N /= pf, power++; }
        ans *= (power + 1);
        pf = primes[++idx];
    }
    if (N != 1) ans *= 2;
    return ans;
}

int main() {
    fastio;
    int t, n;
    vl nums;
    ll num;
    cin >> t;
    sieve(1000000);
    while (t--) {
        cin >> n;
        nums.assign(n, 0);
        for (int i = 0; i < n; ++i) cin >> nums[i];

        sort(ALL(nums));
        ll res = nums[0] * nums.back();
        vl divs;
        for (ll i = 2LL; i * i <= res; ++i) {
            if (res % i == 0) {
                divs.pb(i);
                if (i != res / i) divs.pb(res / i);
            }
        }

        sort(ALL(divs));
        if (divs == nums) cout << res;
        else cout << -1;
        cout << endl;
    }

    return 0;
}
