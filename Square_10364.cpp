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

int n, m, len;
vi A;

int dp[(1 << 20)][4];

bool f(int mask, int buckets, int curlen)
{
    if (dp[mask][buckets] != -1)
        return dp[mask][buckets];
    if (mask == (1 << m) - 1)
        return dp[mask][buckets] = buckets == 0;

    for (int i = 0; i < m; ++i) {
        if ((mask >> i) & 1)
            continue;

        if (curlen - A[i] >= 0) {
            bool res = curlen - A[i] == 0 ? f(mask | (1 << i), buckets - 1, len) : f(mask | (1 << i), buckets, curlen - A[i]);
            if (res)
                return dp[mask][buckets] = true;
        }
    }

    return dp[mask][buckets] = false;
}

int main()
{
    fastio;
    cin >> n;
    while (n--) {
        cin >> m;
        A.assign(m, 0);
        memset(dp, -1, sizeof dp);
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            cin >> A[i];
            sum += A[i];
        }
        len = sum / 4;
        if (sum % 4) {
            cout << "no\n";
            continue;
        }

        cout << (f(0, 4, len) ? "yes" : "no") << endl;
    }
    return 0;
}
