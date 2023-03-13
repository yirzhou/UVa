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
vvl AL, range;

ll memo[100005][2];

ll dfs(ll p, ll u, int val) {
    if (memo[u][val] != -1) return memo[u][val];
    ll ans = 0LL;
    ll value = (val == 0) ? range[u][0] : range[u][1];
    for (auto &v : AL[u]) {
        if (v == p) continue;
        ll vl = range[v][0], vr = range[v][1];
        ans +=
            max(dfs(u, v, 0) + abs(value - vl), dfs(u, v, 1) + abs(value - vr));
    }

    return memo[u][val] = ans;
}

int main() {
    fastio;
    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        AL = vvl(n);
        range = vvl(n, vl(2, 0));
        for (ll i = 0; i < n; ++i) cin >> range[i][0] >> range[i][1];
        for (ll i = 0; i < n - 1; ++i) {
            ll u, v;
            cin >> u >> v;
            u--;
            v--;
            AL[u].pb(v), AL[v].pb(u);
        }
        memset(memo, -1, sizeof memo);
        ll a, b;
        a = dfs(-1, 0, 0);
        memset(memo, -1, sizeof memo);
        b = dfs(-1, 0, 1);
        cout << max(a, b) << endl;
    }

    return 0;
}
