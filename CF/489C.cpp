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
typedef vector<ll> vll;
typedef vector<vi> vii;

ii D[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int memo1[105][905], memo2[105][905];
string mem1[105][905], mem2[105][905];

int M, S;

pair<int, string> dp1(int m, int s) {
    if (m == 1 && s == 0) return make_pair(1, "0");
    if (m == 0)
        return (s != 0 ? make_pair<int, string>(0, "")
                       : make_pair<int, string>(1, ""));

    if (memo1[m][s] != -1) return make_pair(memo1[m][s], mem1[m][s]);

    for (int i = (M == m ? 1 : 0); i <= min(9, s); ++i) {
        pair<int, string> res = dp1(m - 1, s - i);
        if (res.fi) {
            memo1[m][s] = 1, mem1[m][s] = to_string(i) + res.se;
            return make_pair(1, mem1[m][s]);
        };
    }

    memo1[m][s] = 0;
    return make_pair(0, "");
}

pair<int, string> dp2(int m, int s) {
    if (m == 1 && s == 0) return make_pair(1, "0");
    if (m == 0)
        return (s != 0 ? make_pair<int, string>(0, "")
                       : make_pair<int, string>(1, ""));

    if (memo2[m][s] != -1) return make_pair(memo2[m][s], mem2[m][s]);

    for (int i = min(9, s); i >= (M == m ? 1 : 0); --i) {
        pair<int, string> res = dp2(m - 1, s - i);
        if (res.fi) {
            memo2[m][s] = 1, mem2[m][s] = to_string(i) + res.se;
            return make_pair(1, mem2[m][s]);
        }
    }
    memo2[m][s] = 0;
    return make_pair(0, "");
}

int main() {
    fastio;

    int m, s;
    cin >> m >> s;
    M = m, S = s;
    memset(memo1, -1, sizeof memo1), memset(memo2, -1, sizeof memo2);
    pair<int, string> r1 = dp1(m, s);
    if (!r1.first) pii(-1, -1);
    else cout << r1.second << " " << dp2(m, s).second << endl;
    return 0;
}
