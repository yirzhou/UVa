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

#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define fastio                                                                                                         \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(0)
#define precision(a)                                                                                                   \
    cout << fixed;                                                                                                     \
    cout.precision(a)

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
#define oo INT_MAX
#define UNVISITED -1
#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;

ll memo[1000010][2];

const int BITS = 20;

ll f(ll a, ll b)
{
    ll ans = 0;
    for (int i = BITS - 1; i >= 0; --i)
    {
        ll b1 = (a >> i) & 1, b2 = (b >> i) & 1;
        if (b1 == 0 && b2 == 0) continue;
        if (b1 == 0 && b2 == 1) ans |= (1 << i);
        if (b1 == 1 && b2 == 0)
        {
            ans |= (1 << i);
            break;
        }
        if (b1 == 1 && b2 == 1) ans |= (1 << i);
    }

    return ans;
}
// a' + (a'|b') + (1-a-b) => minimise a' + (a'|b')
// a <= a' and b <= b'
int main()
{
    fastio;
    ll t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        ll ans = b - a;
        for (ll a_prime = a; a_prime <= b; ++a_prime)
        {
            ll b_prime = f(a_prime, b);
            ans = min(ans, a_prime + (a_prime | b_prime) + (1 - a - b));
        }
        cout << ans << endl;
    }
    return 0;
}
