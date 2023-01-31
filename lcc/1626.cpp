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
#define fastio                                                                 \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(0)
#define precision(a)                                                           \
    cout << fixed;                                                             \
    cout.precision(a)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;

/*
Input: scores = [4,5,6,5], ages = [2,1,2,1]
Output: 16
Explanation: It is best to choose the last 3 players. Notice that you are
allowed to choose multiple people of the same age.

- 1 <= scores.length, ages.length <= 1000
- scores.length == ages.length
- 1 <= scores[i] <= 1e6
- 1 <= ages[i] <= 1000
*/

int memo[1005][1005];

class Solution {
  public:
    vector<ii> A;
    int n;

    int dp(int prev, int i) {
        if (i == n + 1)
            return 0;
        if (memo[prev][i] != -1)
            return memo[prev][i];
        int ans = 0, page = A[prev].fi, ps = A[prev].se, cage = A[i].fi,
            cs = A[i].se;

        if (cage == page)
            ans = max(ans, max(cs + dp(i, i + 1), dp(prev, i + 1)));
        else
            ans = max(ans,
                      max((cs >= ps ? cs + dp(i, i + 1) : 0), dp(prev, i + 1)));

        return memo[prev][i] = ans;
    }

    int bestTeamScore(vector<int> &scores, vector<int> &ages) {
        n = scores.size();
        A = vector<ii>(n + 1);
        A[0] = {0, 0};
        for (int i = 0; i < n; ++i)
            A[i + 1] = {ages[i], scores[i]};
        sort(ALL(A), [](const ii &a, const ii &b) {
            if (a.fi == b.fi)
                return a.se < b.se;
            return a.fi < b.fi;
        });

        memset(memo, -1, sizeof memo);

        return dp(0, 1);
    }
};
