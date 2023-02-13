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
    int m, n;
    vvi pre;

  public:
    int good(int t, int len) {
        for (int i = 0; i < m - len + 1; ++i)
            for (int j = 0; j < n - len + 1; ++j)
                if (sum(i, j, i + len - 1, j + len - 1) <= t) return 1;

        return 0;
    }

    int sum(int x1, int y1, int x2, int y2) {
        return pre[x2 + 1][y2 + 1] - pre[x1][y2 + 1] - pre[x2 + 1][y1] +
               pre[x1][y1];
    }

    int maxSideLength(vector<vector<int>> &mat, int t) {
        m = mat.size(), n = mat[0].size();
        pre = vvi(m + 1, vi(n + 1, 0));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] + mat[i - 1][j - 1] -
                            pre[i - 1][j - 1];

        int lo = 0, hi = n + 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (good(t, mid)) lo = mid + 1;
            else hi = mid;
        }
        lo = min(lo, n);
        return max(good(t, lo) ? lo : lo - 1, 0);
    }
};
