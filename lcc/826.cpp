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
#define MOD 1000000007

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

class Solution {
  public:
    int n;
    vvi A;
    vi M;
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit,
                            vector<int> &worker) {
        n = profit.size();
        A.assign(n, {});
        M.assign(n, 0);
        for (int i = 0; i < n; ++i) A[i] = {difficulty[i], profit[i]};
        sort(ALL(A));
        sort(ALL(worker));
        M[0] = A[0][1];
        for (int i = 1; i < n; ++i) M[i] = max(M[i - 1], A[i][1]);

        int ans = 0;
        for (auto &w : worker) {
            vi t = {w + 1, 0};
            int p = lower_bound(
                        ALL(A), t,
                        [](const vi &a, const vi &b) { return a[0] < b[0]; }) -
                    A.begin() - 1;
            if (p >= 0) ans += M[p];
        }
        return ans;
    }
};
