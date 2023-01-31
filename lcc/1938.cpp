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

/*
here is a rooted tree consisting of n nodes numbered 0 to n - 1. Each node's
number denotes its unique genetic value (i.e. the genetic value of node x is x).
The genetic difference between two genetic values is defined as the bitwise-XOR
of their values. You are given the integer array parents, where parents[i] is
the parent for node i. If node x is the root of the tree, then parents[x] == -1.

You are also given the array queries where queries[i] = [nodei, vali]. For each
query i, find the maximum genetic difference between vali and pi, where pi is
the genetic value of any node that is on the path between nodei and the root
(including nodei and the root). More formally, you want to maximize vali XOR pi.

Return an array ans where ans[i] is the answer to the ith query.
*/

class Solution {
  public:
    const int SZ = 18;
    unordered_map<int, vector<ii>> Q;
    vvi AL;
    vi ans;
    struct Node {
        int bit;
        Node *children[2] = {NULL};
        Node(int i) : bit(i) {}
    };

    Node *troot;

    void insert(int num) {
        Node *node = troot;
        for (int i = SZ; i >= 0; --i) {
            int b = (num >> i) & 1;
            if (node->children[b] == NULL)
                node->children[b] = new Node(b);
            node = node->children[b];
        }
    }

    bool leaf(Node *u) { return !u->children[0] && !u->children[1]; }

    int find(int num) {
        Node *node = troot;
        int other = 0;
        for (int i = SZ; i >= 0; --i) {
            int b = (num >> i) & 1;
            if (node->children[!b]) {
                other |= ((!b) << i);
                node = node->children[!b];
            } else {
                if (node->children[0])
                    node = node->children[0];
                else
                    other |= (1 << i), node = node->children[1];
            }
        }
        return num ^ other;
    }

    Node *search(int num) {
        Node *node = troot;
        for (int i = SZ; i >= 0; --i) {
            int b = ((num >> i) & 1);
            if (!node->children[b])
                return NULL;
            node = node->children[b];
        }
        return node;
    }

    Node *traverse(Node *root, int val, int i) {

        piii(val, i, root->bit);
        if (i == -1) {
            return root;
        }
        int b = ((val >> i) & 1);

        return traverse(root->children[b], val, i - 1);
    }

    Node *remove(Node *root, int val, int i) {

        if (i == -1) {
            delete root;
            root = NULL;
            return root;
        }

        int b = ((val >> i) & 1);

        root->children[b] = remove(root->children[b], val, i - 1);

        if (leaf(root)) {
            delete root;
            root = NULL;
        }
        return root;
    }

    void dfs(int u) {
        insert(u);
        for (auto &[i, val] : Q[u])
            ans[i] = find(val);
        for (auto &v : AL[u])
            dfs(v);
        troot = remove(troot, u, SZ);
    }

    vector<int> maxGeneticDifference(vector<int> &parents,
                                     vector<vector<int>> &queries) {
        ans = vi(queries.size());

        for (int i = 0; i < queries.size(); ++i) {
            int node = queries[i][0], val = queries[i][1];
            Q[node].pb({i, val});
        }
        troot = new Node(0);
        AL = vvi(parents.size());
        int rootval;
        for (int u = 0; u < parents.size(); ++u) {
            if (parents[u] == -1)
                rootval = u;
            else
                AL[parents[u]].pb(u);
        }

        dfs(rootval);

        return ans;
    }
};
