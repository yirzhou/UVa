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

#define MAXN 105

ii D[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

int G[MAXN][MAXN];
int dp[MAXN][MAXN];

int t, n, k;

bitset<MAXN * MAXN> mask;

int f(int i, int j, bitset<MAXN * MAXN>& V)
{

    int pos = i * n + j;
    if (V[pos] == 1)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    V[pos] = 1;
    int ans = G[i][j];

    for (int r = i + 1; r <= min(i + k, n - 1); ++r)
        if (G[r][j] > G[i][j])
            ans = max(ans, G[i][j] + f(r, j, V));

    for (int r = i - 1; r >= max(0, i - k); --r)
        if (G[r][j] > G[i][j])
            ans = max(ans, G[i][j] + f(r, j, V));

    for (int c = j + 1; c <= min(j + k, n - 1); ++c)
        if (G[i][c] > G[i][j])
            ans = max(ans, G[i][j] + f(i, c, V));

    for (int c = j - 1; c >= max(j - k, 0); --c)
        if (G[i][c] > G[i][j])
            ans = max(ans, G[i][j] + f(i, c, V));

    V[pos] = 0;
    return dp[i][j] = ans;
}

void proc()
{
    mask.reset();
    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> G[i][j];
}

int main()
{
    fastio;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        if (i)
            cout << endl;
        proc();
        int res = f(0, 0, mask);
        cout << res << endl;
    }

    return 0;
}