#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
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

string s;
vi digits;

const int MAXN = 100;
ll dp[MAXN][10][5];

bool check()
{
    bool falling = false;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] < s[i - 1]) {
            falling = true;
        } else if (s[i] > s[i - 1]) {
            if (falling)
                return false;
        }
    }
    return true;
}

ll f(int i, int w, int ismax, int pa)
{
    if (i == s.size())
        return 1;
    ll ans = 0;
    if (!ismax && dp[i][pa][w])
        return dp[i][pa][w];
    int maxv = ismax ? digits[i] : 9;
    for (int d = 0; d <= maxv; ++d) {
        if (w == 1) {
            // Rising
            if (d >= pa) {
                ans += f(i + 1, 1, ismax && d == maxv, d);
            } else {
                ans += f(i + 1, 3, ismax && d == maxv, d);
            }
        } else if (w == 2) {
            // Falling
            if (d > pa)
                continue;
            else {
                ans += f(i + 1, 2, ismax && d == maxv, d);
            }
        } else if (w == 3) {
            // Rising and falling
            if (d > pa)
                continue;
            else {
                ans += f(i + 1, 3, ismax && d == maxv, d);
            }
        }
    }
    if (!ismax)
        dp[i][pa][w] = ans;
    return ans;
}

int main()
{
    fastio;
    while (getline(cin, s) && s.size()) {
        if (!check()) {
            cout << -1 << endl;
            continue;
        }
        int n = s.size();
        digits.assign(n, 0);
        for (int i = 0; i < n; ++i)
            digits[i] = s[i] - '0';
        memset(dp, 0, sizeof(dp));
        ll res = f(0, 1, 1, -1) - 1;
        cout << (ll)res << endl;
    }
}