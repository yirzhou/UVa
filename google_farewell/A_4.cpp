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

ii D[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

ll T, N;

int f(ll target, ll guess)
{
    ll total = 26 * guess * (1 + guess) / 2;
    return total <= target;
}

int main()
{
    fastio;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> N;
        ll lo = 1, hi = 3e5;
        while (lo < hi)
        {
            ll mid = lo + (hi - lo) / 2;
            if (f(N, mid)) lo = mid + 1;
            else hi = mid;
        }

        ll rounds = lo - 1;
        ll left = N - (1 + rounds) * (rounds)*26 / 2;
        cout << "Case #" << t << ": ";
        if (left == 0) { cout << "Z"; }
        else
        {
            ll idx = left / lo, rem = left % lo;

            if (rem == 0) cout << (char)('A' + (idx - 1));
            else cout << (char)('A' + idx);
        }
        cout << endl;
    }
    return 0;
}
