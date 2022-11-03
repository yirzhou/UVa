#include <bits/stdc++.h>

using namespace std;

#define MAXN 2005

typedef vector<int> vi;

vector<vi> G;
vi dfn, low;
set<int> S;
int dep, cnt;
void dfs(int u)
{
    low[u] = dfn[u] = ++dep;
    S.emplace(u);
    for (auto& v : G[u]) {
        if (!dfn[v])
            dfs(v), low[u] = min(low[u], low[v]);
        else if (S.count(v))
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
        S.clear(), ++cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    while (cin >> N >> M, N && M) {
        G.assign(N + 1, vi());
        low.assign(N + 1, 0);
        dfn.assign(N + 1, 0);
        S.clear();
        dep = cnt = 0;
        int V, W, P;
        while (M--) {
            cin >> V >> W >> P;
            G[V].emplace_back(W);
            if (P == 2)
                G[W].emplace_back(V);
        }
        for (int u = 1; u <= N; ++u)
            if (!dfn[u] && cnt < 2)
                dfs(u);
        cout << (cnt == 1) << "\n";
    }
    return 0;
}
