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

/*
We have two arrays arr1 and arr2 which are initially empty. You need to add
positive integers to them such that they satisfy all the following conditions:

1) arr1 contains uniqueCnt1 distinct positive integers, each of which is not
divisible by divisor1. 2) arr2 contains uniqueCnt2 distinct positive integers,
each of which is not divisible by divisor2. 3) No integer is present in both
arr1 and arr2.

Given divisor1, divisor2, uniqueCnt1, and uniqueCnt2, return the minimum
possible maximum integer that can be present in either array.

- 2 <= divisor1, divisor2 <= 10^5
- 1 <= uniqueCnt1, uniqueCnt2 < 10^9
- 2 <= uniqueCnt1 + uniqueCnt2 <= 10^9
*/

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return (ll)a * (ll)(b / gcd(a, b)); }

class Solution {
  public:
    ll LCM, total;
    ll div1, div2, u1, u2;
    int good(ll val) {
        return val - val / div1 >= u1 && val - val / div2 >= u2 &&
               val - val / LCM >= total;
    }
    // my idea: check # numbers between each two LCM's.
    int minimizeSet(int d1, int d2, int u1, int u2) {
        div1 = d1, div2 = d2;
        this->u1 = u1, this->u2 = u2;
        LCM = lcm((ll)d1, (ll)d2);
        total = u1 + u2;

        ll lo = 1, hi = 1e10;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            if (good(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
