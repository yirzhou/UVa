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
    vi vals;
    vii AL;
    ll n, sum = 0;
    int maxval = 0;

    vll divisors;

    void get_factors(ll N)
    {
        for (ll i = 1; i <= sqrt(N); ++i) {
            if (N % i == 0) {
                if (i * i == N)
                    divisors.pb(i);
                else
                    divisors.pb(i), divisors.pb(N / i);
            }
        }
    }

    int bfs(int target, vii& edges)
    {
        vi nums = vals;
        vi seen(n, 0);

        vi degrees(n, 0);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            degrees[u]++, degrees[v]++;
        }
        queue<int> q;
        for (int u = 0; u < n; ++u) {
            if (degrees[u] == 1)
                q.push(u), seen[u] = 1;
        }
        int ans = 0;
        while (q.size() > 1) {
            int u = q.front();
            q.pop();
            int val = nums[u];
            if (val > target)
                return -1;
            seen[u] = 1;
            for (auto& v : AL[u]) {
                if (!seen[v]) {
                    degrees[v]--;
                    if (val == target)
                        ans++;
                    else
                        nums[v] += val;
                    if (degrees[v] == 1)
                        q.push(v);
                }
            }
        }
        return nums[q.front()] == target ? ans : -1;
    }

    int componentValue(vector<int>& nums, vector<vector<int>>& edges)
    {
        n = nums.size();
        if (n == 1)
            return 0;
        vals = nums;
        for (auto& val : nums)
            sum += val, maxval = max(maxval, val);

        AL = vii(n);
        get_factors(sum);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            AL[u].pb(v), AL[v].pb(u);
        }

        sort(ALL(divisors));
        int ans = INT_MAX;
        for (auto& div : divisors) {
            int res = bfs(div, edges);
            if (res != -1) {
                ans = res;
                break;
            }
        }

        return ans;
    }
};

/*
There is an undirected tree with n nodes labeled from 0 to n - 1.

You are given a 0-indexed integer array nums of length n where nums[i] represents the value of the ith node. You are also given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

You are allowed to delete some edges, splitting the tree into multiple connected components. Let the value of a component be the sum of all nums[i] for which node i is in the component.

Return the maximum number of edges you can delete, such that every connected component in the tree has the same value.

- 1 <= n <= 2 * 10^4
- nums.length == n
- 1 <= nums[i] <= 50
- edges.length == n - 1
- edges[i].length == 2
- 0 <= edges[i][0], edges[i][1] <= n - 1
- edges represents a valid tree.
*/

// int main()
// {

//     vi nums = { 6, 2, 2, 2, 6 };
//     vii edges = { { 0, 1 }, { 1, 2 }, { 1, 3 }, { 3, 4 } };

//     Solution sol;
//     cout << sol.componentValue(nums, edges) << endl;
// }
