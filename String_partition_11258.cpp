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

#define MAXN 505

string s;

ll dp[MAXN];

ll f(int idx)
{
    if (dp[idx] != -1)
        return dp[idx];

    if (idx == s.size())
        return dp[idx] = 0;
    if (idx == s.size() - 1)
        return dp[idx] = s[idx] - '0';

    if (s[idx] == '0')
        return f(idx + 1);

    ll ans = INT_MIN, sum = 0;
    for (int i = idx; i < s.size(); ++i) {
        sum *= 10;
        sum += s[i] - '0';
        if (sum < 0 || sum > INT_MAX)
            continue;
        ll rem = f(i + 1);
        ans = max(ans, rem + sum);
    }
    return dp[idx] = ans;
}

int main()
{
    int N;
    getline(cin, s);
    N = stoi(s);
    while (N--) {
        getline(cin, s);
        fill(dp, dp + MAXN, -1);
        ll res = f(0);
        printf("%lld\n", res == INT_MIN ? 0 : res);
    }
}