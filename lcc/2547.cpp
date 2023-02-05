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
    int k;
    int mem1[1005][1005] = {0}, mem2[1005][1005] = {0};
    int dp(vector<int> &nums, int prev, int i) {
        if (prev == nums.size()) return 0;
        if (i + 1 == nums.size()) return k + mem1[prev][nums.size() - 1];
        if (mem2[prev][i] != -1) return mem2[prev][i];
        int ans = min(mem1[prev][i] + k + dp(nums, i + 1, i + 1),
                      dp(nums, prev, i + 1));
        return mem2[prev][i] = ans;
    }
    int minCost(vector<int> &nums, int K) {
        k = K;
        int n = nums.size();
        memset(mem1, 0, sizeof mem1);
        memset(mem2, -1, sizeof mem2);
        for (int i = 0; i < n; ++i) {
            int freq[1005] = {0};
            int len = 0;
            for (int j = i; j < n; ++j) {
                int num = nums[j];
                freq[num]++;
                if (freq[num] == 2) len += 2;
                else if (freq[num] - 1 >= 2) len++;
                mem1[i][j] = len;
            }
        }

        return dp(nums, 0, 0);
    }
};
