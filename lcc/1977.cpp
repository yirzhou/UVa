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

ll memo[3505][3505];

ll mem1[3505][3505], mem2[3505][3505];
class Solution {
  public:
    const ll MOD = (1e9) + 7;

    ll dp(string &s, int i, int j) {

        if (s[i] == '0')
            return 0;

        if (j == s.size() - 1)
            return 1;
        if (memo[i][j] != -1)
            return memo[i][j];
        ll ans = 0;

        int len = j - i + 1, first = j + 1;
        if (first < s.size() && s[first] == '0')
            return 0;

        for (int last = first + len - 1; last < s.size(); ++last) {
            int sz = last - first + 1;
            if (sz == len) {
                if (memcmp(&s[i], &s[first], sz) <= 0)
                    ans = (ans + dp(s, first, last)) % MOD;
            } else {
                ans = (ans + dp(s, first, last)) % MOD;
            }
        }

        return memo[i][j] = ans;
    }

    int numberOfCombinations(string &s) {
        memset(mem1, 0, sizeof mem1);
        memset(mem2, 0, sizeof mem2);
        ll ans = 0, n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0')
                continue;
            for (int j = n - 1, sum = 0; j >= i; --j) {
                if (j == n - 1) {
                    mem1[i][j] = 1;
                } else {
                    int first = j + 1, len = j - i + 1, last = first + len;
                    if (last <= n && memcmp(&s[i], &s[first], len) <= 0)
                        mem1[i][j] = (mem1[i][j] + mem1[first][last - 1]) % MOD;
                    if (last < n)
                        mem1[i][j] = (mem1[i][j] + mem2[first][last]) % MOD;
                }

                mem2[i][j] = sum = (sum + mem1[i][j]) % MOD;
            }
        }

        return mem2[0][0];
    }
};

// int main() {
//     vector<string> S = {
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "1111111111111111111111111111111111111111111111111111111111111111111111"
//         "111111111111111111111111111111111111111111111111111111111111111111111"
//         "1"};
//     for (auto &s : S)
//         cout << s << ": " << Solution().numberOfCombinations(s) << endl;
// }
