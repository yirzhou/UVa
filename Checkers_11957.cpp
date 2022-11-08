#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000007;

int u, n;
typedef vector<char> vc;
vector<vc> G;

int memo[100][100];

int dp(int i, int j)
{
    if (i == 0) {
        return 1;
    }
    if (memo[i][j] != -1)
        return memo[i][j];

    int res = 0;

    if (i - 1 >= 0 && j + 1 < n) {
        if (G[i - 1][j + 1] != 'B')
            res = (res + dp(i - 1, j + 1)) % MOD;
        else if (G[i - 1][j + 1] == 'B' && i - 2 >= 0 && j + 2 < n && G[i - 2][j + 2] != 'B')
            res = (res + dp(i - 2, j + 2)) % MOD;
    }

    if (i - 1 >= 0 && j - 1 >= 0) {
        if (G[i - 1][j - 1] != 'B')
            res = (res + dp(i - 1, j - 1)) % MOD;
        else if (G[i - 1][j - 1] == 'B' && i - 2 >= 0 && j - 2 >= 0 && G[i - 2][j - 2] != 'B')
            res = (res + dp(i - 2, j - 2)) % MOD;
    }

    return memo[i][j] = res;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d\n", &n);
        G = vector<vc>(n, vc(n));
        for (int i = 0; i < n; ++i) {
            fill(memo[i], memo[i] + n, -1);
        }
        int si, sj;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%c", &G[i][j]);
                if (G[i][j] == 'W') {
                    si = i, sj = j;
                }
            }
            scanf("\n");
        }
        int res = dp(si, sj);
        printf("Case %d: %d\n", t, res);
    }
}