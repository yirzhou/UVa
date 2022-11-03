#include <bits/stdc++.h>

using namespace std;
#define MAXN 105

int res, target;
typedef vector<int> vi;

vector<vi> E, G;
vector<vi> D;
int visited[MAXN];

struct DSU {
    vi parent;
    DSU(int n)
    {
        parent = vi(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x)
    {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }

    void connect(int x, int y)
    {
        int rootx = find(x), rooty = find(y);
        if (rootx == rooty)
            return;
        parent[rooty] = rootx;
    }
};

void f(int u, vi& path)
{
    if (u == target) {
        for (auto& p : path)
            res = max(res, p);
        return;
    }
    if (visited[u])
        return;
    visited[u] = 1;

    for (auto& v : G[u]) {
        path.push_back(D[u][v]);
        f(v, path);
        path.pop_back();
    }
}

int main()
{
    int C, S, Q;
    int c = 0;
    while (scanf("%d%d%d", &C, &S, &Q) && (C || S || Q)) {
        if (c > 0)
            printf("\n");
        G = vector<vi>(C + 1);
        E = vector<vi>(S);
        D = vector<vi>(C + 1, vi(C + 1, INT_MAX));
        int c1, c2, d;
        for (int i = 0; i < S; ++i) {
            scanf("%d%d%d", &c1, &c2, &d);

            E[i] = { c1, c2, d };
        }
        sort(E.begin(), E.end(),
            [](const vi& a, const vi& b) {
                return a[2] < b[2];
            });
        DSU uf(C + 1);
        int u, v;
        for (auto& e : E) {
            u = e[0], v = e[1], d = e[2];
            if (!uf.connected(u, v)) {
                uf.connect(u, v);
                G[u].push_back(v);
                G[v].push_back(u);
                D[u][v] = D[v][u] = d;
            }
        }

        printf("Case #%d\n", ++c);
        while (Q--) {
            res = 0;
            memset(visited, 0, sizeof(visited));
            scanf("%d%d", &c1, &c2);
            target = c2;
            vi path;
            f(c1, path);

            if (res == 0)
                printf("no path\n");
            else
                printf("%d\n", res);
        }
    }
}
