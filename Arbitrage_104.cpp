#include <bits/stdc++.h>

using namespace std;

#define N 25
int n;

double dist[N][N][N];
int path[N][N][N];

void printfPath(int i, int j, int s)
{
    if (s == 0) {
        printf("%d", i);
        return;
    }
    printfPath(i, path[i][j][s], s - 1);
    printf(" %d", j);
    return;
}

void f()
{
    for (int l = 2; l <= n; ++l) {
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    double d = dist[i][k][l - 1] * dist[k][j][1];
                    if (d > dist[i][j][l]) {
                        dist[i][j][l] = d;
                        path[i][j][l] = k;
                    }
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (dist[i][i][l] > 1.01) {
                printfPath(i, i, l);
                printf("\n");
                return;
            }
        }
    }
    printf("no arbitrage sequence exists\n");
}

int main()
{
    while (scanf("%d", &n) == 1) {
        memset(dist, 0, sizeof(dist));
        memset(path, 0, sizeof(path));

        for (int u = 1; u <= n; ++u) {
            for (int v = 1; v <= n; ++v) {
                if (v == u) {
                    dist[u][v][1] = 1.0;

                } else {
                    scanf("%lf", &dist[u][v][1]);
                }
            }
        }

        f();
    }
}
