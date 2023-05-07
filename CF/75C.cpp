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

void factor(ll num, unordered_set<int> &factors)
{
    factors.insert(1);
    factors.insert(num);
    ll i = 2;
    while (i <= sqrt(num))
    {
        if (num % i == 0)
        {
            factors.insert(i);
            if (i != (num / i)) factors.insert(num / i);
        }
        i++;
    }
}

int main()
{
    fastio;
    ll a, b, n;
    cin >> a >> b >> n;
    unordered_set<int> f1, f2;
    factor(a, f1), factor(b, f2);
    vl factors;
    for (auto &num : f1)
        if (f2.count(num)) factors.pb(num);

    sort(ALL(factors));
    while (n--)
    {
        ll lo, hi;
        cin >> lo >> hi;
        auto iter = upper_bound(ALL(factors), hi) - 1;
        if (iter != factors.end() && *iter >= lo) cout << *iter << endl;
        else cout << -1L << endl;
    }
    return 0;
}
