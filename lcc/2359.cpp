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
    vi G;
    int n;

    vi dist1, dist2;
    struct cmp {
        bool operator()(const ii &a, const ii &b) { return a.se > b.se; }
    };

    void f(vi &dist, int s) {
        dist.assign(n, INT_MAX);
        dist[s] = 0;

        priority_queue<ii, vector<ii>, cmp> pq;
        pq.push({s, 0});
        while (pq.size()) {
            int u = pq.top().fi, cost = pq.top().se;
            pq.pop();
            int v = G[u];
            if (v == -1)
                continue;
            if (cost + 1 < dist[v]) {
                dist[v] = cost + 1;
                pq.push({v, cost + 1});
            }
        }
    }

    int closestMeetingNode(vector<int> &edges, int node1, int node2) {
        n = edges.size();
        G = edges;

        f(dist1, node1), f(dist2, node2);

        int mdist = INT_MAX, res = -1;

        for (int u = 0; u < n; ++u) {
            int maxdist = max(dist1[u], dist2[u]);
            if (maxdist < mdist) {
                res = u, mdist = maxdist;
            }
        }

        return res;
    }
};
