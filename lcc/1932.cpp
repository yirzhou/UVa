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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    TreeNode *prev = NULL;
    bool valid(TreeNode *root) {
        prev = NULL;
        return traverse(root);
    }
    bool traverse(TreeNode *root) {
        if (!root) return 1;
        bool left = traverse(root->left);
        if (prev && prev->val >= root->val) return 0;
        prev = root;
        bool right = traverse(root->right);
        return left & right;
    }

    unordered_map<int, int> cnt;
    unordered_map<int, TreeNode *> roots, leaves;
    unordered_set<int> unique;

    void connect(TreeNode *p, int val) {
        TreeNode *child = roots[val];
        if (p->left && p->left->val == val) p->left = child;
        else if (p->right && p->right->val == val) p->right = child;
        roots.erase(val);
    }

    int count(TreeNode *root) {
        if (!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }

    TreeNode *canMerge(vector<TreeNode *> &trees) {
        for (auto &t : trees) {
            if (t->left)
                cnt[t->left->val]++, leaves[t->left->val] = t,
                                     unique.insert(t->left->val);
            if (t->right)
                cnt[t->right->val]++, leaves[t->right->val] = t,
                                      unique.insert(t->right->val);
            roots[t->val] = t, unique.insert(t->val);
        }

        for (auto &[val, f] : cnt)
            if (f > 1) return NULL;

        for (auto &[val, p] : leaves)
            if (roots.count(val)) connect(p, val);

        if (roots.size() != 1) return NULL;
        TreeNode *root;
        for (auto &[val, r] : roots) root = r;
        return valid(root) && count(root) == unique.size() ? root : NULL;
    }
};

/*
You are given n BST (binary search tree) root nodes for n separate BSTs stored
in an array trees (0-indexed). Each BST in trees has at most 3 nodes, and no two
roots have the same value. In one operation, you can:

Select two distinct indices i and j such that the value stored at one of the
leaves of trees[i] is equal to the root value of trees[j]. Replace the leaf node
in trees[i] with trees[j]. Remove trees[j] from trees. Return the root of the
resulting BST if it is possible to form a valid BST after performing n - 1
operations, or null if it is impossible to create a valid BST.

A BST (binary search tree) is a binary tree where each node satisfies the
following property:

Every node in the node's left subtree has a value strictly less than the node's
value. Every node in the node's right subtree has a value strictly greater than
the node's value. A leaf is a node that has no children.

- n == trees.length
- 1 <= n <= 5 * 10^4
- The number of nodes in each tree is in the range [1, 3].
- Each node in the input may have children but no grandchildren.
- No two roots of trees have the same value.
- All the trees in the input are valid BSTs.
- 1 <= TreeNode.val <= 5 * 10^4.
*/
