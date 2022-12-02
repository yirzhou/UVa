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

unordered_set<string> dict;
vector<string> words;
map<string, int> dp;

class ED {
public:
    vector<vector<int>> memo;
    int f(string& s1, string& s2, int i, int j)
    {
        if (i == s1.length()) {
            return s2.length() - j;
        }
        if (j == s2.length()) {
            return s1.length() - i;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        char a = s1[i], b = s2[j];
        if (a == b) {
            memo[i][j] = f(s1, s2, i + 1, j + 1);
        } else {
            memo[i][j] = 1 + min(f(s1, s2, i + 1, j + 1), min(f(s1, s2, i + 1, j), f(s1, s2, i, j + 1)));
        }
        return memo[i][j];
    }

    int minDistance(string& s1, string& s2)
    {
        int m = s1.length(), n = s2.length();
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        return f(s1, s2, 0, 0);
    }
};

int main()
{
    fastio;
    string s, t;
    int res = 0;
    while (cin >> s) {
        if (!dp.count(s)) {
            dp[s] = 1, res = max(res, dp[s]);
        }

        for (int i = 0; i < s.size(); ++i) {
            for (char c = 'a'; c <= s[i]; ++c) {
                t = s.substr(0, i) + c + s.substr(i);
                if (dp.count(t)) {
                    dp[s] = max(dp[s], dp[t] + 1);
                    res = max(dp[s], res);
                }
            }
        }

        for (int i = 0; i < s.size(); ++i) {
            if (i + 1 < s.size() && s[i] < s[i + 1])
                continue;
            t = s.substr(0, i) + s.substr(i + 1);
            if (dp.count(t)) {
                dp[s] = max(dp[s], dp[t] + 1);
                res = max(dp[s], res);
            }
        }

        t = s;
        for (int i = 0; i < t.size(); ++i) {
            char cur = t[i];
            for (char c = 'a'; c < cur; ++c) {
                t[i] = c;
                if (dp.count(t)) {
                    dp[s] = max(dp[s], dp[t] + 1);
                    res = max(dp[s], res);
                }
            }
            t[i] = cur;
        }
    }

    cout << res << endl;
    return 0;
}