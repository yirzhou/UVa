#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
#define UNVISITED -1
#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define pll(a, b) printf("%lld %lld\n", a, b)
#define plll(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
#define precision(a) \
    cout << fixed;   \
    cout.precision(a)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vi> vii;

#define MAXN 1005

ii D[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

int n;
int G[MAXN][MAXN];
int V[MAXN][MAXN];
ll dp[MAXN][MAXN];

const ll MOD = (1 << 31) - (ll)1;

bool check()
{
    queue<ii> q;
    q.push({ 1, 1 });
    memset(V, 0, sizeof V);
    int i, j, ni, nj;
    while (q.size()) {
        i = q.front().fi, j = q.front().se;
        q.pop();
        if (i == n && j == n)
            return true;
        if (V[i][j])
            continue;

        V[i][j] = 1;
        for (auto& [di, dj] : D) {
            ni = i + di, nj = j + dj;
            if (ni >= 1 && ni <= n && nj >= 1 && nj <= n && G[ni][nj] && !V[ni][nj])
                q.push({ ni, nj });
        }
    }
    return false;
}

int main()
{
    fastio;
    memset(G, 0, sizeof G);
    memset(dp, 0, sizeof dp);
    cin >> n;
    char c;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> c;
            G[i][j] = c == '.';
        }
    }

    if (G[1][1] && G[n][n])
        dp[1][1] = 1;
    else {
        cout << "INCONCEIVABLE";
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!G[i][j])
                continue;
            if (i == 1 && j == 1)
                continue;
            dp[i][j] = 1ll * (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }

    if (dp[n][n])
        cout << dp[n][n];
    else if (check())
        cout << "THE GAME IS A LIE";
    else
        cout << "INCONCEIVABLE";

    return 0;
}