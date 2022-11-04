#include <bits/stdc++.h>

using namespace std;

#define N 100
#define INF 1000000000

typedef vector<int> vi;
typedef set<int> si;

int dist[N + 1][N + 1];

si nodes;

int main()
{
    int u, v;
    int c = 1;
    while (scanf("%d%d", &u, &v) && (u && v)) {
        nodes.clear();
        for (int i = 0; i <= N; ++i)
            fill(dist[i], dist[i] + N + 1, INF);
        dist[u][v] = 1;
        nodes.insert(u);
        nodes.insert(v);
        while (scanf("%d%d", &u, &v) && (u && v)) {
            dist[u][v] = 1;
            nodes.insert(u);
            nodes.insert(v);
        }
        for (auto& u : nodes)
            dist[u][u] = 0;

        for (auto& k : nodes) {
            for (auto& i : nodes) {
                for (auto& j : nodes) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        double total = 0.0, cnt = 0.0;
        for (auto& u : nodes) {
            for (auto& v : nodes) {
                if (u != v && dist[u][v] < INF) {
                    cnt += 1.0;
                    total += dist[u][v];
                }
            }
        }

        double res = total / cnt;

        printf("Case %d: average length between pages = %.3f clicks\n", c++, res);
    }
}
