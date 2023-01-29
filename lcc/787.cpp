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

ll memo[105][105];

class Solution {
  public:
    int n;
    vector<vector<ii>> G;
    int s, t;
    ll dp(int u, int k) {
        if (k < 0)
            return INT_MAX;
        if (u == t)
            return 0;
        if (memo[u][k] != -1)
            return memo[u][k];
        ll res = INT_MAX;
        for (auto &[v, cost] : G[u])
            res = min(res, cost + dp(v, k - 1));

        return memo[u][k] = res;
    }

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                          int k) {
        this->n = n;
        G.assign(n, vector<ii>());
        s = src, t = dst;
        for (auto &f : flights) {
            int u = f[0], v = f[1], cost = f[2];
            G[u].pb({v, cost});
        }
        memset(memo, -1, sizeof memo);
        ll res = dp(src, k + 1);
        return res < INT_MAX ? res : -1;
    }
};
