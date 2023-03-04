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

int main() {
    fastio;
    int t, n, k, z;
    vl nums, pre, mp, mv;
    cin >> t;
    while (t--) {
        cin >> n >> k >> z;
        nums.assign(n, 0);
        pre.assign(n + 1, 0);
        mp.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            pre[i + 1] = pre[i] + nums[i];
        }

        mp[0] = nums[0] + nums[1];
        for (int i = 1; i < n - 1; ++i)
            mp[i] = max(mp[i - 1], nums[i] + nums[i + 1]);
        mp[n - 1] = mp[n - 2];

        ll ans = pre[k + 1];
        for (int i = 1; i <= z && k - 2 * i >= 0; ++i) {
            int hi = k - 2 * i;
            ans = max(ans, pre[hi + 1] + i * mp[hi]);
        }
        cout << ans << endl;
    }
    return 0;
}
