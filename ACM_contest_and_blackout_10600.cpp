#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
vector<vi> E;

struct DSU {
    vi parent;
    int cnt;
    DSU(int n)
    {
        parent = vi(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
        cnt = n;
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
        cnt--;
    }
};

int main()
{
    int T, N, M, A, B, C;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        E = vector<vi>(M);
        DSU uf(N + 1);

        for (int i = 0; i < M; ++i) {
            scanf("%d%d%d", &A, &B, &C);
            E[i] = { A, B, C };
        }

        vector<int> MST;

        sort(E.begin(), E.end(), [](const vi& a, const vi& b) { return a[2] < b[2]; });

        int u, v, d;
        int cheapest = 0, second_cheapest = INT_MAX;
        for (int i = 0; i < M; ++i) {
            u = E[i][0], v = E[i][1], d = E[i][2];
            if (!uf.connected(u, v)) {
                uf.connect(u, v);
                MST.push_back(i);
                cheapest += d;
            }
        }

        for (auto& i : MST) {
            DSU dsu(N + 1);
            int cost = 0;
            for (int j = 0; j < M; ++j) {
                u = E[j][0], v = E[j][1], d = E[j][2];
                if (j != i && !dsu.connected(u, v)) {
                    cost += d;
                    dsu.connect(u, v);
                }
            }
            if (dsu.cnt == 2) {
                second_cheapest = min(second_cheapest, cost);
            }
        }
        printf("%d %d\n", cheapest, second_cheapest);
    }
}
