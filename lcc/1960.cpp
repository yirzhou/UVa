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
    vector<ll> manacher_odd(string s) {
        ll n = s.size();
        s = "$" + s + "^";
        vector<ll> p(n + 2);
        ll l = 1, r = 1;
        for (ll i = 1; i <= n; i++) {
            p[i] = max(0LL, min(r - i, p[l + (r - i)]));
            while (s[i - p[i]] == s[i + p[i]]) {
                p[i]++;
            }
            if (i + p[i] > r) {
                l = i - p[i], r = i + p[i];
            }
        }
        return vector<ll>(begin(p) + 1, end(p) - 1);
    }

    // right-to-left & left-to-right
    vl mem1, mem2;
    long long maxProduct(string &s) {
        int n = s.size();
        vl d_odd = manacher_odd(s);

        mem1.assign(n, 1), mem2.assign(n, 1);

        for (int i = 0; i < n; ++i) {
            ll len = d_odd[i] * 2 - 1;
            ll lo = i - (d_odd[i] - 1), hi = i + (d_odd[i] - 1);
            mem1[lo] = max(mem1[lo], len);
            mem2[hi] = max(mem2[hi], len);
        }

        for (int i = 1; i < n; ++i)
            mem1[i] = max(mem1[i], mem1[i - 1] - 2);
        for (int i = n - 2; i >= 0; --i)
            mem2[i] = max(mem2[i], mem2[i + 1] - 2);

        for (int i = n - 2; i >= 0; --i)
            mem1[i] = max(mem1[i], mem1[i + 1]);
        for (int i = 1; i < n; ++i)
            mem2[i] = max(mem2[i], mem2[i - 1]);

        ll ans = 0;
        for (int i = 0; i + 1 < n; ++i)
            ans = max(ans, mem2[i] * mem1[i + 1]);

        return ans;
    }
};
