#include <bits/stdc++.h>

using namespace std;

#define MAXN 50000

int T, N;
int G[MAXN + 1];
int V[MAXN + 1];
int seen[MAXN + 1];

int dfs(int v)
{
    if (V[v] > 0) {
        return V[v];
    }
    if (seen[v]) {
        int size = 1, node = v;
        while (G[node] != v) {
            node = G[node];
            size++;
        }
        node = v;
        for (; G[node] != v; node = G[node]) {
            V[node] = size;
        }
        return 0;
    }
    seen[v] = 1;
    int cnt = 1 + dfs(G[v]);
    if (V[v] == 0) {
        V[v] = cnt;
    }
    return V[v];
}

int main()
{
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        memset(G, 0, sizeof(G));
        memset(V, 0, sizeof(V));
        memset(seen, 0, sizeof(seen));
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u] = v;
        }
        int maxc = 0, minv = MAXN;
        for (int v = 1; v <= N; ++v) {
            if (!G[v])
                continue;
            if (V[v])
                continue;
            int cnt = dfs(v);
            if (cnt > maxc) {
                maxc = cnt;
                minv = v;
            }
        }

        printf("Case %d: %d\n", t, minv);
    }
}
