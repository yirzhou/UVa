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

ii D[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

ll nums[200005];
ll t, n, k;

ll f1() {
    ll extra = k * (k - 1) / 2, maxval = 0L, sum = 0L;
    int i = 0, j = 0;
    for (; j < n; ++j) {
        ll num = nums[j];
        sum += num;
        if (j - i + 1 > k) { sum -= nums[i++]; }
        maxval = max(maxval, sum);
    }
    return maxval + extra;
}

ll f2() {
    ll ans = 0;
    for (int i = 0; i < n; ++i) ans += nums[i];
    ans += (k - n + k - 1) * n / 2;
    return ans;
}

int main() {
    fastio;

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) cin >> nums[i];
        ll ans = k <= n ? f1() : f2();
        cout << ans << endl;
    }
}
