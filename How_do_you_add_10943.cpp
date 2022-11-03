#include <bits/stdc++.h>
#define MOD 1000000

using namespace std;

typedef long long ll;

int N, K;
ll dp[101][101];

ll f(int n, int k)
{
    if (k == 2)
        return n + 1;
    if (k == 1)
        return 1;

    if (dp[n][k] != -1)
        return dp[n][k];
    ll ans = 0;

    for (int i = 0; i <= n; ++i) {
        ans = (ans + f(n - i, k - 1)) % MOD;
    }
    dp[n][k] = ans;
    return ans;
}

int main()
{
    while (scanf("%d %d", &N, &K) && N && K) {
        for (int i = 0; i < 101; ++i)
            memset(dp[i], -1, sizeof(dp[i]));

        ll res = f(N, K);
        printf("%lld\n", res);
    }
}
