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

class Solution {
  public:
    struct cmp {
        bool operator()(const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        }
    };
    int findMaximizedCapital(int k, int w, vector<int> &profits,
                             vector<int> &capital) {
        vector<vector<int>> A;
        int n = profits.size();
        for (int i = 0; i < n; ++i) A.push_back({capital[i], profits[i]});
        sort(A.begin(), A.end());
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

        int i = 0;
        while (i < n && k && A[i][0] <= w) {
            while (i < n && A[i][0] <= w) pq.push(A[i++]);
            w += pq.top()[1];
            pq.pop();
            k--;
        }

        while (k-- && pq.size()) {
            while (i < n && A[i][0] <= w) pq.push(A[i++]);
            w += pq.top()[1];
            pq.pop();
        }

        return w;
    }
};
