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
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
#define precision(a) \
    cout << fixed;   \
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

ii D[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

/**
aa, ab, ac, ad, ...
ba, bb, bc, bd, ...
...
za, zb, zc, zd, ...

Eulerian cycle - such a genius way.
*/

vvi AL;
vi hierholzer(int n, int s)
{
    vi ans, idx(n, 0), st;

    st.pb(s);
    while (!st.empty()) {
        int u = st.back();
        if (idx[u] < (int)AL[u].size()) {
            st.pb(AL[u][idx[u]]);
            ++idx[u];
        } else {
            ans.pb(u);
            st.pop_back();
        }
    }
    reverse(ALL(ans));
    return ans;
}

int main()
{
    fastio;

    int n, k;
    cin >> n >> k;
    AL.assign(k, vi());
    for (int u = 0; u < k; ++u) {
        for (int v = 0; v < k; ++v) {
            AL[u].pb(v);
        }
    }

    vi tour = hierholzer(k, 0);
    string ans;
    for (int i = 0; i < tour.size() && ans.size() < n; ++i) {
        ans.pb(tour[i] + 'a');
    }
    for (int i = tour.size() - k * k; ans.size() < n; i++) {
        if (i == tour.size())
            i = tour.size() - k * k;
        ans.pb('a' + tour[i]);
    }

    cout << ans << endl;
}
