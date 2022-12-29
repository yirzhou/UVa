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

int n, m;
int P[35];

int dp1[35][105], dp2[35][105];

int target, res;

int f1(int i, int k)
{
    if (dp1[i][k] != -1)
        return dp1[i][k];
    if (k == 0)
        return dp1[i][k] = INF;
    if (i == m)
        return dp1[i][k] = 0;

    int ans = f1(i + 1, k), u;
    for (int j = 1; j <= k; ++j) {
        u = f1(i + 1, k - j);
        ans = max(ans, min(u, P[i] / j));
    }

    return dp1[i][k] = ans;
}

int f2(int i, int k)
{
    if (dp2[i][k] != -1)
        return dp2[i][k];
    if (k == 0)
        return dp2[i][k] = 0;

    if (i == m)
        return dp2[i][k] = 30005;

    int ans = f2(i + 1, k), cost;

    for (int j = 1; j <= k; ++j) {
        int u = P[i] / j;
        cost = f2(i + 1, k - j);
        if (u >= target)
            ans = min(ans, P[i] + cost);
    }

    return dp2[i][k] = ans;
}

int main()
{
    fastio;

    while (cin >> n >> m && (n | m)) {
        for (int i = 0; i < m; ++i)
            cin >> P[i];

        memset(dp1, -1, sizeof dp1);
        memset(dp2, -1, sizeof dp2);

        target = f1(0, n);
        res = f2(0, n);
        cout << target << " " << (target == 0 ? 0 : res) << endl;
    }

    return 0;
}
