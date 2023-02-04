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

class Solution {
  public:
    int m, n;
    int id(int r, int c) { return r * n + c; }
    int N;

    vector<vi> AL;
    unordered_set<int> S;

    int mem1[1005][1005];
    int mem2[1005][1005][2];

    void print(set<ii> &S) {
        for (auto &[x, y] : S)
            cout << "(" << x << "," << y << ")"
                 << " ";
        cout << endl;
    }

    bool dfs(vector<vi> &grid, int i, int j) {
        if (i == m - 1 && j == n - 1) { return 1; }
        if (mem1[i][j] != -1) { return mem1[i][j]; }
        if ((i + 1 < m && grid[i + 1][j] && dfs(grid, i + 1, j)) ||
            (j + 1 < n && grid[i][j + 1] && dfs(grid, i, j + 1))) {
            return mem1[i][j] = 1;
        }

        return mem1[i][j] = 0;
    }

    /*
    1. Finding AP doesn't work.
    2. DSU with disconnect (no)
    3. SSSP (TLE);
    4. DP(i,j,k) where k = 1 (doesn't work).
    */

    struct cmp {
        bool operator()(const ii &a, const ii &b) { return a.se > b.se; }
    };

    int sssp(int bx, int by) {
        priority_queue<ii, vector<ii>, cmp> pq;
        pq.push({0, 0});

        vl dist(m * n, INT_MAX);
        dist[0] = 0;

        while (pq.size()) {
            int u = pq.top().fi, cost = pq.top().se;
            pq.pop();
            if (u == m * n - 1) return 1;
            for (auto &v : AL[u]) {
                if (bx * n + by == v) continue;
                if (cost + 1 < dist[v]) {
                    dist[v] = cost + 1;
                    pq.push({v, cost + 1});
                }
            }
        }

        return 0;
    }

    int dp(vector<vector<int>> &grid, int i, int j, int k) {
        if (i == 0 && j == 0) return 0;
        if (i < 0 || j < 0 || grid[i][j] == 0) return 1;
        if (mem2[i][j][k] != -1) return mem2[i][j][k];
        if (k) {
            int a1 = dp(grid, i, j - 1, k - 1);
            int a2 = dp(grid, i - 1, j, k - 1);
            // Cut (i,j) works.
            if (a1 || a2) return mem2[i][j][k] = 1;
        }
        // Cut (i,j) doesn't work.
        // Try others
        int a1 = dp(grid, i - 1, j, k);
        int a2 = dp(grid, i, j - 1, k);

        return mem2[i][j][k] = a1 | a2;
    }

    bool bfs(vvi &grid) {
        ii target{m - 1, n - 1};
        queue<ii> q;
        q.push({0, 0});
        vvi vis(m, vi(n, 0));
        while (q.size()) {
            int sz = q.size();
            set<ii> S;
            while (sz--) {
                int x = q.front().fi, y = q.front().se;
                q.pop();
                if (vis[x][y]) continue;
                if (x == m - 1 && y == n - 1) return 0;
                vis[x][y] = 1;
                if (x + 1 < m && grid[x + 1][y] && !vis[x + 1][y]) {
                    q.push({x + 1, y});
                    S.insert({x + 1, y});
                }

                if (y + 1 < n && grid[x][y + 1] && !vis[x][y + 1]) {
                    q.push({x, y + 1});
                    S.insert({x, y + 1});
                }
            }

            if (S.size() == 1 && S.count(target) == 0) return 1;
        }

        return 0;
    }

    bool isPossibleToCutPath(vector<vector<int>> &grid) {
        m = grid.size();
        n = grid[0].size();
        memset(mem1, -1, sizeof mem1);
        N = m * n;
        if (!dfs(grid, 0, 0)) return 1;

        return bfs(grid);
    }
};
