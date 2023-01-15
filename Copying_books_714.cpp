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

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define pll(a, b) printf("%lld %lld\n", a, b)
#define plll(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
#define precision(a) \
    cout << fixed;   \
    cout.precision(a)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vi> vii;

ii D[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

ll A[505];

ll f(ll t, int k, int m)
{

    ll cap = t, mw = 0, i = 0;
    for (; i < m && k >= 0; ++i) {
        if (cap >= A[i])
            cap -= A[i];
        else
            mw = max(mw, t - cap), cap = t, cap -= A[i], k--;
    }
    mw = max(mw, t - cap);
    if (i < m || k <= 0)
        return -1;
    return mw;
}

void solve(vector<vll>& res, ll t, int m, int k)
{
    ll cap = t;

    for (int i = m - 1; i >= 0; --i) {
        if (!(cap - A[i] >= 0 && i >= k - 1))
            k--, cap = t;
        cap -= A[i], res[k - 1].pb(A[i]);
    }

    for (auto& l : res)
        reverse(ALL(l));
}

void print(vector<vll>& res)
{
    for (auto& num : res[0])
        cout << num << " ";
    for (int i = 1; i < res.size() - 1; ++i) {
        cout << "/ ";
        for (auto& num : res[i])
            cout << num << " ";
    }

    cout << "/ ";
    for (int i = 0; i < res.back().size(); ++i) {
        cout << res.back()[i];
        if (i != res.back().size() - 1)
            cout << " ";
    }

    cout << endl;
}

int main()
{
    fastio;

    int n, m, k;
    cin >> n;
    while (n--) {
        cin >> m >> k;
        ll lo = 0, hi = LLONG_MAX;
        for (int i = 0; i < m; ++i)
            cin >> A[i], lo = max(lo, A[i]);
        ll ans = 0;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            ll res = f(mid, k, m);
            if (res == -1)
                lo = mid + 1;
            else {
                ans = res, hi = mid;
            }
        }
        vector<vll> res(k, vll());
        solve(res, ans, m, k);
        print(res);
    }

    return 0;
}
