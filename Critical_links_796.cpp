#include <bits/stdc++.h>

using namespace std;

#define UNVISITED 1000000

int cnt = 0, N, dfs_root, root_children;
vector<int> dfs_num, dfs_low, dfs_parent;
vector<vector<int>> G;

vector<vector<int>> res;

void f(int u)
{
    dfs_low[u] = dfs_num[u] = cnt++;
    for (int j = 0; j < G[u].size(); ++j) {
        int v = G[u][j];
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            if (u == dfs_root)
                root_children++;
            f(v);

            if (dfs_low[v] > dfs_num[u]) {
                res.push_back({ v, u });
                sort(res.back().begin(), res.back().end());
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);

        } else if (v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
}

int main()
{
    while (scanf("%d", &N) != EOF) {
        G = vector<vector<int>>(N);

        for (int n = 0; n < N; ++n) {
            int u, c, v;
            scanf("%d (%d) ", &u, &c);
            while (c--) {
                scanf("%d", &v);
                G[u].push_back(v);
            }
        }

        cnt = 0;
        dfs_num.assign(N, UNVISITED);
        dfs_low.assign(N, 0);
        dfs_parent.assign(N, 0);
        res.clear();

        for (int i = 0; i < N; ++i) {
            if (dfs_num[i] == UNVISITED) {
                dfs_root = i;
                root_children = 0;
                f(i);
            }
        }

        printf("%ld critical links\n", res.size());
        sort(res.begin(), res.end());
        for (auto& link : res) {
            printf("%d - %d\n", link[0], link[1]);
        }
        printf("\n");
        scanf("\n");
    }
}
