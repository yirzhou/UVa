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

/*
For two strings s and t, we say "t divides s" if and only if s = t + ... + t
(i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides
both str1 and str2.

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"

Input: str1 = "LEET", str2 = "CODE"
Output: ""
*/
class Solution {
  public:
    bool match(string &s, int len, int i) {
        for (int j = i; j < i + len; ++j)
            if (s[j] != s[j - len])
                return 0;
        return 1;
    }

    bool check(string &s, int len) {
        if (s.size() % len != 0)
            return 0;
        for (int i = len; i < s.size() - len + 1; i += len) {
            if (!match(s, len, i))
                return 0;
        }

        return 1;
    }

    bool same(string &s1, string &s2, int len) {
        for (int i = 0; i < len; ++i)
            if (s1[i] != s2[i])
                return 0;

        return 1;
    }

    bool check2(string &longer, string &shorter, int len) {
        if (longer.size() % len != 0)
            return 0;
        if (!same(longer, shorter, len))
            return 0;
        return check(longer, len);
    }

    string gcdOfStrings(string str1, string str2) {
        string shorter = (str1.size() < str2.size() ? str1 : str2),
               longer = (str1.size() < str2.size() ? str2 : str1);
        string ans;
        for (int len = shorter.size(); len > 0; --len) {
            if (check(shorter, len) && check2(longer, shorter, len)) {
                ans = shorter.substr(0, len);
                break;
            }
        }

        return ans;
    }
};
