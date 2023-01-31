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
There are n people standing in a queue, and they numbered from 0 to n - 1 in
left to right order. You are given an array heights of distinct integers where
heights[i] represents the height of the ith person.

A person can see another person to their right in the queue if everybody in
between is shorter than both of them. More formally, the ith person can see the
jth person if i < j and min(heights[i], heights[j]) > max(heights[i+1],
heights[i+2], ..., heights[j-1]).

Return an array answer of length n where answer[i] is the number of people the
ith person can see to their right in the queue.

Input: heights = [10,6,8,5,11,9]
Output: [3,1,2,1,1,0]
Explanation:
Person 0 can see person 1, 2, and 4.
Person 1 can see person 2.
Person 2 can see person 3 and 4.
Person 3 can see person 4.
Person 4 can see person 5.
Person 5 can see no one since nobody is to the right of them.
*/

class SegmentTree {
  private:
    int n;
    vi A, st, lazy;

    int l(int p) { return p << 1; }
    int r(int p) { return (p << 1) + 1; }

    int conquer(int a, int b) {
        if (a == -1)
            return b;
        if (b == -1)
            return a;
        return max(a, b);
    }

    void build(int p, int L, int R) {
        if (L == R)
            st[p] = A[L];
        else {
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    void propagate(int p, int L, int R) {
        if (lazy[p] != -1) {
            st[p] = lazy[p];
            if (L != R)
                lazy[l(p)] = lazy[r(p)] = lazy[p];
            else
                A[L] = lazy[p];
            lazy[p] = -1;
        }
    }

    int RMQ(int p, int L, int R, int i, int j) {
        propagate(p, L, R);
        if (i > j)
            return -1;
        if ((L >= i) && (R <= j))
            return st[p];
        int m = (L + R) / 2;
        return conquer(RMQ(l(p), L, m, i, min(m, j)),
                       RMQ(r(p), m + 1, R, max(i, m + 1), j));
    }

    void update(int p, int L, int R, int i, int j, int val) {
        propagate(p, L, R);
        if (i > j)
            return;
        if ((L >= i) && (R <= j)) {
            lazy[p] = val;
            propagate(p, L, R);
        } else {
            int m = (L + R) / 2;
            update(l(p), L, m, i, min(m, j), val);
            update(r(p), m + 1, R, max(i, m + 1), j, val);
            int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
            int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
            st[p] = (lsubtree <= rsubtree) ? st[l(p)] : st[r(p)];
        }
    }

  public:
    SegmentTree(int sz) : n(sz), st(4 * n), lazy(4 * n, -1){};

    SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
        A = initialA;
        build(1, 0, n - 1);
    }

    void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }

    int RMQ(int i, int j) { return RMQ(1, 0, n - 1, i, j); }
};

int pos[100005];

// 11 19 12 15 14 18 7 1 8 9
// 0  1  2  3  4  5  6 7 8 9
// -1 -1 1  1  3  1  5 6 5 5
// 1  10 3  5  5  10 8 8 9 10
// 1  3  1  2  1  3  2 1 1 0
class Solution {
  public:
    vector<int> canSeePersonsCount(vector<int> &heights) {
        int n = heights.size();
        for (int i = 0; i < n; ++i)
            pos[heights[i]] = i;

        vi r(n), l(n), S;
        for (int i = n - 1; i >= 0; --i) {
            int num = heights[i];
            while (S.size() && heights[S.back()] < num)
                S.pop_back();
            r[i] = (S.empty() ? n : S.back());
            S.push_back(i);
        }
        S.clear();
        for (int i = 0; i < n; ++i) {
            int num = heights[i];
            while (S.size() && heights[S.back()] < num)
                S.pop_back();
            l[i] = (S.empty() ? -1 : S.back());
            S.push_back(i);
        }
        vi ans(n, 0);
        for (int i = 0; i < n; ++i) {
            if (l[i] != -1)
                ans[l[i]]++;
            if (r[i] < n)
                ans[i]++;
        }

        return ans;
    }
};
