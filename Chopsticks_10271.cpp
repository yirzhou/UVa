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

ll A[5005];

ll memo[5005][1015];

ll dp(int cidx, int g)
{
    if (memo[cidx][g] != -1)
        return memo[cidx][g];
    if (g == 0)
        return memo[cidx][g] = 0;

    if (n - cidx < g * 3)
        return INT_MAX;

    ll diff = A[cidx] - A[cidx + 1], bad = diff * diff;
    ll ans = min(bad + dp(cidx + 2, g - 1), dp(cidx + 1, g));
    return memo[cidx][g] = ans;
}

int main()
{
    fastio;

    int T;
    cin >> T;
    while (T--) {
        cin >> k >> n;
        k += 8;
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        memset(memo, -1, sizeof memo);
        ll ans = dp(0, k);
        cout << ans << endl;
    }

    return 0;
}
