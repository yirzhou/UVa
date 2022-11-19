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
int n;
vi dp;

int f(int i)
{
    if (i > n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    if (i + 2 > n)
        return dp[i] = 1;
    return dp[i] = f(i + 2) + f(i + 3);
}

int main()
{
    while (si(n) != EOF) {
        dp.assign(n + 1, -1);
        int res = f(1) + f(2);
        cout << res << endl;
    }
}