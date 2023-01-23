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

/*
You are given an integer n denoting the number of nodes of a weighted directed graph. The nodes are numbered from 0 to n - 1.

You are also given a 2D integer array edges where edges[i] = [fromi, toi, weighti] denotes that there exists a directed edge from fromi to toi with weight weighti.

Lastly, you are given three distinct integers src1, src2, and dest denoting three distinct nodes of the graph.

Return the minimum weight of a subgraph of the graph such that it is possible to reach dest from both src1 and src2 via a set of edges of this subgraph. In case such a subgraph does not exist, return -1.

A subgraph is a graph whose vertices and edges are subsets of the original graph. The weight of a subgraph is the sum of weights of its constituent edges.

3 <= n <= 1e5
*/

class Solution {

public:
    vector<unordered_map<int, ll>> AL;
    vector<unordered_map<int, ll>> RAL;
    int n;

    vl dist1, dist2, rdist;

    struct info {
        int u;
        ll d;
    };

    struct cmp {
        bool operator()(const info& a, const info& b)
        {
            return a.d > b.d;
        }
    };

    ll sssp(vector<unordered_map<int, ll>>& AL, vl& dist, int s, int t)
    {
        dist.assign(n, LLONG_MAX);
        dist[s] = 0;

        priority_queue<info, vector<info>, cmp> pq;
        pq.push({ s, 0 });

        ll res = -1;

        while (pq.size()) {
            int u = pq.top().u;
            ll d = pq.top().d;
            pq.pop();
            if (u == t)
                res = d;

            for (auto& [v, dd] : AL[u]) {
                ll nxtd = d + dd;
                if (nxtd < dist[v]) {
                    dist[v] = nxtd;
                    pq.push({ v, nxtd });
                }
            }
        }

        return res;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest)
    {
        this->n = n;
        AL = vector<unordered_map<int, ll>>(n);
        RAL = vector<unordered_map<int, ll>>(n);

        for (int u = 0; u < n; ++u)
            AL[u][u] = RAL[u][u] = 0;

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            if (AL[u].count(v))
                AL[u][v] = min(AL[u][v], (ll)e[2]);
            else
                AL[u][v] = e[2];

            if (RAL[v].count(u))
                RAL[v][u] = min(RAL[v][u], (ll)e[2]);
            else
                RAL[v][u] = e[2];
        }

        ll a = sssp(AL, dist1, src1, dest), b = sssp(AL, dist2, src2, dest);
        if (a == -1 || b == -1)
            return -1;
        sssp(RAL, rdist, dest, src1);

        ll ans = a + b;

        for (int u = 0; u < n; ++u) {
            ll ud = dist1[u], vd = dist2[u];
            if (ud != LLONG_MAX && vd != LLONG_MAX && rdist[u] != LLONG_MAX)
                ans = min(ans, ud + vd + rdist[u]);
        }

        return ans;
    }
};

// int main()
// {
//     int t, n, e, src1, src2, dest;

//     cin >> t;
//     while (t--) {
//         cin >> n >> e;
//         vvi edges;
//         int u, v, d;
//         while (e--) {
//             cin >> u >> v >> d;
//             edges.pb({ u, v, d });
//         }
//         cin >> src1 >> src2 >> dest;
//         Solution sol;
//         cout << sol.minimumWeight(n, edges, src1, src2, dest) << endl;
//     }
// }
