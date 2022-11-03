#include <bits/stdc++.h>

#define MAXN 2000

int lis[2 * MAXN + 1];
int A[2 * MAXN];
int T, n;

using namespace std;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);

        for (int i = 0; i < n; ++i) {
            scanf("%d", &A[i + n]);
            A[n - i - 1] = A[i + n];
        }
        for (int i = 0; i <= MAXN << 1; ++i) {
            lis[i] = 1;
        }

        n <<= 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (A[j] < A[i])
                    lis[i] = max(lis[i], lis[j] + 1);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, lis[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
