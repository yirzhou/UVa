#include <bits/stdc++.h>

using namespace std;

#define N 20
int n;

double dist[N][N][N];
int path[N][N][N];

void f()
{
    for (int l = 1; l < n; ++l) {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    double d = dist[i][k][l - 1] * dist[k][j][1];
                    if (d > dist[i][j][l]) {
                        dist[i][j][l] = d;
                        path[i][j][l] = k;
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (dist[i][i][l] > 1.01) {
                vector<int> s;
                int j = i;
                while (l - 1) {
                    s.push_back(j = path[i][j][l--]);
                }

                printf("%d ", i + 1);
                while (!s.empty()) {
                    printf("%d ", s.back() + 1);
                    s.pop_back();
                }
                printf("%d\n", i + 1);
                return;
            }
        }
    }
    printf("no arbitrage sequence exists\n");
}

int main()
{
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                fill(dist[i][j], dist[i][j] + n, 0.0);
                fill(path[i][j], path[i][j] + n, i);
            }
            fill(dist[i][i], dist[i][i] + n, 1.0);
        }

        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (v == u)
                    continue;
                double val;
                scanf("%lf", &val);
                fill(dist[u][v] + 1, dist[u][v] + n, val);
            }
        }

        f();
    }
}
