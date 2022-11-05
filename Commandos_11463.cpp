#include <bits/stdc++.h>

using namespace std;

#define MAXN 100
const int INF = 1e9;

int dist[MAXN][MAXN];
int s, d;
int T, N, R;

int main()
{
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        for (int i = 0; i < MAXN; ++i) {
            fill(dist[i], dist[i] + MAXN, INF);
            dist[i][i] = 0;
        }

        scanf("%d", &N);
        scanf("%d", &R);
        while (R--) {
            int u, v;
            scanf("%d %d", &u, &v);
            dist[u][v] = dist[v][u] = 1;
        }

        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        scanf("%d %d", &s, &d);
        int res = 0;

        for (int i = 0; i < N; ++i) {
            res = max(res, dist[s][i] + dist[i][d]);
        }

        printf("Case %d: %d\n", t, res);
    }
}
