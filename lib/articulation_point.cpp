#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second
#define UNVISITED -1

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

// Need adjacency list
vi dfs_num, dfs_low, dfs_parent, ap_vertex;
vector<vi> AL;

int counter, dfs_root, root_children;

void ap(vector<vi>& AL, int u)
{
    dfs_num[u] = counter++;
    dfs_low[u] = dfs_num[u];
    for (auto& v : AL[u]) {
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            if (u == dfs_root)
                ++root_children;
            ap(AL, v);
            if (dfs_low[v] >= dfs_num[u])
                ap_vertex[u] = 1;
            if (dfs_low[v] > dfs_num[u]) {
                // Bridge
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

void find_ap(vector<vi>& AL)
{
    int V = AL.size();
    dfs_num.assign(V, UNVISITED);
    dfs_parent.assign(V, -1);
    dfs_low.assign(V, 0);
    ap_vertex.assign(V, 0);
    counter = 0;

    for (int u = 0; u < V; ++u) {
        if (dfs_num[u] == UNVISITED) {
            dfs_root = u;
            root_children = 0;
            ap(AL, u);
            ap_vertex[dfs_root] = (root_children > 1);
        }
    }
}