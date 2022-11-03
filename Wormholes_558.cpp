#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

typedef vector<int> vi;
vector<vi> G;
vector<vi> E;
vi dist;

int main()
{
    int c, n, m;
    scanf("%d", &c);
    while (c--) {
        scanf("%d%d", &n, &m);
        int x, y, t;
        G = vector<vi>(n);
        E = vector<vi>(n, vector<int>(n, INF));
        dist.assign(n, INF);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &x, &y, &t);
            E[x][y] = t;
            G[x].push_back(y);
        }
        dist[0] = 0;

        for (int i = 0; i < n - 1; ++i) {
            for (int u = 0; u < n; ++u) {
                for (auto& v : G[u]) {
                    dist[v] = min(dist[v], dist[u] + E[u][v]);
                }
            }
        }

        bool negc = false;

        for (int u = 0; u < n; ++u) {
            for (auto& v : G[u]) {
                if (dist[v] > dist[u] + E[u][v]) {
                    negc = true;
                    break;
                }
            }
            if (negc)
                break;
        }

        printf(negc ? "possible\n" : "not possible\n");
    }
}
