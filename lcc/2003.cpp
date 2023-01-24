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
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
class Solution {
public:
    int n;
    bool visited[100005] = { 0 };
    vi nums, res;
    vvi AL;

    void dfs(int u)
    {
        int num = nums[u];
        if (!visited[num]) {
            visited[num] = 1;
            for (auto& v : AL[u])
                dfs(v);
        }
    }

    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums)
    {
        n = parents.size();
        this->nums = nums;
        AL = vvi(n);
        for (int i = 1; i < n; ++i) {
            int p = parents[i];
            AL[p].pb(i);
        }

        res.assign(n, 1);

        int pos = find(ALL(nums), 1) - nums.begin(), minval = 1;

        for (; pos < n && pos != -1; pos = parents[pos]) {
            dfs(pos);
            while (visited[minval])
                minval++;
            res[pos] = minval;
        }

        return res;
    }
};

// void print(vi& A)
// {
//     for (auto& num : A)
//         cout << num << " ";
//     cout << endl;
// }

// int main()
// {
//     int t, n;
//     cin >> t;
//     while (t--) {
//         cin >> n;
//         vi parents(n, -1), nums(n, 0);
//         for (int i = 0; i < n; ++i)
//             cin >> parents[i];
//         for (int i = 0; i < n; ++i)
//             cin >> nums[i];

//         vi res = Solution().smallestMissingValueSubtree(parents, nums);
//         print(res);
//     }
// }

/*
There is a family tree rooted at 0 consisting of n nodes numbered 0 to n - 1. You are given a 0-indexed integer array parents, where parents[i] is the parent for node i. Since node 0 is the root, parents[0] == -1.

There are 10^5 genetic values, each represented by an integer in the inclusive range [1, 10^5]. You are given a 0-indexed integer array nums, where nums[i] is a distinct genetic value for node i.

Return an array ans of length n where ans[i] is the smallest genetic value that is missing from the subtree rooted at node i.

The subtree rooted at a node x contains node x and all of its descendant nodes.

2 <= n <= 10^5
*/
