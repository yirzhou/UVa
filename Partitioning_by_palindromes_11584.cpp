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
int dp[1005][1005];
int memo[1005];

int isPalDP(int l, int r)
{
    if (l == r)
        return 1;
    if (l + 1 == r)
        return s[l] == s[r];
    int& ans = dp[l][r];
    if (ans != -1)
        return ans;
    ans = 0;
    if (s[l] == s[r])
        ans = isPalDP(l + 1, r - 1);
    return ans;
}

int f(int i)
{
    if (i == s.size())
        return 0;
    if (memo[i] != -1)
        return memo[i];
    int ans = s.size();
    for (int j = i; j < s.size(); ++j) {
        if (dp[i][j]) {
            ans = min(ans, 1 + f(j + 1));
        }
    }

    return memo[i] = ans;
}

int main()
{
    fastio;
    int N;
    cin >> N;

    while (N--) {
        cin >> s;
        int n = s.size();
        memset(dp, 0, sizeof dp);
        memset(memo, -1, sizeof memo);
        int a, b;
        for (int i = 0; i < n; ++i) {
            // Check odd
            a = i, b = i;
            while (a >= 0 && b < n && s[a] == s[b]) {
                dp[a][b] = 1;
                a--;
                b++;
            }
            // Check even
            if (i + 1 < n && s[i] == s[i + 1]) {
                a = i, b = i + 1;
                while (a >= 0 && b < n && s[a] == s[b]) {
                    dp[a][b] = 1;
                    a--;
                    b++;
                }
            }
        }

        cout << f(0) << endl;
    }
}