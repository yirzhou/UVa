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

/*
Given an n x n grid containing only values 0 and 1, where 0 represents water and
1 represents land, find a water cell such that its distance to the nearest land
cell is maximized, and return the distance. If no land or water exists in the
grid, return -1.

The distance used in this problem is the Manhattan distance: the distance
between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
*/
class Solution {
  public:
    int n;
    int seen[105][105];

    map<ii, int> mp;

    int bfs(vvi &grid) {
        queue<vi> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) q.push({i, j, 0});
            }
        }

        memset(seen, 0, sizeof seen);
        int ans = -1;
        while (q.size()) {
            int x = q.front()[0], y = q.front()[1], d = q.front()[2];
            q.pop();
            if (!grid[x][y] && !mp.count({x, y})) {
                mp[{x, y}] = d;
                ans = max(ans, d);
            }
            if (seen[x][y]) continue;
            seen[x][y] = 1;
            for (auto &[dx, dy] : D) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !grid[nx][ny] &&
                    !seen[nx][ny])
                    q.push({nx, ny, d + 1});
            }
        }

        return ans;
    }
    int maxDistance(vector<vector<int>> &grid) {
        n = grid.size();
        return bfs(grid);
    }
};
