#include <bits/stdc++.h>
using namespace std;
#define MAXN 100

typedef long long ll;
int T, N, M, K;
ll pre[MAXN + 1][MAXN + 1];
ll val;

ll area(int x1, int y1, int x2, int y2)
{
    return pre[x2 + 1][y2 + 1] - pre[x2 + 1][y1] - pre[x1][y2 + 1] + pre[x1][y1];
}

int main()
{
    scanf("%d", &T);
    for (int n = 0; n <= MAXN; ++n) {
        memset(pre[n], 0, sizeof(pre[n]));
    }

    for (int i = 1; i <= T; ++i) {
        int ans = 0;
        ll P = LONG_MAX;
        scanf("%d %d %d", &N, &M, &K);
        for (int n = 1; n <= N; ++n) {
            for (int m = 1; m <= M; ++m) {
                scanf("%lld", &val);
                pre[n][m] = pre[n][m - 1] + pre[n - 1][m] - pre[n - 1][m - 1] + val;
            }
        }

        for (int x1 = 0; x1 < N; ++x1) {
            for (int x2 = x1; x2 < N; ++x2) {
                int y1 = 0;
                ll sum = 0;
                for (int y2 = 0; y2 < M; ++y2) {
                    sum += area(x1, y2, x2, y2);
                    while (sum > K) {
                        int prev = area(x1, y1, x2, y1);
                        sum -= prev;
                        y1++;
                    }
                    int a = (x2 - x1 + 1) * (y2 - y1 + 1);
                    if (a > ans) {
                        ans = a;
                        P = sum;
                    } else if (a == ans) {
                        P = min(P, sum);
                    }
                }
            }
        }

        printf("Case #%d: %d %lld\n", i, ans, P);
    }
}
