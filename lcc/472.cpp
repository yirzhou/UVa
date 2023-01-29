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

    struct Node {
        Node *children[26] = {nullptr};
        bool is = false;
        Node() {}
    };

    Node *root;

    unordered_map<string, bool> dp;

    void insert(string &s) {
        Node *node = root;
        for (auto &c : s) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new Node();
            node = node->children[idx];
        }

        node->is = true;
    }

    bool exist(string &s, int lo, int hi) {
        Node *node = root;
        for (int i = lo; i <= hi; ++i) {
            int idx = s[i] - 'a';
            if (!node->children[idx])
                return false;
            node = node->children[idx];
        }
        return node->is;
    }

  public:
    unordered_set<string> mp;

    bool dfs(string &w) {
        if (dp.count(w))
            return dp[w];

        for (int i = 1; i < w.size(); ++i) {
            string pre = w.substr(0, i), suf = w.substr(i);
            if ((mp.count(pre) && mp.count(suf)) ||
                (mp.count(pre) && dfs(suf)) || (mp.count(suf) && dfs(pre))) {
                return dp[w] = true;
            }
        }

        return dp[w] = false;
    }

    bool f(string &w, int i, int k) {
        if (i == w.size())
            return k > 1;
        if (dp.count(w))
            return dp[w];
        for (int j = i; j < w.size(); ++j) {
            if (exist(w, i, j) && f(w, j + 1, k + 1)) {
                dp[w.substr(i)] = true;
                return true;
            }
        }

        return dp[w.substr(i)] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {

        root = new Node();
        for (auto &w : words)
            mp.insert(w);

        vector<string> res;
        for (auto &w : words) {
            if (dfs(w))
                res.pb(w);
        }

        return res;
    }
};

// int main() {

//     vector<string> words = {"cat", "cats",        "catsdogcats",
//                             "dog", "dogcatsdog",  "hippopotamuses",
//                             "rat", "ratcatdogcat"};

//     for (auto &w : Solution().findAllConcatenatedWordsInADict(words))
//         cout << w << endl;
// }
