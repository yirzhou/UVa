#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
vector<vector<int>> E;

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
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void connect(int p, int q)
    {
        int rootp = find(p), rootq = find(q);
        if (rootp == rootq)
            return;
        parent[rootq] = rootp;
        cnt--;
    }

    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }
};

int main()
{
    int m, n;
    while (scanf("%d%d", &m, &n) && (m || n)) {
        DSU uf(m);
        E.clear();
        int sum = 0;
        while (n--) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            E.push_back({ z, x, y });
            sum += z;
        }
        sort(E.begin(), E.end());
        int chosen = 0;
        for (int i = 0; i < E.size() && uf.cnt > 1; ++i) {
            int a = E[i][1], b = E[i][2], cost = E[i][0];

            if (!uf.connected(a, b)) {
                uf.connect(a, b);
                chosen += cost;
            }
        }

        printf("%d\n", sum - chosen);
    }
}
