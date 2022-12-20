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

int k, n;

vector<vector<double>> memo;

double dp(int i, int j)
{
    if (i == 1)
        return 1.0;

    if (memo[i][j] != -1.0)
        return memo[i][j];

    if (j == 0)
        return memo[i][j] = dp(i - 1, j) + dp(i - 1, j + 1);
    if (j == k)
        return memo[i][j] = dp(i - 1, j - 1) + dp(i - 1, j);

    return memo[i][j] = dp(i - 1, j) + dp(i - 1, j - 1) + dp(i - 1, j + 1);
}

int main()
{
    fastio;
    precision(5);

    while (cin >> k >> n) {
        memo = vector<vector<double>>(n + 1, vector<double>(k + 1, -1.0));
        double cnt = 0.0;
        for (int i = 0; i <= k; ++i)
            cnt += dp(n, i);
        if (k == 0 && n > 1)
            cnt /= 2.0;
        cout << cnt / pow(k + 1, n) * 100 << endl;
    }

    return 0;
}
