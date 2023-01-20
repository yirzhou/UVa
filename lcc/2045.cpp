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
A city is represented as a bi-directional connected graph with n vertices where each vertex is labeled from 1 to n (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself. The time taken to traverse any edge is time minutes.

Each vertex has a traffic signal which changes its color from green to red and vice versa every change minutes. All signals change at the same time. You can enter a vertex at any time, but can leave a vertex only when the signal is green. You cannot wait at a vertex if the signal is green.

The second minimum value is defined as the smallest value strictly larger than the minimum value.

For example the second minimum value of [2, 3, 4] is 3, and the second minimum value of [2, 2, 4] is 4.
Given n, edges, time, and change, return the second minimum time it will take to go from vertex 1 to vertex n.

Notes:

You can go through any vertex any number of times, including 1 and n.
You can assume that when the journey starts, all signals have just turned green.

Input: n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
Output: 13
*/

class Solution {
public:
    vii AL;
    int N;

    vi dist;
    int T, C;

    struct cmp {
        bool operator()(const ii& a, const ii& b)
        {
            return a.se > b.se;
        }
    };

    int dijkstra1()
    {
        dist = vi(N + 1, INT_MAX);
        dist[1] = 0;

        priority_queue<ii, vector<ii>, cmp> pq;
        pq.push({ 1, 0 });

        while (pq.size()) {
            int u = pq.top().fi, time = pq.top().se;
            pq.pop();
            int green = (time / C) % 2 == 0;
            if (!green)
                time += (C - time % C);
            for (auto& v : AL[u]) {
                int nxt_time = time + T;
                if (nxt_time < dist[v]) {
                    dist[v] = nxt_time;
                    pq.push({ v, nxt_time });
                }
            }
        }

        return dist[N];
    }

    struct node {
        int u, vtime = 0, time;
    };

    struct cmp2 {
        bool operator()(const node& a, const node& b) { return a.time > b.time; }
    };

    int dijkstra2()
    {
        // {visit time, cost}

        vii cost(N + 1, vi(2, INT_MAX));
        cost[1][0] = 0;
        priority_queue<node, vector<node>, cmp2> pq;
        pq.push({ 1, 0, 0 });
        while (pq.size()) {
            int u = pq.top().u, time = pq.top().time, vtime = pq.top().vtime;
            pq.pop();
            if (u == N && vtime == 1)
                return time;

            if (vtime > 1)
                continue;

            int green = (time / C) % 2 == 0;
            if (!green)
                time += (C - time % C);

            for (auto& v : AL[u]) {
                int nxt_time = time + T;
                if (nxt_time < cost[v][vtime]) {
                    cost[v][vtime] = nxt_time;
                    pq.push({ v, vtime, nxt_time });
                } else if (vtime == 0 && nxt_time > cost[v][vtime]) {
                    cost[v][1] = nxt_time;
                    pq.push({ v, 1, nxt_time });
                }
            }
        }
        return -1;
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change)
    {
        N = n, T = time, C = change;
        AL.assign(n + 1, vi());
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            AL[u].pb(v), AL[v].pb(u);
        }

        int ans = dijkstra2();
        return ans;
    }
};

// int main()
// {
//     int t, n, E, time, change;
//     cin >> t;
//     while (t--) {
//         cin >> n;
//         cin >> E;
//         vii edges;
//         int u, v;
//         while (E--) {
//             cin >> u >> v;
//             edges.pb({ u, v });
//         }

//         cin >> time >> change;
//         Solution sol;
//         cout << sol.secondMinimum(n, edges, time, change) << endl;
//     }
// }
