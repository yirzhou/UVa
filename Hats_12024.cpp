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

int dp[15];
int memo[15];

int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    if (memo[n] != -1)
        return memo[n];
    return memo[n] = n * fact(n - 1);
}

int der(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = (n - 1) * (der(n - 1) + der(n - 2));
}

int main()
{
    fastio;
    int t, n;
    cin >> t;
    while (t--) {
        memset(dp, -1, sizeof dp);
        memset(memo, -1, sizeof memo);
        cin >> n;

        cout << der(n) << "/" << fact(n) << endl;
    }
    return 0;
}