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
You are given an array of positive integers price where price[i] denotes the
price of the ith candy and a positive integer k.

The store sells baskets of k distinct candies. The tastiness of a candy basket
is the smallest absolute difference of the prices of any two candies in the
basket.

Return the maximum tastiness of a candy basket.
*/
class Solution {
  public:
    int good(vi &price, int k, int mid) {
        int nxt = price[0] + mid;
        for (int i = 1; i < price.size(); ++i) {
            if (price[i] >= nxt) nxt = price[i] + mid, k--;
            if (k == 1) return 1;
        }

        return 0;
    }
    int maximumTastiness(vector<int> &price, int k) {
        sort(ALL(price));
        int lo = 0, hi = price.back() - price.front() + 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (good(price, k, mid)) lo = mid + 1;
            else hi = mid;
        }

        return lo - 1;
    }
};
