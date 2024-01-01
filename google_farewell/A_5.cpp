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
#define fastio                                                                                                         \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(0)
#define precision(a)                                                                                                   \
    cout << fixed;                                                                                                     \
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

unordered_map<char, int> mp = {{'P', 1}, {'R', 2}, {'S', 3}};
ll T;
string C;
vi nums;

ll dp(int init, int pre, int i)
{
    if (i == nums.size()) return 0;
    int j = (i + 1);
    int nxt = (j == nums.size() ? init : nums[j]);

    int c = nums[i];
    ll ans = 1005;
    for (int k = 1; k < 4; ++k)
        if (k != pre && k != nxt) ans = min(ans, (k == c ? 0 : 1) + dp(init, k, i + 1));
    return ans;
}

int main()
{
    fastio;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> C;
        nums.assign(C.size(), 0);
        for (int i = 0; i < C.size(); ++i) { nums[i] = mp[C[i]]; }
        ll ans = 1005;
        for (int init = 1; init < 4; ++init)
        {
            if (init != nums.back()) { ans = min(ans, (init == nums[0] ? 0 : 1) + dp(init, init, 1)); }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
