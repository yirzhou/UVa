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

// 1 <= n <= 10^5
// m == paths.length
// 2 <= m <= 10^5
// sum(paths[i].length) <= 10^5
// 0 <= paths[i][j] < n
// The same city is not listed multiple times consecutively in paths[i].

/*
BSTA:
- guess len
- use sliding window
*/

ull extEuclid(ull a, ull b, ull &x, ull &y) {
    unsigned long long xx = y = 0;
    ull yy = x = 1;
    while (b) {
        ull q = a / b;
        ull t = b;
        b = a % b;
        a = t;
        t = xx;
        xx = x - q * xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a;
}

ull mod(ull a, ull m) { return ((a % m) + m) % m; }
ull modInverse(ull b, ull m) {
    ull x, y;
    ull d = extEuclid(b, m, x, y);
    if (d != 1) return -1;
    return mod(x, m);
}

class RH {
    vector<ull> P;
    vector<ull> h;
    const ull p = 100019, M = 1000000000019;

  public:
    RH() {}

    void prepareP(int n) {
        P.assign(n, 0);
        P[0] = 1;
        for (int i = 1; i < n; ++i) { P[i] = ((ull)P[i - 1] * p) % M; }
    }

    void compute_rolling_hash(vector<int> &T) {
        prepareP(T.size());
        h = vector<ull>(T.size(), 0);
        for (int i = 0; i < T.size(); ++i) {
            if (i != 0) h[i] = h[i - 1];
            h[i] = (h[i] + ((ull)T[i] * P[i])) % M;
        }
    }

    ull hash_fast(int L, int R) {
        if (L == 0) return h[R];
        ull ans = 0;
        ans = (h[R] - h[L - 1] + M) % M;
        ans = ((ull)ans * modInverse(P[L], M)) % M;
        return ans;
    }
};

class Solution {
  public:
    const ull p = 100001, M = 1000000000019;
    int good(vvi &paths, int k) {
        unordered_map<ull, int> mp;
        for (int i = 0; i < paths.size(); ++i) {
            RH rh;
            rh.compute_rolling_hash(paths[i]);
            for (int j = 0; j < paths[i].size() - k + 1; ++j)
                mp[rh.hash_fast(j, j + k - 1)]++;
        }

        for (auto &[h, cnt] : mp)
            if (cnt == paths.size()) return 1;
        return 0;
    }

    int longestCommonSubpath(int n, vector<vector<int>> &paths) {

        int lo = 0, hi = INT_MAX;
        for (auto &p : paths) hi = min(hi, (int)p.size());
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            piii(lo, mid, hi);
            if (good(paths, mid)) {
                lo = mid;
            } else hi = mid - 1;
        }

        return lo;
    }
};
