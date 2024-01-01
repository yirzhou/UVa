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

int n, l, r, s, t;
vi S;
int low(int k) { return k * (k + 1) / 2; }

int high(int n, int k) { return k * (2 * n + 1 - k) / 2; }

bool solve() {
    int k = r - l + 1;
    S.clear();
    for (int i = n; i >= 1 && k > 0; --i) {
        if (high(i, k) >= s && s - i >= low(k - 1)) {
            S.pb(i);
            s -= i;
            k--;
        }
    }
    return S.size() == r - l + 1;
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n >> l >> r >> s;
        bool res = solve();
        if (!res) {
            cout << -1;
        } else {
            vi ans(n);
            bool V[505] = {0};
            for (int i = l; i <= r; ++i) {
                ans[i - 1] = S[i - l];
                V[S[i - l]] = 1;
            }
            int num = 1;
            for (int i = 0; i < l - 1; ++i) {
                while (V[num]) { num++; }
                ans[i] = num;
                V[num++] = 1;
            }
            num = 1;
            for (int i = r; i < n; ++i) {
                while (V[num]) { num++; }
                ans[i] = num;
                V[num++] = 1;
            }

            cout << ans[0];
            for (int i = 1; i < ans.size(); ++i) cout << " " << ans[i];
        }
        cout << endl;
    }
}
