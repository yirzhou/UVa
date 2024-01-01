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

unordered_set<int> AL[200005];
int colors[200005];

map<ii, int> memo;

int dfs(int p, int u) {
    if (memo.count({p, u})) return memo[{p, u}];

    if (p == 0) {
        for (auto &v : AL[u])
            if (!dfs(u, v)) return memo[{p, u}] = 0;
        return memo[{p, u}] = 1;
    }
    int color_u = colors[u], color_v;
    for (auto &v : AL[u]) {
        if (v == p) continue;
        color_v = colors[v];
        if (color_u != color_v || !dfs(u, v)) { return memo[{p, u}] = 0; }
    }
    return memo[{p, u}] = 1;
}

int main() {
    fastio;
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        AL[u].insert(v), AL[v].insert(u);
    }
    for (int i = 1; i <= n; ++i) cin >> colors[i];

    for (int u = 1; u <= n; ++u) {
        if (dfs(0, u)) {
            cout << "YES" << endl << u << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
