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

ii D[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

/*
removing 1 on a cell decreases R and C by 1 at the same time.
Draw this diagonally.
*/

int main() {
    fastio;
    int n, k, t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vvi ans(n, vi(n, 0));

        vi rsum(n, 0), csum(n, 0);

        for (int col = 0; col < n && k > 0; ++col) {
            int c = col;
            for (int r = 0; r < n && k > 0; ++r) {
                rsum[r]++, csum[c % n]++;
                ans[r][c % n] = 1;
                k--, c++;
            }
        }

        int rmax = *max_element(ALL(rsum)), rmin = *min_element(ALL(rsum)),
            cmax = *max_element(ALL(csum)), cmin = *min_element(ALL(csum));

        cout << (int)pow((rmax - rmin), 2) + (int)pow((cmax - cmin), 2) << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) cout << ans[i][j];
            cout << endl;
        }
    }

    return 0;
}
