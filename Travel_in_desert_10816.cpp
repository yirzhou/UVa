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

ii D[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

int n, e, s, t;
typedef pair<double, double> dd;

struct info {
    dd dist;
    int u;
};

struct cmp {
    bool operator()(info& a, info& b)
    {
        return a.dist.fi > b.dist.fi;
    }
};

struct cmp2 {
    bool operator()(info& a, info& b)
    {
        return a.dist.se > b.dist.se;
    }
};

// Find min max temp.
double f1(int s, int t, vector<vector<pair<int, dd>>>& dist)
{
    priority_queue<info, vector<info>, cmp> pq;
    vector<double> costs(n + 1, (double)INT_MAX);
    costs[s] = 0.0;
    pq.push({ { 0.0, 0.0 }, s });

    vi parent(n + 1);
    parent[s] = 0;
    while (pq.size()) {
        info cur = pq.top();
        int u = cur.u;
        dd cost = cur.dist;
        pq.pop();
        if (u == t)
            break;

        for (auto& [v, c] : dist[u]) {
            double maxr = max(cost.fi, c.fi);
            if (maxr < costs[v]) {
                costs[v] = maxr;
                parent[v] = u;
                pq.push({ { maxr, 0 }, v });
            }
        }
    }

    return costs[t];
}

// Find min dist.
double f(int s, int t, vector<vector<pair<int, dd>>>& dist)
{
    priority_queue<info, vector<info>, cmp2> pq;
    vector<double> costs(n + 1, (double)INT_MAX);
    costs[s] = 0.0;
    pq.push({ { 0.0, 0.0 }, s });

    vi parent(n + 1);
    parent[s] = 0;
    while (pq.size()) {
        info cur = pq.top();
        int u = cur.u;
        dd cost = cur.dist;
        pq.pop();
        if (u == t)
            break;

        for (auto& [v, c] : dist[u]) {
            double nd = cost.se + c.se;
            if (nd < costs[v]) {
                costs[v] = nd;
                parent[v] = u;
                pq.push({ { 0, nd }, v });
            }
        }
    }

    int u = t;
    vi path;
    while (u != 0)
        path.pb(u), u = parent[u];
    reverse(ALL(path));
    for (int i = 0; i < path.size() - 1; ++i)
        cout << path[i] << " ";
    cout << path.back() << endl;

    return costs[t];
}

int main()
{
    fastio;
    precision(1);
    while (cin >> n >> e) {
        cin >> s >> t;
        vector<vector<pair<int, dd>>> dist1(n + 1);
        vector<vector<pair<int, dd>>> dist2(n + 1);
        vector<vector<double>> edges;
        int x, y;
        double r, d;
        for (int i = 0; i < e; ++i) {
            cin >> x >> y >> r >> d;
            dist1[x].pb({ y, { r * 10, d * 10 } });
            dist1[y].pb({ x, { r * 10, d * 10 } });
            edges.pb({ (double)x, (double)y, r * 10, d * 10 });
        }
        double maxr = f1(s, t, dist1);

        for (auto& e : edges) {
            int x = e[0], y = e[1], r = e[2], d = e[3];
            if (e[2] > maxr)
                continue;

            dist2[x].pb({ y, { r, d } });
            dist2[y].pb({ x, { r, d } });
        }

        double mind = f(s, t, dist2);
        cout << mind / 10.0 << " " << maxr / 10.0 << endl;
    }

    return 0;
}
