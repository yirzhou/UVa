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
vi A;

int dp[1 << 15];

int test(int mask, int i)
{
    return ((mask >> (n - i - 1)) & 1) == 0;
}

int f(int mask)
{
    if (dp[mask] != -1)
        return dp[mask];
    int ans = 0;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (test(mask, i) && test(mask, j) && test(mask, k) && A[i] + A[j] + A[k] >= 20)
                    ans = max(ans, 1 + f(mask | (1 << (n - i - 1)) | (1 << (n - j - 1)) | (1 << (n - k - 1))));
            }
        }
    }

    return dp[mask] = ans;
}

int main()
{
    fastio;

    int caseno = 1;
    while (cin >> n && n) {
        memset(dp, -1, sizeof dp);
        cout << "Case " << caseno++ << ": ";
        A.assign(n, 0);
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        sort(ALL(A));

        int res = f(0);
        cout << res << endl;
    }

    return 0;
}
