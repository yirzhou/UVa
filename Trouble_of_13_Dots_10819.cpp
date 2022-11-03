#include <bits/stdc++.h>

#define MAXP 10000
#define MAXF 5
#define C 2000
#define R 200
#define MAXN 100

using namespace std;

typedef pair<int, int> ii;
int m, n;
vector<ii> A(MAXN);
int dp[MAXP + R + 1][MAXN];
int ans = 0;

int func(int cost, int i)
{
    if (i == n)
        return 0;
    int fval = A[i].second, pval = A[i].first, res = 0;

    if (dp[cost][i] != -1)
        return dp[cost][i];

    if (cost + pval <= m || (cost + pval > C && cost + pval <= m + 200)) {
        res = fval + func(cost + pval, i + 1);
    }
    res = max(res, func(cost, i + 1));

    ans = max(ans, res);
    dp[cost][i] = res;
    return res;
}

int main()
{
    while (scanf("%d %d", &m, &n) != EOF) {
        ans = 0;
        int f, p;
        for (int i = 0; i <= MAXP + R; ++i) {
            memset(dp[i], -1, sizeof(dp[i]));
        }

        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &p, &f);
            A[i] = { p, f };
        }
        sort(A.begin(), A.begin() + n);
        func(0, 0);
        printf("%d\n", ans);
    }
}
