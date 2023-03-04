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

vl nums, pre;
ll memo[200005][2];

ll dp(int i, int started) {
    if (i >= nums.size()) return 0;
    if (i == nums.size() - 1) return (i % 2 == 0) * nums[i];
    if (memo[i][started] != -1) return memo[i][started];
    ll ans = 0;
    if (i % 2 == 0) {
        if (!started)
            ans = max(nums[i] + dp(i + 1, 0), nums[i + 1] + dp(i + 2, 1));
        else ans = max(nums[i + 1] + dp(i + 2, 1), pre.back() - pre[i - 1]);
    } else {
        if (!started) ans = max(nums[i] + dp(i + 2, 1), dp(i + 1, 0));
        else ans = max(nums[i] + dp(i + 2, 1), pre.back() - pre[i]);
    }

    return memo[i][started] = ans;
}

int main() {
    fastio;
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        nums.assign(n, 0), pre.assign(n + 1, 0);
        for (int i = 0; i < n; ++i) cin >> nums[i];
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1];
            if (i % 2 == 1) pre[i] += nums[i - 1];
        }
        memset(memo, -1, sizeof memo);
        cout << dp(0, 0) << endl;
    }

    return 0;
}
