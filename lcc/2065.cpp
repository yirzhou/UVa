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
    int n;
    vector<unordered_map<int, int>> AL;
    map<ii, int> cnt;
    vi vals;
    unordered_map<int, int> S;

    int ans = 0;

    void f(int u, int quality, int tleft)
    {
        if (tleft < 0)
            return;

        if (S.find(u) == S.end())
            quality += vals[u];
        if (u == 0)
            ans = max(ans, quality);
        S[u]++;

        for (auto& [v, cost] : AL[u]) {
            ii E = { u, v };
            if (cnt[E] == 1)
                cnt[E]--, f(v, quality, tleft - AL[u][v]), cnt[E]++;
        }
        S[u]--;
        if (S[u] == 0)
            S.erase(u);
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime)
    {
        n = values.size();
        vals = values;
        S.clear();
        AL.assign(n, unordered_map<int, int>());
        for (auto& e : edges) {
            int u = e[0], v = e[1], time = e[2];
            cnt[{ u, v }] = cnt[{ v, u }] = 1;
            AL[u][v] = AL[v][u] = time;
        }
        f(0, 0, maxTime);

        return ans;
    }
};

int main()
{
    int t, sz, edge_cnt, max_time;
    cin >> t;
    while (t--) {
        cin >> sz;
        vi values(sz);
        for (int i = 0; i < sz; ++i)
            cin >> values[i];

        cin >> edge_cnt;
        vii edges;
        int u, v, time;
        for (int i = 0; i < edge_cnt; ++i)
            cin >> u >> v >> time, edges.pb({ u, v, time });
        cin >> max_time;

        Solution sol;
        int ans = sol.maximalPathQuality(values, edges, max_time);
        cout << ans << endl;
    }
}

/*
There is an undirected graph with n nodes numbered from 0 to n - 1 (inclusive). You are given a 0-indexed integer array values where values[i] is the value of the ith node. You are also given a 0-indexed 2D integer array edges, where each edges[j] = [uj, vj, timej] indicates that there is an undirected edge between the nodes uj and vj, and it takes timej seconds to travel between the two nodes. Finally, you are given an integer maxTime.

A valid path in the graph is any path that starts at node 0, ends at node 0, and takes at most maxTime seconds to complete. You may visit the same node multiple times. The quality of a valid path is the sum of the values of the unique nodes visited in the path (each node's value is added at most once to the sum).

Return the maximum quality of a valid path.

Note: There are at most four edges connected to each node.
*/
