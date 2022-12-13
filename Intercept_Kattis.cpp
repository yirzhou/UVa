#include <bits/stdc++.h>

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

int n, m, s, t;

vector<vector<ii>> G;
int dist[100005] = { INT_MAX };
vii parent;
int V[100005];

vi dfs_num, dfs_low, dfs_parent, ap_vertex;
vector<unordered_set<int>> AL;

int counter, dfs_root, root_children;

vi involved;

void ap(vector<unordered_set<int>>& AL, int u)
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
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

void find_ap(vector<unordered_set<int>>& AL)
{
    int V = AL.size();
    dfs_num.assign(V, UNVISITED);
    dfs_parent.assign(V, -1);
    dfs_low.assign(V, 0);
    ap_vertex.assign(V, 0);
    counter = 0;

    for (auto& u : involved) {
        if (dfs_num[u] == UNVISITED) {
            dfs_root = u;
            root_children = 0;
            ap(AL, u);
            ap_vertex[dfs_root] = (root_children > 1);
        }
    }
}

struct cmp {
    bool operator()(const ii& a, const ii& b)
    {
        return a.se > b.se;
    }
};

void sssp(int s, int t)
{
    memset(V, 0, sizeof V);
    fill(dist, dist + 100005, INT_MAX);
    parent.assign(n, vi());
    dist[s] = 0;
    priority_queue<ii, vector<ii>, cmp> q;
    q.push({ s, 0 });

    while (q.size()) {
        int u = q.top().fi, d = q.top().se;
        q.pop();
        if (V[u])
            continue;
        if (u == t)
            break;
        V[u] = 1;
        for (auto& [v, dd] : G[u]) {
            int nd = dd + d;
            if (nd < dist[v]) {
                dist[v] = nd;
                q.push({ v, nd });
                parent[v].clear();
                parent[v].pb(u);
            } else if (nd == dist[v])
                parent[v].pb(u);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dist[i] != INT_MAX)
            involved.pb(i);
    }
}

void trace(int u)
{
    if (parent[u].empty())
        return;
    for (auto& p : parent[u]) {
        if (AL[p].count(u))
            continue;
        AL[p].insert(u);
        trace(p);
    }
}

int main()
{
    fastio;

    cin >> n >> m;
    int u, v, w;
    G.assign(n, vector<ii>());
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        G[u].pb({ v, w });
    }
    cin >> s >> t;
    sssp(s, t);
    AL.assign(n, unordered_set<int>());
    for (auto& u : involved)
        trace(u);

    find_ap(AL);
    vi res;
    for (int i = 0; i < n; ++i) {
        if (ap_vertex[i])
            res.pb(i);
    }

    sort(ALL(res));

    cout << res[0];
    for (int i = 1; i < res.size(); ++i)
        cout << " " << res[i];
    cout << endl;

    return 0;
}