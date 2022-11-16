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

#define MAXN 80

int dp[MAXN][MAXN];

string s;

bool check(int i, int j, int l)
{
    for (; i < j - l + 1; i += l) {
        if (s.substr(i, l) != s.substr(i + l, l)) {
            return false;
        }
    }
    return true;
}

int f(int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == j)
        return dp[i][j] = 1;
    if (i > j)
        return dp[i][j] = s.size();
    int L = j - i + 1, ans = L;
    for (int l = 1; l < L; ++l) {
        if (L % l == 0 && check(i, j, l)) {

            ans = min(ans, f(i, i + l - 1));
        }
        ans = min(ans, f(i, i + l - 1) + f(i + l, j));
    }

    return dp[i][j] = ans;
}

void init()
{
    for (int i = 0; i < MAXN; ++i)
        fill(dp[i], dp[i] + MAXN, -1);
}

int main()
{
    while (getline(cin, s) && s != "*") {
        init();
        int res = f(0, s.size() - 1);
        cout << res << endl;
    }
}