#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int M[8][8];
int n;
int order[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
int f(int n)
{
    int ans = INT_MAX;
    do {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += M[i][order[i]];
        }
        ans = min(ans, sum);
    } while (next_permutation(order, order + n));
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 0; i < 8; ++i) {
            memset(M[i], 0, sizeof(M[i]));
        }

        scanf("%d", &n);
        sort(order, order + n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &M[i][j]);
            }
        }

        printf("%d\n", f(n));
    }
}
