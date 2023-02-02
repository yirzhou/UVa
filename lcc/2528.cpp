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

class Solution {
  public:
    int good(vi &stations, ll min_power, int r, int k) {
        ll sum = accumulate(stations.begin(), stations.begin() + r, 0LL);
        vi A = stations;
        int n = A.size(), l = 0;
        for (int i = 0; i < n; ++i) {
            if (i + r < n) sum += A[i + r];
            if (sum < min_power) {
                ll need = min_power - sum;
                if (need > k) return 0;
                k -= need, A[min(n - 1, i + r)] += need, sum += need;
            }
            if (i - l == r) sum -= A[l++];
        }
        return 1;
    }
    long long maxPower(vector<int> &stations, int r, int k) {
        ll lo = 0, hi = accumulate(ALL(stations), 0LL) + k + 1;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            if (good(stations, mid, r, k)) lo = mid + 1;
            else hi = mid;
        }
        return lo - 1;
    }
};
