#include <bits/stdc++.h>

using namespace std;

#define MAX 100000
#define UNVISITED 1000000

typedef pair<int, int> ii;

vector<ii> res;

int n, m;
vector<vector<int>> G;
int cnt = 0, N, dfs_root, root_children;
vector<int> dfs_num, dfs_low, dfs_parent;
int ap[MAX];
int visited[MAX];

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

            if (dfs_low[v] >= dfs_num[u]) {
                ap[u] = 1;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
}

void dfs(int u, int removed)
{
    if (u == removed || visited[u])
        return;

    visited[u] = 1;
    for (auto& v : G[u])
        dfs(v, removed);
}

int g(int removed)
{
    int res = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; ++i) {
        if (!(i == removed || visited[i])) {
            dfs(i, removed);
            res++;
        }
    }

    return res;
}

int main()
{

    while (scanf("%d %d", &n, &m) && (n || m)) {
        G = vector<vector<int>>(n);
        cnt = 0;
        dfs_num.assign(n, UNVISITED);
        dfs_low.assign(n, 0);
        dfs_parent.assign(n, 0);
        memset(ap, 0, sizeof(ap));
        res.clear();

        int x, y;
        while (scanf("%d %d", &x, &y) && (x != -1 || y != -1)) {
            G[x].push_back(y);
            G[y].push_back(x);
        }

        for (int i = 0; i < n; ++i) {
            if (dfs_num[i] == UNVISITED) {
                dfs_root = i, root_children = 0, f(i);
                ap[dfs_root] = (root_children > 1);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (ap[i]) {
                int comps = g(i);
                res.push_back({ i, comps });
            }
        }

        sort(res.begin(), res.end(),
            [](const ii& a, const ii& b) {
                if (a.second == b.second)
                    return a.first < b.first;
                return a.second > b.second;
            });

        for (int i = 0; i < min(m, (int)res.size()); ++i) {
            printf("%d %d\n", res[i].first, res[i].second);
        }

        int j = res.size();

        for (int i = 0; i < n && j < m; ++i) {
            if (!ap[i]) {
                j++;
                printf("%d %d\n", i, 1);
            }
        }

        printf("\n");
    }
}
