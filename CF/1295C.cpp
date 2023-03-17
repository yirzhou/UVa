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

ii D[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

string s, t;

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        s.clear(), t.clear();
        cin >> s >> t;
        int n = s.size();
        vvi pre(n + 1, vi(26, n + 1));
        for (int i = n - 1; i >= 0; --i) {
            char c = s[i];
            for (int j = 0; j < 26; ++j) pre[i][j] = pre[i + 1][j];
            pre[i][c - 'a'] = i + 1;
        }

        bool possible = true;
        for (auto &c : t)
            if (pre[0][c - 'a'] == n + 1) {
                possible = false;
                break;
            }

        if (!possible) {
            cout << -1 << endl;
            continue;
        }

        int ans = 1;
        int i = 0, j = 0;
        while (i < t.size()) {
            while (i < t.size() && pre[j][t[i] - 'a'] != n + 1)
                j = pre[j][t[i++] - 'a'];

            if (i == t.size()) break;
            ans++, j = 0;
        }

        cout << ans << endl;
    }
    return 0;
}
