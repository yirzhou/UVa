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
Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
Output: [3,3,4]
Explanation:
- 1st query updates s = "bbbacc". The longest substring consisting of one repeating character is "bbb" with length 3.
- 2nd query updates s = "bbbccc".
  The longest substring consisting of one repeating character can be "bbb" or "ccc" with length 3.
- 3rd query updates s = "bbbbcc". The longest substring consisting of one repeating character is "bbbb" with length 4.
Thus, we return [3,3,4].
*/

struct node {
    char lc, rc;
    int pref = 0, suf = 0, longest = 0, sz = 1;
    void merge(node& l, node& r)
    {
        longest = max(l.longest, r.longest);
        if (l.rc == r.lc)
            longest = max(longest, l.suf + r.pref);
        sz = l.sz + r.sz;
        lc = l.lc, rc = r.rc;
        pref = l.pref + (l.pref == l.sz && l.lc == r.lc ? r.pref : 0);
        suf = r.suf + (r.suf == r.sz && l.rc == r.rc ? l.suf : 0);
    }
};

class Solution {
public:
    int update(vector<node>& st, int pos, char c, int i, int l, int r)
    {
        if (l <= pos && pos <= r) {
            if (l != r) {
                int m = (l + r) / 2, li = 2 * i + 1, ri = 2 * i + 2;
                update(st, pos, c, li, l, m);
                update(st, pos, c, ri, m + 1, r);
                st[i].merge(st[li], st[ri]);
            } else {
                st[i].lc = st[i].rc = c;
                st[i].pref = st[i].suf = st[i].longest = 1;
            }
        }

        return st[i].longest;
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices)
    {
        vi ans;
        int p = 1, sz = s.size();
        while (p < sz)
            p <<= 1;
        vector<node> st(p * 2);
        for (int i = 0; i < sz; ++i)
            update(st, i, s[i], 0, 0, p - 1);
        for (int i = 0; i < queryIndices.size(); ++i)
            ans.pb(update(st, queryIndices[i], queryCharacters[i], 0, 0, p - 1));
        return ans;
    }
};
