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

ii D[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, k;
vvi AL;
int visited[200005] = {0}, depths[200005] = {0}, sz[200005] = {1};

int dfs(int p, int u, int dist) {
    depths[u] = dist;
    int cnt = 1;
    for (auto &v : AL[u])
        if (v != p) cnt += dfs(u, v, dist + 1);
    sz[u] = cnt - 1;
    return cnt;
}

int main() {
    fastio;
    cin >> n >> k;
    AL.assign(n, vi());
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--, AL[u].pb(v), AL[v].pb(u);
    }
    dfs(-1, 0, 0);
    vi diff(n);
    for (int u = 0; u < n; ++u) diff[u] = sz[u] - depths[u];
    sort(ALL(diff), [](const int &a, const int &b) { return a > b; });
    ll ans = 0;
    for (int i = 0; i < n - k; ++i) ans += diff[i];
    cout << ans << endl;
    return 0;
}
