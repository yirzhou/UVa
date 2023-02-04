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

int memo[100005][3];

class Solution {
  public:
    typedef pair<int, int> ii;
    vector<ii> intervals;

    int gap = 0;
    int getcnt(vector<int> &pos, int num, int i) {
        int nxt = num + gap;
        auto iter = lower_bound(pos.begin() + i, pos.end(), nxt + 1);
        int ni = iter - pos.begin();
        return ni - i;
    }

    int dp(int i, int k) {
        if (k == 0) return 0;
        if (i == intervals.size()) return INT_MIN;
        if (memo[i][k] != -1) return memo[i][k];
        int ans = intervals[i].second, lo = intervals[i].first;
        ii p = {lo + gap + 1, 0};
        int nxt = lower_bound(intervals.begin(), intervals.end(), p) -
                  intervals.begin();
        ans = max(ans, max(intervals[i].second + dp(nxt, k - 1), dp(i + 1, k)));
        return memo[i][k] = ans;
    }
    map<int, int> mp;

    int maximizeWin(vector<int> &pos, int K) {
        gap = K;
        vector<int> cnt;
        int n = pos.size();

        for (int i = 0; i < pos.size(); ++i) {
            int num = pos[i];
            if (mp.count(num)) continue;
            mp[num] = i;
        }

        for (auto &[num, i] : mp) {
            int count = getcnt(pos, num, i);
            intervals.push_back({num, count});
        }
        memset(memo, -1, sizeof memo);
        return dp(0, 2);
    }
};
