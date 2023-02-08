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

/*
Input: inventory = [3,5], orders = 6
Output: 19
Explanation: Sell the 1st color 2 times (3 + 2) and the 2nd color 4 times (5 + 4
+ 3 + 2). The maximum total value is 3 + 2 + 5 + 4 + 3 + 2 = 19.
*/
class Solution {
  public:
    ii good(vi &nums, int k, int orders) {
        ll sum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > k) {
                int nxtorders = max(0, orders - (nums[i] - k));
                ll cnt = orders - nxtorders, start = nums[i] - cnt + 1,
                   end = nums[i];
                sum += (start + end) * cnt / 2;
                orders = nxtorders;
            }
            if (!(nums[i] > k) || orders == 0) break;
        }

        for (int i = 0; i < nums.size() && orders > 0 && nums[i] >= k; i++)
            orders--, sum += k;

        return {orders == 0, sum % MOD};
    }

    int maxProfit(vector<int> &nums, int orders) {
        sort(ALL(nums)), reverse(ALL(nums));

        ll lo = 0, hi = 1e9 + 1;
        int sum = 0;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            ii res = good(nums, mid, orders);
            if (res.fi) {
                lo = mid + 1;
                sum = res.se;
            } else {
                hi = mid;
            }
        }

        return sum % MOD;
    }
};
