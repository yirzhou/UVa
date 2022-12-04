#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
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

ii D[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

class Solution {
public:
    vector<unordered_set<int>> G;
    vector<vll> AL;
    unordered_set<int> g;
    vi vis;
    int N;

    void group(int start)
    {
        queue<int> q;
        q.push(start);
        g.clear();

        while (q.size()) {
            int u = q.front();
            q.pop();
            if (vis[u])
                continue;
            vis[u] = 1;
            g.insert(u);

            for (auto& v : G[u]) {
                if (!vis[v])
                    q.push(v);
            }
        }
    }

    bool check(int start)
    {
        g.clear();
        queue<ii> q;

        vi C(N + 1, 0);
        C[start] = 0;
        q.push({ start, 0 });
        while (q.size()) {
            int u = q.front().fi, c = q.front().se;
            g.insert(u);
            for (auto& v : G[u]) {
                if (C[v] && C[v] == c)
                    return false;
                C[v] = 1 - c;
                q.push({ v, 1 - c });
            }
        }
        return true;
    }

    ll fm()
    {
        for (auto& k : g) {
            for (auto& i : g) {
                for (auto& j : g) {
                    AL[i][j] = min(AL[i][j], AL[i][k] + AL[k][j]);
                }
            }
        }

        ll res = 0;
        for (auto& u : g) {
            for (auto& v : g) {
                if (AL[u][v] < INF)
                    res = max(res, AL[u][v]);
            }
        }

        return res;
    }

    ll solve()
    {
        ll res = 0;
        for (int u = 1; u < N; ++u) {
            if (!vis[u]) {
                if (!check(u))
                    return -1;
                for (auto& u : g)
                    vis[u] = 1;
                res += (1 + fm());
            }
        }

        return res;
    }

    int magnificentSets(int n, vector<vector<int>>& edges)
    {
        N = n + 1;
        G.assign(n + 1, unordered_set<int>());
        AL.assign(n + 1, vll(n + 1, INF));
        vis.assign(n + 1, 0);
        int u, v;
        for (int u = 1; u < N; ++u)
            AL[u][u] = 0;

        for (auto& e : edges) {
            u = e[0], v = e[1];
            G[u].insert(v), G[v].insert(u);
            AL[u][v] = AL[v][u] = 1;
        }

        return solve();
    }
};