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

class Solution {
  public:
    /*
    - 1 <= paths.length <= 2 * 10^4
    - 1 <= paths[i].length <= 500
    - 1 <= paths[i][j].length <= 10
    - 1 <= sum(paths[i][j].length) <= 2 * 10^5
    */

    struct Node {
        unordered_map<string, Node *> children;
        bool is_path = 0, todel = 0;
        string repr;

        Node(string s) : repr(s) {}
    };

    Node *root;
    vector<vector<string>> ans;
    unordered_map<string, Node *> encodings;

    void insert(vector<string> &path) {
        Node *node = root;
        for (auto &dir : path) {
            if (!node->children.count(dir))
                node->children[dir] = new Node(dir);
            node = node->children[dir];
        }
        node->is_path = 1;
    }

    void preproc(vector<vector<string>> &paths) {
        root = new Node("/");
        for (auto &path : paths)
            insert(path);
    }

    string dfs(Node *node) {
        string H;
        vector<string> tuples;
        for (auto &[s, child] : node->children)
            tuples.pb(dfs(child));

        sort(ALL(tuples));
        for (auto &c : tuples)
            H += c;

        if (H.size()) {
            if (encodings.count(H)) {
                encodings[H]->todel = node->todel = 1;
            } else {
                encodings[H] = node;
            }
        }

        H = node->repr + H;
        return "(" + H + ")";
    }

    void bt(Node *node, vector<string> &path) {
        if (node->todel)
            return;
        path.pb(node->repr);
        ans.pb(path);
        for (auto &[s, child] : node->children)
            bt(child, path);
        path.pop_back();
    }

    vector<vector<string>>
    deleteDuplicateFolder(vector<vector<string>> &paths) {
        preproc(paths);
        for (auto &[s, node] : root->children)
            dfs(node);
        vector<string> path;
        for (auto &[s, node] : root->children)
            path.clear(), bt(node, path);

        return ans;
    }
};
