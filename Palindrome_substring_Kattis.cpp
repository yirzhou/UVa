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

int dp[1005][1005];

int main()
{
    fastio;
    string s;
    while (getline(cin, s) && s.size()) {
        memset(dp, 0, sizeof dp);
        set<string> S;
        int a, b, n = s.size();
        for (int i = 0; i < n; ++i) {
            a = i, b = i;
            while (a >= 0 && b < n && s[a] == s[b]) {
                dp[a][b] = 1;
                if (b - a >= 1)
                    S.emplace(s.substr(a, b - a + 1));
                a--;
                b++;
            }
            if (i + 1 < n && s[i] == s[i + 1]) {
                a = i, b = i + 1;
                while (a >= 0 && b < n && s[a] == s[b]) {
                    dp[a][b] = 1;
                    if (b - a >= 1)
                        S.emplace(s.substr(a, b - a + 1));
                    a--;
                    b++;
                }
            }
        }

        for (auto& str : S) {
            cout << str << endl;
        }
        cout << endl;
    }
}