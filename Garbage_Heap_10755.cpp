#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAXN 20
int N, A, B, C, T;
ll arr[MAXN][MAXN][MAXN];
ll pre[MAXN + 1][MAXN + 1][MAXN + 1];

ll area(int x1, int y1, int x2, int y2, int c)
{
    return pre[x2 + 1][y2 + 1][c + 1] - pre[x2 + 1][y1][c + 1] - pre[x1][y2 + 1][c + 1] + pre[x1][y1][c + 1];
}

void get_pre()
{
    for (int c = 1; c <= C; ++c) {
        for (int x = 1; x <= A; ++x) {
            for (int y = 1; y <= B; ++y) {
                pre[x][y][c] = pre[x][y - 1][c] + pre[x - 1][y][c] - pre[x - 1][y - 1][c] + arr[x - 1][y - 1][c - 1];
            }
        }
    }
}

int main()
{
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d %d", &A, &B, &C);
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                memset(pre[i][j], 0, sizeof(pre[i][j]));
            }
        }
        for (int i = 0; i < A; ++i) {
            for (int j = 0; j < B; ++j) {
                for (int k = 0; k < C; ++k) {
                    scanf("%lld", &arr[i][j][k]);
                }
            }
        }

        get_pre();
        ll res = LONG_MIN;
        for (int x1 = 0; x1 < A; ++x1) {
            for (int y1 = 0; y1 < B; ++y1) {
                for (int x2 = x1; x2 < A; ++x2) {
                    for (int y2 = y1; y2 < B; ++y2) {
                        ll sum = 0;
                        for (int c = 0; c < C; ++c) {
                            ll val = area(x1, y1, x2, y2, c);
                            sum = max(sum + val, val);
                            res = max(res, sum);
                        }
                    }
                }
            }
        }
        printf("%lld\n", res);
        if (T)
            printf("\n");
    }
}
