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

class Solution {
public:
    // Input: nums = [2,4,0,9,6]
    // Output: [9,6,6,-1,-1]
    vector<int> secondGreaterElement(vector<int>& nums)
    {
        int n = nums.size();
        vi ans(n, -1);
        stack<int> s1, s2;
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            stack<int> tmp;
            while (!s2.empty() && nums[s2.top()] < a) {
                int b = s2.top();
                s2.pop();
                ans[b] = a;
            }

            while (!s1.empty() && nums[s1.top()] < a) {
                int b = s1.top();
                s1.pop();
                tmp.push(b);
            }

            while (!tmp.empty()) {
                s2.push(tmp.top());
                tmp.pop();
            }
            s1.push(i);
        }

        return ans;
    }
};

int main()
{
    vi nums = { 2, 4, 0, 9, 6 };
    Solution sol;
    vi ans = sol.secondGreaterElement(nums);
    for (auto& num : ans)
        cout << num << " ";
    cout << endl;
}
