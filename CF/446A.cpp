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

ll n;
ll nums[100005], mem1[100005], mem2[100005];

ll dp1(int i) {
    if (i == n - 1) return mem1[i] = 1LL;
    if (mem1[i] != 0) return mem1[i];
    ll ans = 1;
    if (nums[i + 1] > nums[i]) ans += dp1(i + 1);
    return mem1[i] = ans;
}

ll dp2(int i) {
    if (i == 0) return mem2[i] = 1LL;
    if (mem2[i] != 0) return mem2[i];
    ll ans = 1;
    if (nums[i - 1] < nums[i]) ans += dp2(i - 1);
    return mem2[i] = ans;
}

int main() {
    fastio;

    cin >> n;
    for (ll i = 0; i < n; ++i) cin >> nums[i];

    memset(mem1, 0, sizeof mem1);
    memset(mem2, 0, sizeof mem2);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll l1 = dp1(i), l2 = dp2(i);
        ans = max(ans, max(l1, l2));
    }

    for (int i = 0; i < n; ++i) {
        ans = max(ans, 1 + mem1[i + 1]);
        if (i - 1 >= 0) ans = max(ans, 1 + mem2[i - 1]);
        if (nums[i - 1] + 1 < nums[i + 1])
            ans = max(ans, mem2[i - 1] + 1 + mem1[i + 1]);
    }

    cout << ans << endl;

    return 0;
}
