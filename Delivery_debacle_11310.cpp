#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

ll dp[45];

ll f(int n)
{
    return dp[n] = dp[n - 1] + 4 * dp[n - 2] + 2 * dp[n - 3];
}

int main()
{
    int t, len;
    cin >> t;
    memset(dp, -1, sizeof dp);
    dp[0] = dp[1] = 1;
    dp[2] = 5;

    for (int i = 3; i <= 40; ++i)
        f(i);

    while (t--) {
        cin >> len;
        printf("%lld\n", dp[len]);
    }
}