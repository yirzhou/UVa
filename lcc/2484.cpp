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
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
#define precision(a) \
    cout << fixed;   \
    cout.precision(a)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vi> vii;

/*
Given a string of digits s, return the number of palindromic subsequences of s having length 5. Since the answer may be very large, return it modulo 1e9 + 7.

Note:

A string is palindromic if it reads the same forward and backward.
A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

Input: s = "103301"
Output: 2
Explanation:
There are 6 possible subsequences of length 5: "10330","10331","10301","10301","13301","03301".
Two of them (both equal to "10301") are palindromic.
*/

ll dp1[10005][10][10], dp2[10005][10][10];

ll pre1[10005][10], pre2[10005][10];

class Solution {
public:
    const ll MOD = 1e9 + 7;
    int n;

    // Check left
    ll dpl(string& s, int i, int d1, int d2)
    {
        if (i < 2)
            return 0;
        if (dp1[i][d1][d2] != -1)
            return dp1[i][d1][d2];
        ll ans = 0;

        if (s[i - 1] - '0' == d2)
            ans = pre1[i - 2][d1];
        ans += dpl(s, i - 1, d1, d2);

        return dp1[i][d1][d2] = ans;
    }

    // Check right
    ll dpr(string& s, int i, int d1, int d2)
    {
        if (i >= n - 2)
            return 0;
        if (dp2[i][d1][d2] != -1)
            return dp2[i][d1][d2];
        ll ans = 0;
        if (s[i + 1] - '0' == d1)
            ans = pre2[i + 2][d2];
        ans += dpr(s, i + 1, d1, d2);
        return dp2[i][d1][d2] = ans;
    }

    void preproc(string& s)
    {
        memset(pre1, 0, sizeof pre1);
        memset(pre2, 0, sizeof pre2);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                pre1[i][s[i] - '0']++;
                continue;
            }
            for (int d = 0; d < 10; ++d)
                pre1[i][d] = pre1[i - 1][d];

            pre1[i][s[i] - '0']++;
        }

        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                pre2[i][s[i] - '0']++;
                continue;
            }

            for (int d = 0; d < 10; ++d)
                pre2[i][d] = pre2[i + 1][d];

            pre2[i][s[i] - '0']++;
        }
    }

    int countPalindromes(string& s)
    {
        n = s.size();
        preproc(s);
        memset(dp1, -1, sizeof dp1);
        memset(dp2, -1, sizeof dp2);
        ll ans = 0;
        for (int i = 2; i < n - 2; ++i) {
            for (int d1 = 0; d1 < 10; ++d1) {
                for (int d2 = 0; d2 < 10; ++d2) {
                    ll left = dpl(s, i, d1, d2), right = dpr(s, i, d2, d1);
                    ans = (ans + left * right) % MOD;
                }
            }
        }
        return ans;
    }
};

int main()
{
    string s = "1203021";
    Solution sol;
    cout << sol.countPalindromes(s) << endl;
}
