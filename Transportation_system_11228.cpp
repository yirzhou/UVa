#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

typedef pair<int, int> ii;
typedef vector<int> vi;

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

struct edge {
    int u, v;
    double d;
};

int t, n, r;
vector<ii> P;
vector<edge> E;

int main()
{
    scanf("%d", &t);
    for (int c = 1; c <= t; ++c) {
        scanf("%d%d", &n, &r);
        P.clear();
        E.clear();
        DSU uf(n);
        int x, y;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &x, &y);
            P.push_back({ x, y });
        }

        for (int u = 0; u < n; ++u) {
            for (int v = u + 1; v < n; ++v) {
                int x1 = P[u].first, y1 = P[u].second, x2 = P[v].first, y2 = P[v].second;
                int dx = abs(x1 - x2), dy = abs(y1 - y2);
                E.push_back({ u, v, sqrt(dx * dx + dy * dy) });
            }
        }

        sort(E.begin(), E.end(), [](const edge& a, const edge& b) {
            return a.d < b.d;
        });

        int states = 1;
        double road = 0.0, rail = 0.0;
        for (auto& e : E) {
            int u = e.u, v = e.v;
            double d = e.d;

            if (!uf.connected(u, v)) {
                if (d > r) {
                    states++;
                    rail += d;
                } else {
                    road += d;
                }
                uf.connect(u, v);
            }
        }

        printf("Case #%d: %d %d %d\n", c, states, (int)round(road), (int)round(rail));
    }
}
