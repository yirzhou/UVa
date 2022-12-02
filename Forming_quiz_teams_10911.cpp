#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
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

ii D[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

#define MAXN 8

int pos[2 * MAXN][2];

int N, M;

double dp[(1 << 2 * MAXN)];

double dist(int s1, int s2)
{
    int x1 = pos[s1][0], y1 = pos[s1][1], x2 = pos[s2][0], y2 = pos[s2][1];
    return sqrt(pow(abs(x1 - x2), 2.0) + pow(abs(y1 - y2), 2.0));
}

double f(int mask)
{
    if (mask == ((1 << M) - 1)) {
        return 0;
    }

    if (dp[mask] != -1.0)
        return dp[mask];

    double ans = oo;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i != j && ((mask >> i) & 1) == 0 && ((mask >> j) & 1) == 0) {
                ans = min(ans, dist(i, j) + f(mask | (1 << i) | (1 << j)));
            }
        }
    }

    return dp[mask] = ans;
}

int main()
{
    fastio;
    precision(2);
    string name;
    int x, y, caseno = 1;
    while (cin >> N && N) {
        int id = 0;
        M = 2 * N;
        memset(pos, 0, sizeof pos);
        fill(dp, dp + (1 << M), -1);
        for (int i = 0; i < M; ++i) {
            cin >> name >> x >> y;
            pos[id][0] = x, pos[id][1] = y, id++;
        }
        cout << "Case " << caseno++ << ": ";
        double res = f(0);
        cout << res << endl;
    }

    return 0;
}