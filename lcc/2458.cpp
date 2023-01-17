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

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr) {}
            * TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

/*
You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.

You have to perform m independent queries on the tree where in the ith query you do the following:

Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root.
Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.

Note:

The queries are independent, so the tree returns to its initial state after each query.
The height of a tree is the number of edges in the longest simple path from the root to some node in the tree.
*/

class Solution {
public:
    unordered_map<int, ii> G, H;
    unordered_map<int, int> dist_to_leaf, ans;

    int dfs2(TreeNode* root, int d)
    {
        if (!root)
            return -1;
        int ans = max(root->left ? 1 + dfs2(root->left, d + 1) : 0, root->right ? 1 + dfs2(root->right, d + 1) : 0);
        dist_to_leaf[root->val] = ans;
        return ans;
    }

    void solve(TreeNode* root)
    {
        deque<pair<TreeNode*, int>> q;
        q.push_back({ root, 0 });
        map<int, int> S;
        while (q.size()) {
            S.clear();
            for (auto& [node, dist] : q) {
                int val = node->val;
                S[dist + dist_to_leaf[val]]++;
            }

            for (auto& [node, dist] : q) {
                int val = node->val, h = dist + dist_to_leaf[val];
                S[h]--;
                if (!S[h])
                    S.erase(h);
                if (!S.size())
                    ans[val] = max(0, dist - 1);
                else
                    ans[val] = prev(S.end())->first;
                S[h]++;
            }

            int len = q.size();
            while (len--) {
                TreeNode* node = q.front().fi;
                int dist = q.front().se;
                q.pop_front();
                if (node->left)
                    q.pb({ node->left, dist + 1 });
                if (node->right)
                    q.pb({ node->right, dist + 1 });
            }
        }
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries)
    {
        int h = max(dfs2(root->left, 1), dfs2(root->right, 1));
        dist_to_leaf[root->val] = h + 1;

        solve(root);
        int m = queries.size();
        vi res(m);
        for (int i = 0; i < m; ++i)
            res[i] = ans[queries[i]];

        return res;
    }
};
