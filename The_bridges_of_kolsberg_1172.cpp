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

vector<pair<string, int>> N, S;

ii dp[1005][1005];

ii f(int i, int j)
{
    if (i == N.size() || j == S.size())
        return dp[i][j] = { 0, 0 };
    if (dp[i][j].fi != -1)
        return dp[i][j];
    int maxtv = 0, min_cnt = max(N.size() - i, S.size() - j);
    if (N[i].fi == S[j].fi) {
        ii res = f(i + 1, j + 1);
        maxtv = max(maxtv, N[i].se + S[j].se + res.fi);
        min_cnt = min(min_cnt, 1 + res.se);
    }
    ii r1 = f(i + 1, j);
    ii r2 = f(i, j + 1);

    int tv = 0, cnt = 0;
    if (r1.fi > r2.fi)
        tv = r1.fi, cnt = r1.se;
    else if (r2.fi > r1.fi)
        tv = r2.fi, cnt = r2.se;
    else
        tv = r1.fi, cnt = min(r2.se, r1.se);

    if (tv > maxtv) {
        maxtv = tv, min_cnt = cnt;
    } else if (tv == maxtv)
        min_cnt = min(min_cnt, cnt);

    return dp[i][j] = { maxtv, min_cnt };
}

int main()
{
    fastio;
    string city, os;
    int t, tv, cities;
    cin >> t;
    while (t--) {
        N.clear(), S.clear();
        for (int i = 0; i < 1005; ++i)
            fill(dp[i], dp[i] + 1005, ii(-1, -1));

        cin >> cities;
        while (cities--) {
            cin >> city >> os >> tv;
            N.pb({ os, tv });
        }

        cin >> cities;
        while (cities--) {
            cin >> city >> os >> tv;
            S.pb({ os, tv });
        }

        ii res = f(0, 0);
        cout << res.fi << " " << res.se << endl;
    }
    return 0;
}