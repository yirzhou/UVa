#include <algorithm>
#include <assert.h>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define oo INT_MAX
#define UNVISITED -1
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
typedef vector<vi> vii;

int S[255], pre[255];
int memo[255][255];
int opt[255][255];
int n;

int rsq(int i, int j)
{
    if (i > j)
        return 0;
    return pre[j + 1] - pre[i];
}

int dp(int i, int j)
{
    if (i >= j)
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];
    int ans = INT_MAX;
    for (int k = i; k <= j; ++k) {
        int tcost = dp(i, k - 1) + dp(k + 1, j) + rsq(i, k - 1) + rsq(k + 1, j);
        ans = min(ans, tcost);
    }

    return memo[i][j] = ans;
}

int main()
{
    fastio;

    while (cin >> n) {
        for (int i = 0; i < n; ++i)
            cin >> S[i];
        pre[0] = 0;
        for (int i = 1; i <= n; ++i)
            pre[i] = pre[i - 1] + S[i - 1];
        memset(memo, -1, sizeof memo);
        int res = dp(0, n - 1);
        cout << res << endl;
    }

    return 0;
}
