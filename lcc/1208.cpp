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
    vi costs;
    int good(int maxCost, int len) {
        int i = 0, s = 0;
        for (int j = 0; j < costs.size(); ++j) {
            s += costs[j];
            while (s > maxCost) s -= costs[i++];
            if (j - i + 1 >= len) return 1;
        }
        return 0;
    }
    int equalSubstring(string &s, string &t, int maxCost) {
        costs = vi(s.size());
        for (int i = 0; i < s.size(); ++i) costs[i] = abs(s[i] - t[i]);
        int lo = 1, hi = s.size() + 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (good(maxCost, mid)) lo = mid + 1;
            else hi = mid;
        }

        return lo - 1;
    }
};
