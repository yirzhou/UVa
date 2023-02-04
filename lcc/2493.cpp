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

/*
You are given a positive integer n representing the number of nodes in an
undirected graph. The nodes are labeled from 1 to n.

You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates
that there is a bidirectional edge between nodes ai and bi. Notice that the
given graph may be disconnected.

Divide the nodes of the graph into m groups (1-indexed) such that:

Each node in the graph belongs to exactly one group.
For every pair of nodes in the graph that are connected by an edge [ai, bi], if
ai belongs to the group with index x, and bi belongs to the group with index y,
then |y - x| = 1. Return the maximum number of groups (i.e., maximum m) into
which you can divide the nodes. Return -1 if it is impossible to group the nodes
with the given conditions.
*/
class Solution {
  public:
    vvi AL;
    int n;

    int seen[505] = {0};

    int bp(int s) {
        queue<ii> q;
        q.push({s, 0});

        unordered_map<int, int> color;
        while (q.size()) {
            int u = q.front().fi, c = q.front().se;
            q.pop();
            seen[u] = 1;

            for (auto &v : AL[u]) {
                if (color.count(v) && color[v] == c) return 0;
                if (!color.count(v)) {
                    color[v] = !c;
                    q.push({v, !c});
                }
            }
        }

        return 1;
    }

    int check() {
        for (int u = 1; u < n; ++u)
            if (!seen[u] && !bp(u)) return 0;
        return 1;
    }

    unordered_set<int> S;

    void dfs(int u) {
        if (seen[u]) return;
        S.insert(u);
        seen[u] = 1;
        for (auto &v : AL[u]) dfs(v);
    }

    int bfs(int s) {
        queue<ii> q;
        q.push({s, 1});
        vi vis(n, 0);
        int res = 0;
        while (q.size()) {
            int u = q.front().fi, d = q.front().se;
            q.pop();
            if (vis[u]) continue;
            res = max(res, d);
            vis[u] = 1;
            for (auto &v : AL[u])
                if (!vis[v]) q.push({v, d + 1});
        }
        return res;
    }

    int solve() {
        int res = 0;
        for (auto &s : S) res = max(res, bfs(s));
        return res;
    }

    int magnificentSets(int n, vector<vector<int>> &edges) {
        this->n = n + 1;
        AL = vvi(this->n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            AL[u].pb(v), AL[v].pb(u);
        }

        if (!check()) return -1;

        memset(seen, 0, sizeof seen);
        int res = 0;
        for (int u = 1; u < this->n; ++u)
            if (!seen[u]) S.clear(), dfs(u), res += solve();
        return res;
    }
};
