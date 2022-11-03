#include <bits/stdc++.h>

using namespace std;

int l, n;
int A[51];
int memo[52][52];

int f(int l, int r)
{
    if (l + 1 >= r)
        return 0;
    if (memo[l][r] != -1)
        return memo[l][r];
    int ans = INT_MAX;
    for (int i = l + 1; i <= r - 1; ++i) {
        ans = min(ans, A[r] - A[l] + f(l, i) + f(i, r));
    }
    memo[l][r] = ans;
    return ans;
}

int main()
{
    A[0] = 0;
    while (scanf("%d", &l) && l) {
        for (int i = 0; i < 52; ++i)
            memset(memo[i], -1, sizeof(memo[i]));

        scanf("%d", &n);
        int val;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &val);
            A[i] = val;
        }
        A[n + 1] = l;
        printf("The minimum cutting is %d.\n", f(0, n + 1));
    }

    return 0;
}
