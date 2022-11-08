#include <bits/stdc++.h>

using namespace std;

#define MAXN 120
#define MAXM 15
#define INF 1000000000

char T[13];

int n, m;
typedef vector<int> vi;
int t[MAXN * MAXM][MAXN * MAXM];

int memo[MAXN][MAXM];

int dp(int i, int j)
{
    if (i == n - 1)
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];
    int u = i * m + j;
    int ans = INF;
    for (int k = 0; k < m; ++k) {
        int v = (i + 1) * m + k;
        ans = min(ans, 2 + t[u][v] + dp(i + 1, k));
    }

    return memo[i][j] = ans;
}

int main()
{
    while (scanf("%s", T) != EOF) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < MAXN * MAXM; ++i)
            fill(t[i], t[i] + MAXN * MAXM, INF);

        for (int i = 0; i < MAXN; ++i)
            fill(memo[i], memo[i] + MAXM, -1);

        int u, v;
        for (int k = 0; k < n - 1; ++k) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < m; ++j) {
                    u = k * m + i, v = (k + 1) * m + j;
                    scanf("%d", &t[u][v]);
                }
            }
        }
        int res = INF;
        for (int j = 0; j < m; ++j)
            res = min(res, dp(0, j));
        printf("%s\n%d\n", T, res);
    }
}