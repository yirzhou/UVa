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

ii D[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

int n, k;

vector<vii> G;

ll dp[15][1005];

ll f(int i, int k_left)
{
    if (k_left < 0)
        return INT_MAX;
    if (i == n && k_left == 0)
        return 0;
    ll& res = dp[i][k_left];
    if (res != -1)
        return res;
    int days = (k - k_left);
    ll ans = INT_MAX;
    for (int j = 1; j <= n; ++j) {
        if (j == i)
            continue;
        int idx = days % G[i][j].size();
        if (!G[i][j][idx])
            continue;

        ans = min(ans, G[i][j][idx] + f(j, k_left - 1));
    }

    return res = ans;
}

int main()
{
    fastio;
    int s = 1;
    while (cin >> n >> k && (n | k)) {
        cout << "Scenario #" << s++ << endl;
        G.assign(n + 1, vii(n + 1, vi()));
        memset(dp, -1, sizeof dp);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j)
                    continue;
                int p, c;
                cin >> p;
                while (p--) {
                    cin >> c;
                    G[i][j].pb(c);
                }
            }
        }

        ll ans = f(1, k);
        if (ans >= INT_MAX)
            cout << "No flight possible.\n";
        else
            cout << "The best flight costs " << ans << "." << endl;
        cout << endl;
    }
    return 0;
}