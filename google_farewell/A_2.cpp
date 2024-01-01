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

ll T, M, R, N;

bool cmp(vl &a, ll b)
{
    return a[0] < b;
}

int main()
{
    fastio;

    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> M >> R >> N;
        ll num;
        vvl intervals;
        for (int i = 0; i < N; ++i)
        {
            cin >> num;
            intervals.pb({max(0LL, num - R), min(M, num + R)});
        }
        sort(ALL(intervals), [](const auto &a, const auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        bool good = true;
        ll ans = 0LL, covered = 0;

        for (int i = 0; i < N && good; ++i)
        {
            ll l = intervals[i][0], r = intervals[i][1];
            if (covered >= M) break;
            if (r <= covered) continue;
            if (l <= covered)
            {
                ll max_r = -1;
                int max_id;
                for (int j = i; (j < N) && (intervals[j][0] <= covered); ++j)
                {
                    if (intervals[j][1] > max_r)
                    {
                        max_r = intervals[j][1];
                        max_id = j;
                    }
                }
                ++ans;
                covered = max_r;
                i = max_id;
            }
            else { good = false; }
        }
        cout << "Case #" << t << ": ";
        (!good || covered < M) ? (cout << "IMPOSSIBLE") : (cout << ans);
        cout << endl;
    }
    return 0;
}
