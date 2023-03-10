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

struct cmp {
    bool operator()(const vl &a, const vl &b) { return a[0] < b[0]; }
};

int main() {
    fastio;
    int n, k;
    ll t, a, b;
    cin >> n >> k;
    vl alice, bob, all;
    for (int i = 0; i < n; ++i) {
        cin >> t >> a >> b;
        if (!a && !b) continue;
        if (a && !b) alice.pb(t);
        else if (!a && b) bob.pb(t);
        else if (a && b) all.pb(t);
    }
    sort(ALL(alice)), sort(ALL(bob)), sort(ALL(all));
    ll res = LLONG_MAX;
    vl pre_a(alice.size() + 1, 0), pre_b(bob.size() + 1, 0),
        pre_all(all.size() + 1, 0);
    for (int i = 1; i <= all.size(); ++i)
        pre_all[i] = pre_all[i - 1] + all[i - 1];
    for (int i = 1; i <= alice.size(); ++i)
        pre_a[i] = pre_a[i - 1] + alice[i - 1];
    for (int i = 1; i <= bob.size(); ++i) pre_b[i] = pre_b[i - 1] + bob[i - 1];

    for (int len = 0; len <= k && len < pre_all.size(); ++len) {
        int need = k - len;

        if (pre_a.size() > need && pre_b.size() > need)
            res = min(res, pre_all[len] + pre_a[need] + pre_b[need]);
    }

    cout << (res == LLONG_MAX ? -1LL : res) << endl;

    return 0;
}
