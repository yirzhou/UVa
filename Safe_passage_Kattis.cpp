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

int n, mask;

int dp[2][1 << 15];

vi T;

int f(int pos, int mask)
{
    if (mask == (1 << n) - 1)
        return 0;
    if (dp[pos][mask] != -1)
        return dp[pos][mask];
    int target = pos ? 1 : 0;
    int ans = INT_MAX;
    if (pos) {
        for (int i = 0; i < n; ++i)
            if (((mask >> i) & 1) == target)
                ans = min(ans, T[i] + f(1 - pos, mask ^ (1 << i)));
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && (((mask >> i) & 1) == target) && ((mask >> j) & 1) == target)
                    ans = min(ans, max(T[i], T[j]) + f(1 - pos, mask | (1 << i) | (1 << j)));
            }
        }
    }

    return dp[pos][mask] = ans;
}

int main()
{
    fastio;
    cin >> n;
    T.assign(n, 0);
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; ++i)
        cin >> T[i];

    int res = f(0, 0);
    cout << res << endl;
    return 0;
}