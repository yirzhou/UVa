#include <bits/stdc++.h>

#define MAXH 9
#define MAXX 1000
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

vector<ii> D { { -1, 20 }, { 0, 30 }, { 1, 60 } };
int A[10][MAXX];
int dp[10][MAXX];

int T, X;

ll f(int h, int x)
{
    if (x == X)
        return h == 0 ? 0 : INT_MAX;

    ll ans = INT_MAX;
    if (dp[h][x] != -1)
        return dp[h][x];
    int dh, dc;
    for (auto& d : D) {
        dh = d.first, dc = d.second;
        if (h + dh >= 0 && h + dh <= MAXH) {
            ans = min(ans, f(h + dh, x + 1) + dc - A[h][x]);
        }
    }
    dp[h][x] = ans;
    return ans;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 10; ++i)
            memset(dp[i], -1, sizeof(dp[i]));
        scanf("%d", &X);
        X /= 100;
        for (int i = 9; i >= 0; --i) {
            for (int j = 0; j < X; ++j) {
                scanf("%d", &A[i][j]);
            }
        }
        ll res = f(0, 0);
        printf("%lld\n\n", res);
    }
}
