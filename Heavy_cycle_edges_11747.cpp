#include <bits/stdc++.h>

using namespace std;

int n, m;
typedef vector<int> vi;

vector<vi> E;

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

int main()
{
    while (scanf("%d%d", &n, &m) && (n || m)) {
        E = vector<vi>(m);
        DSU uf(n);
        int u, v, w;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            E[i] = { u, v, w };
        }

        sort(E.begin(), E.end(),
            [](const vi& a, const vi& b) {
                return a[2] < b[2];
            });

        vi he;
        for (auto& e : E) {
            u = e[0], v = e[1], w = e[2];
            if (!uf.connected(u, v)) {
                uf.connect(u, v);
            } else {
                he.push_back(w);
            }
        }

        if (he.empty())
            printf("forest\n");
        else {
            for (int i = 0; i < he.size(); ++i)
                printf(i == he.size() - 1 ? "%d\n" : "%d ", he[i]);
        }
    }
}
