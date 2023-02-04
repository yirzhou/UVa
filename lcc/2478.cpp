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
You are given a string s that consists of the digits '1' to '9' and two integers
k and minLength.

A partition of s is called beautiful if:

s is partitioned into k non-intersecting substrings.
Each substring has a length of at least minLength.
Each substring starts with a prime digit and ends with a non-prime digit. Prime
digits are '2', '3', '5', and '7', and the rest of the digits are non-prime.
Return the number of beautiful partitions of s. Since the answer may be very
large, return it modulo 10^9 + 7.

A substring is a contiguous sequence of characters within a string.

Input: s = "23542185131", k = 3, minLength = 2
Output: 3
Explanation: There exists three ways to create a beautiful partition:
"2354 | 218 | 5131"
"2354 | 21851 | 31"
"2354218 | 51 | 31"

- 1 <= k, minLength <= s.length <= 1000
- s consists of the digits '1' to '9'.
*/

ll memo[1005][1005];

class Solution {
  public:
    int is_prime(char c) {
        int num = c - '0';
        return num == 2 || num == 3 || num == 5 || num == 7;
    }

    ll dp(string &s, int i, int k) {
        if (i == n) return k == 0;
        if (k < 0 || n - i < minlen) return 0;
        if (memo[i][k] != -1) return memo[i][k];
        ll ans = 0;

        auto iter = lower_bound(ALL(pre), i + minlen);
        if (iter == pre.end()) return 0;
        for (int j = iter - pre.begin(); j < pre.size(); ++j)
            ans = (ans + dp(s, pre[j], k - 1)) % MOD;

        return memo[i][k] = ans;
    }

    vi pre;
    int n, minlen;
    int beautifulPartitions(string s, int k, int minLength) {
        if (is_prime(s.back()) || !is_prime(s[0])) return 0;
        minlen = minLength;
        n = s.size();
        for (int i = 1; i < n; ++i)
            if (is_prime(s[i]) && !is_prime(s[i - 1])) pre.pb(i);
        pre.pb(n);
        memset(memo, -1, sizeof memo);
        return dp(s, 0, k);
    }
};
