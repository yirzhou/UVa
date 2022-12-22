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

int n, l, c;
vi T;

vector<vector<ii>> memo;

int di(int t)
{
    return t == 0 ? 0 : (t >= 1 && t <= 10 ? -c : (t - 10) * (t - 10));
}

void update1(ii& res, int& minlect, int& minDI, int DI)
{
    if (res.fi < minlect)
        minlect = res.fi, minDI = DI + res.se;
    else if (res.fi == minlect)
        minDI = min(minDI, DI + res.se);
}

void update2(ii& res, int& minlect, int& minDI, int DI)
{
    if (1 + res.fi < minlect)
        minlect = 1 + res.fi, minDI = DI + res.se;
    else if (1 + res.fi == minlect)
        minDI = min(minDI, DI + res.se);
}

ii dp(int i, int curt)
{
    if (memo[i][curt].fi != -1)
        return memo[i][curt];
    if (i == n)
        return memo[i][curt] = { 0, di(curt) };

    int minlect = INT_MAX, minDI = INT_MAX;
    int tleft = curt - T[i];
    // Put into current
    if (tleft >= 0) {
        ii res = dp(i + 1, tleft);
        update1(res, minlect, minDI, 0);
    }

    // Put into a new lec
    // End the current
    int DI = di(curt);
    ii res = dp(i + 1, l - T[i]);
    update2(res, minlect, minDI, DI);

    return memo[i][curt] = { minlect, minDI };
}

int main()
{
    fastio;
    int caseno = 1;
    while (cin >> n && n) {
        T.assign(n, 0);
        memo = vector<vector<ii>>(n + 1, vector<ii>(l + 1, { -1, -1 }));
        cin >> l >> c;
        for (int i = 0; i < n; ++i)
            cin >> T[i];
        ii res = dp(0, l);
        cout << "Case " << caseno++ << ":\n";
        cout << "Minimum number of lectures: " << 1 + res.fi << endl;
        cout << "Total dissatisfaction index: " << res.se << endl;
        cout << endl;
    }

    return 0;
}
