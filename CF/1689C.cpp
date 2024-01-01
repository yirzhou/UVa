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
#define fastio                                                                 \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(0)
#define precision(a)                                                           \
    cout << fixed;                                                             \
    cout.precision(a)

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

vvi AL;

map<ii, int> mp;

vi children(int p, int u) {
    vi ans;
    for (auto &v : AL[u]) {
        if (v != p) ans.pb(v);
    }
    return ans;
}

int dfs(int p, int u) {
    if (mp.count({p, u})) return mp[{p, u}];
    int count = 1;
    for (auto &v : AL[u])
        if (v != p) count += dfs(u, v);
    return mp[{p, u}] = count;
}

int f(int p, int u) {
    vi next = children(p, u);
    if (next.empty()) return 0;
    if (next.size() == 1) {
        int v = next[0];
        return mp[{u, v}] - 1;
    }
    int a = next[0], b = next[1];
    return max(mp[{u, a}] - 1 + f(u, b), mp[{u, b}] - 1 + f(u, a));
}

int main() {
    fastio;
    int t, n, u, v;
    cin >> t;
    while (t--) {
        cin >> n;
        AL.assign(n + 1, vi());

        for (int i = 0; i < n - 1; ++i) {
            cin >> u >> v;
            AL[u].pb(v), AL[v].pb(u);
        }
        mp.clear();
        dfs(0, 1);
        int ans = f(0, 1);
        cout << ans << endl;
    }
}
