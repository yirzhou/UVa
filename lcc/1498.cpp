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

template <typename T> T modpow(T base, T exp, T M) {
    base %= M;
    T result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % M;
        base = (base * base) % M;
        exp >>= 1;
    }
    return result;
}

/*
Constraints:
- 1 <= nums.length <= 10^5
- 1 <= nums[i] <= 10^6
- 1 <= target <= 10^6
*/
class Solution {
  public:
    int numSubseq(vector<int> &nums, int target) {
        sort(ALL(nums));
        int n = nums.size();
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            if (2 * num <= target) { ans = (ans + 1) % MOD; }
            auto it =
                upper_bound(nums.begin() + i + 1, nums.end(), target - num) -
                nums.begin() - 1;
            ll cnt = it - i;
            ans = (ans + modpow<ll>(2, cnt, MOD) - 1) % MOD;
        }

        return ans;
    }
};
