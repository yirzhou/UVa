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
typedef vector<vll> vvl;
typedef vector<vi> vvi;

class Solution {
public:
    string smallestSubsequence(string s, int k, char l, int r)
    {
        stack<char> ST;
        int n = s.size(), cnt = 0;
        vi pre(n, 0);
        pre[n - 1] = s.back() == l;
        for (int i = n - 2; i >= 0; --i)
            pre[i] = pre[i + 1] + (s[i] == l);

        string res;

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            // If we can potentially pop the top element because we have found a smaller letter:
            // 1. If the top is `letter`, pop it off if we will have enough `letter`s later
            // 2. If it is not `letter`, pop it off if we have enough letter later.
            while (ST.size() && c < ST.top()) {
                if (ST.top() == l) {
                    if ((cnt > r || pre[i] >= r - cnt + 1) && n - i > k - ST.size())
                        ST.pop(), cnt--;
                    else
                        break;
                } else if (n - i > k - ST.size())
                    ST.pop();
                else
                    break;
            }

            // Deciding if we should push
            // 1) c != l: only push if we have enough space for `letter` after pushing it.
            // 2) c == l: push it if we haven't reached r.
            if (c != l && k - ST.size() > max(r - cnt, 0)) {
                ST.push(c);
            } else if (c == l && ST.size() < k) {
                ST.push(c);
                cnt++;
            }
        }

        while (ST.size())
            res += ST.top(), ST.pop();
        reverse(ALL(res));
        return res;
    }
};

// int main()
// {
//     string s;
//     int k, r, t;
//     char l;
//     cin >> t;
//     while (t--) {
//         cin >> s >> k >> l >> r;
//         Solution sol;
//         cout << sol.smallestSubsequence(s, k, l, r) << endl;
//     }
// }

/*
You are given a string s, an integer k, a letter letter, and an integer repetition.

Return the lexicographically smallest subsequence of s of length k that has the letter letter appear at least repetition times. The test cases are generated so that the letter appears in s at least repetition times.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

A string a is lexicographically smaller than a string b if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b.

Input: s = "leet", k = 3, letter = "e", repetition = 1
Output: "eet"
Explanation: There are four subsequences of length 3 that have the letter 'e' appear at least 1 time:
- "lee" (from "leet")
- "let" (from "leet")
- "let" (from "leet")
- "eet" (from "leet")
The lexicographically smallest subsequence among them is "eet".

- 1 <= repetition <= k <= s.length <= 5 * 1e4
- s consists of lowercase English letters.
- letter is a lowercase English letter, and appears in s at least repetition times.
*/
