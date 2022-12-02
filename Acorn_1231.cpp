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

int main()
{
    fastio;
    int c, t, h, f;
    cin >> c;
    while (c--) {
        cin >> t >> h >> f;
        vector<vi> trees(t, vi(h + 1, 0));
        for (int i = 0; i < t; ++i) {
            int cnt;
            cin >> cnt;
            while (cnt--) {
                int height;
                cin >> height;
                trees[i][height]++;
            }
        }

        vi dp(h + 1, 0);
        for (int i = 0; i < t; ++i)
            dp[h] = max(dp[h], trees[i][h]);

        for (int height = h - 1; height >= 0; --height) {
            for (int tree = 0; tree < t; ++tree) {
                trees[tree][height] += max(trees[tree][height + 1], ((height + f) <= h ? dp[height + f] : 0));
                dp[height] = max(dp[height], trees[tree][height]);
            }
        }

        cout << dp[0] << endl;
    }

    return 0;
}