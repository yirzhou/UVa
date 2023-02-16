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

int memo[1005][1005];
int mp[1005][1005];

const int OFF = 500;

class Solution {
  public:
    int n;
    unordered_set<int> S;

    int dp(int i, int diff) {
        if (mp[i][diff] == -1) return 1;
        if (memo[i][diff] != -1) return memo[i][diff];
        int ans = 1;
        ans += dp(mp[i][diff], diff);
        return memo[i][diff] = ans;
    }
    int longestArithSeqLength(vector<int> &nums) {
        n = nums.size();
        memset(mp, -1, sizeof mp);
        memset(memo, -1, sizeof memo);
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int diff = nums[j] - nums[i] + OFF;
                S.emplace(diff);
                if (mp[i][diff] == -1) mp[i][diff] = j;
            }
        }

        int ans = 0;
        for (auto &diff : S)
            for (int i = 0; i < n - 1; ++i) ans = max(dp(i, diff), ans);
        return ans;
    }
};
