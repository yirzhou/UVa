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

ll A[65][35];
int n;

ll memo[65][35][6010];

const ll OFF = 3005;

void init()
{
    for (int i = 0; i < 65; ++i)
        fill(A[i], A[i] + 35, 55ll);

    for (int i = 0; i < 65; ++i) {
        for (int j = 0; j < 35; ++j)
            fill(memo[i][j], memo[i][j] + 6010, 2 * OFF);
    }
}

int check(int i, int j)
{
    return (i >= 0 && i < 2 * n - 1 && j >= 0 && j < n) && abs(A[i][j]) <= 50;
}

ll dp(int i, int j, int sum)
{
    ll& ans = memo[i][j][sum + OFF];

    if (ans != 2 * OFF)
        return ans;

    if (i == 0 && j == 0) {
        ll r1 = A[i][j] + sum, r2 = -A[i][j] + sum;
        return ans = (abs(r1) < abs(r2) ? r1 : r2);
    }
    int ni = i - 1, nj1 = j, nj2 = i <= (n - 1) ? j - 1 : j + 1;
    ll r1 = INT_MAX, r2 = INT_MAX;

    if (i == 2 * n - 2)
        r1 = dp(i - 1, j, sum + A[i][j]), r2 = dp(i - 1, j + 1, sum + A[i][j]);

    if (check(ni, nj1)) {
        ll a = dp(ni, nj1, sum + A[i][j]), b = dp(ni, nj1, sum - A[i][j]);
        r1 = abs(a) < abs(b) ? a : b;
    }

    if (check(ni, nj2)) {
        ll a = dp(ni, nj2, sum + A[i][j]), b = dp(ni, nj2, sum - A[i][j]);
        r2 = abs(a) < abs(b) ? a : b;
    }

    return ans = (abs(r1) < abs(r2) ? r1 : r2);
}

int main()
{
    fastio;
    while (cin >> n && n) {

        init();

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i + 1; ++j)
                cin >> A[i][j];

        for (int i = n; i < 2 * n - 1; ++i)
            for (int j = 0; j < 2 * n - i - 1; ++j)
                cin >> A[i][j];

        ll res = dp(2 * n - 2, 0, 0);
        cout << abs(res) << endl;
    }

    return 0;
}
