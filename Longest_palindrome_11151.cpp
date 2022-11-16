#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

#define MAXN 1000

vector<vi> dp;

string s;

int f(int l, int r)
{
    if (l == r)
        return 1;
    if (l + 1 == r)
        return s[l] == s[r] ? 2 : 1;
    if (l > r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];

    if (s[l] == s[r])
        return dp[l][r] = 2 + f(l + 1, r - 1);
    return dp[l][r] = max(f(l, r - 1), f(l + 1, r));
}

int main()
{
    int T;
    cin >> T;
    getline(cin, s);
    while (T--) {

        getline(cin, s);
        int n = s.size();
        dp = vector<vi>(n, vi(n, -1));

        cout << f(0, n - 1) << endl;
    }
}