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
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
#define precision(a) \
    cout << fixed;   \
    cout.precision(a)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vi> vii;

ii D[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

/*
You are given an array nums consisting of positive integers and an integer k.

Partition the array into two ordered groups such that each element is in exactly one group. A partition is called great if the sum of elements of each group is greater than or equal to k.

Return the number of distinct great partitions. Since the answer may be too large, return it modulo 109 + 7.

Two partitions are considered distinct if some element nums[i] is in different groups in the two partitions.

Input: nums = [1,2,3,4], k = 4
Output: 6
Explanation: The great partitions are: ([1,2,3], [4]), ([1,3], [2,4]), ([1,4], [2,3]), ([2,3], [1,4]), ([2,4], [1,3]) and ([4], [1,2,3]).

1 <= nums.length, k <= 1000
1 <= nums[i] <= 10e9
*/

template <typename T>
T modpow(T base, T exp, T M)
{
    base %= M;
    T result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % M;
        base = (base * base) % M;
        exp >>= 1;
    }
    return result;
}

ll memo[1005][1005];

class Solution {
public:
    const ll MOD = 1e9 + 7;
    ll sum = 0;
    int K;

    ll dp(int i, ll k, vi& nums)
    {
        if (k >= K)
            return 0;

        if (i == nums.size())
            return k < K;

        if (memo[i][k] != -1)
            return memo[i][k];

        ll ans = (dp(i + 1, k, nums) + dp(i + 1, k + nums[i], nums)) % MOD;
        return memo[i][k] = ans;
    }

    int countPartitions(vector<int>& nums, int k)
    {
        K = k;
        int n = nums.size();
        ll total = modpow<ll>(2, n, MOD);
        sort(ALL(nums));
        sum = 0;
        for (auto& num : nums)
            sum += num;
        if (sum < 2 * k || n == 1)
            return 0;

        memset(memo, -1, sizeof memo);

        ll ans = dp(0, 0, nums) % MOD;
        ans = ans * 2LL % MOD;

        ll res = (total - ans + MOD) % MOD;
        return res;
    }
};

int main()
{
    vi nums = { 790, 555, 729, 447, 538, 657, 258, 716, 645, 349, 148, 860, 425, 401, 282, 889, 309, 720, 228, 39, 366, 107, 765, 546, 791, 938, 154, 85, 845, 656 };

    int k = 558;

    Solution sol;
    int res = sol.countPartitions(nums, k);
    cout << res << endl;
}
