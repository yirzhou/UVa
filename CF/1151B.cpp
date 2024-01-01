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

#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define fastio                                                                 \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(0)
#define precision(a)                                                           \
    cout << fixed;                                                             \
    cout.precision(a)

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
#define oo INT_MAX
#define UNVISITED -1
#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;

int n, m;

ll matrix[505][505];

void print_ans(vl &ans) {
    cout << "TAK\n" << ans[0];
    for (int i = 1; i < ans.size(); ++i) cout << " " << ans[i];
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> matrix[i][j];
    }

    vl ans(n, 1);
    ll res = 0;

    for (int i = 0; i < n; ++i) {
        ll num = matrix[i][0];
        res ^= num;
    }
    if (res != 0) {
        print_ans(ans);
    } else {
        ll row = -1, col = -1;
        for (int i = 0; i < n && row == -1; ++i) {
            for (int j = 1; j < m && row == -1; ++j) {
                if ((matrix[i][j] ^ matrix[i][0]) != 0) {
                    row = i, col = j;
                    break;
                }
            }
        }
        if (row == -1) {
            cout << "NIE";
        } else {
            ans[row] = col + 1;
            print_ans(ans);
        }
    }
    cout << endl;
}
