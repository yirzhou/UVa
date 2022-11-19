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

#define MAXN 1000010

unsigned long long dp[MAXN];

int main()
{
    int n;
    memset(dp, 0, sizeof dp);
    dp[0] = dp[1] = 0;
    for (int i = 2; i <= MAXN - 1; ++i) {
        if (i % 2) {
            ll k = (i - 1) >> 1;
            dp[i] = k * (k + 1) * (4 * k + 5) / 6;
        } else {
            ll k = i >> 1;
            dp[i] = k * (k + 1) * (4 * k - 1) / 6;
        }
    }

    while (cin >> n && n > 2) {
        printf("%lld\n", dp[n - 2]);
    }
}