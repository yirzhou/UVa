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

int n;
int G[20][20];

ll memo1[25][1 << 15], memo2[25][1 << 15][2];

ll dp1(int i, int mask)
{
    if (i == n)
        return 1;
    if (memo1[i][mask] != -1)
        return memo1[i][mask];
    ll ans = 0;
    for (int j = 0; j < n; ++j) {
        if (G[i][j] == 1 && (((mask >> j) & 1) == 0))
            ans += dp1(i + 1, mask | (1 << j));
    }

    return memo1[i][mask] = ans;
}

ll dp2(int i, int mask, bool has2)
{
    if (i == n)
        return has2 ? 1 : 0;

    if (memo2[i][mask][has2] != -1)
        return memo2[i][mask][has2];

    ll ans = 0;

    for (int j = 0; j < n; ++j)
        if (((mask >> j) & 1) == 0)
            ans += dp2(i + 1, mask | (1 << j), has2 | (G[i][j] == 2));

    return memo2[i][mask][has2] = ans;
}

int main()
{
    fastio;

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case " << t << ": ";
        cin >> n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> G[i][j];

        memset(memo1, -1, sizeof memo1);
        memset(memo2, -1, sizeof memo2);
        ll ans = dp1(0, 0) + dp2(0, 0, false);
        cout << ans << endl;
    }

    return 0;
}
