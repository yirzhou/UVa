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

#define MAXN 105

string a, b;

int dp[MAXN][MAXN];

int lcs(int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == a.size() || j == b.size())
        return dp[i][j] = 0;

    char c1 = a[i], c2 = b[j];
    if (c1 == c2)
        return dp[i][j] = 1 + lcs(i + 1, j + 1);
    return dp[i][j] = max(lcs(i + 1, j), lcs(i, j + 1));
}

int main()
{
    int caseno = 0;
    while (getline(cin, a) && a[0] != '#') {
        for (int i = 0; i < MAXN; ++i)
            fill(dp[i], dp[i] + MAXN, -1);
        getline(cin, b);
        int ans = lcs(0, 0);
        printf("Case #%d: you can visit at most %d cities.\n", ++caseno, ans);
    }
}