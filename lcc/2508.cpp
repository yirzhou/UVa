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

/*
There is an undirected graph consisting of n nodes numbered from 1 to n. You are given the integer n and a 2D array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi. The graph can be disconnected.

You can add at most two additional edges (possibly none) to this graph so that there are no repeated edges and no self-loops.

Return true if it is possible to make the degree of each node in the graph even, otherwise return false.

The degree of a node is the number of edges connected to it.

Input: n = 5, edges = [[1,2],[2,3],[3,4],[4,2],[1,4],[2,5]]
Output: true
Explanation: The above diagram shows a valid way of adding an edge.
Every node in the resulting graph is connected to an even number of edges.
*/

class Solution {
public:
    vi degree;
    vector<unordered_set<int>> AL;

    bool handle2(vi& cands)
    {
        if (!AL[cands[0]].count(cands[1]))
            return true;

        int n = degree.size() - 1;
        for (int u = 1; u <= n; ++u)
            if (u != cands[0] && u != cands[1] && !AL[u].count(cands[0]) && !AL[u].count(cands[1]))
                return true;

        return false;
    }

    bool isPossible(int n, vector<vector<int>>& edges)
    {
        degree = vi(n + 1, 0);
        AL = vector<unordered_set<int>>(n + 1);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            degree[u]++, degree[v]++;
            AL[u].insert(v), AL[v].insert(u);
        }

        vi cands;
        for (int u = 1; u <= n; ++u)
            if (degree[u] % 2 == 1)
                cands.pb(u);

        if (!cands.size())
            return true;
        if (cands.size() % 2 || cands.size() > 4)
            return false;

        if (cands.size() == 2)
            return handle2(cands);

        unordered_set<int> cset;
        for (auto& u : cands)
            cset.insert(u);

        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                int u = cands[i], v = cands[j];
                cset.erase(u), cset.erase(v);

                int a = -1, b = -1;
                for (auto& num : cset) {
                    if (a == -1)
                        a = num;
                    else if (b == -1)
                        b = num;
                }

                if (!AL[u].count(v) && !AL[a].count(b))
                    return true;
                cset.insert(u), cset.insert(v);
            }
        }
        return false;
    }
};
