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

ll solve(vl &pre, ll p, ll l, ll r) {
    ll total = r - l + 1;
    if (r <= p - 1) return (total - (pre[r + 1] - pre[l]));

    ll cnt = pre[p] - pre[l] + ((r - p) / p) * pre[p] + pre[((r - p) % p) + 1];
    return total - cnt;
}

int main() {
    fastio;
    ll t, a, b, q, l, r;
    cin >> t;

    while (t--) {
        cin >> a >> b >> q;
        ll p = a * b;
        vl pre(p + 1, 0);
        for (int x = 0; x < p; ++x) {
            pre[x + 1] = pre[x];
            pre[x + 1] += (x % a) % b == (x % b) % a;
        }

        for (int i = 0; i < q; ++i) {
            cin >> l >> r;
            if (l <= p - 1) {
                cout << solve(pre, p, l, r);
            } else {
                ll lo = l % p, hi = r - l + lo;
                cout << solve(pre, p, lo, hi);
            }
            if (i < q - 1) cout << " ";
        }

        cout << endl;
    }
    return 0;
}
