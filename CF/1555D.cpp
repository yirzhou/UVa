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

int main()
{
    fastio;
    int n, m, l, r;
    cin >> n >> m;
    vi nums(n);
    for (int i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        nums[i] = c - 'a';
    }

    vi s = {0, 1, 2};
    sort(ALL(s));
    vi ans(m, INT_MAX);
    vvi q;

    for (int i = 0; i < m; ++i)
    {
        cin >> l >> r;
        q.pb({l, r});
    }
    do {
        vi arr(n), pre(n + 1, 0);

        for (int j = 0; j < n; ++j) { arr[j] = s[j % 3] != nums[j]; }

        for (int j = 1; j <= n; ++j) pre[j] = pre[j - 1] + arr[j - 1];
        for (int i = 0; i < m; ++i) ans[i] = min(ans[i], pre[q[i][1]] - pre[q[i][0] - 1]);
    } while (next_permutation(ALL(s)));

    for (int i = 0; i < m; ++i) cout << ans[i] << endl;

    return 0;
}
