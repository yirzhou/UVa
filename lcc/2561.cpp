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
    long long minCost(vector<int> &b1, vector<int> &b2) {
        unordered_map<int, int> mp1, mp2, mp;
        int minval = INT_MAX;
        for (auto &num : b1) mp1[num]++, mp[num]++, minval = min(minval, num);
        for (auto &num : b2) mp2[num]++, mp[num]++, minval = min(minval, num);

        vi lack, more;
        for (auto &[num, f] : mp) {
            if (f % 2 != 0) return -1;
            if (mp1[num] < f / 2)
                for (int i = 0; i < f / 2 - mp1[num]; ++i) lack.pb(num);

            if (mp1[num] > f / 2)
                for (int i = 0; i < mp1[num] - f / 2; ++i) more.pb(num);
        }

        ll ans = 0;
        sort(ALL(lack)), sort(ALL(more));
        assert(lack.size() == more.size());
        int m = lack.size();
        for (int i = 0; i < m; ++i) {
            int small = min(lack[i], more[m - i - 1]);
            ans += min(2 * minval, small);
        }
        return ans;
    }
};
