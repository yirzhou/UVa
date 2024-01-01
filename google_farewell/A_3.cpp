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

ll T, N;

int main()
{
    fastio;
    cin >> T;
    vl nums;
    for (int t = 1; t <= T; ++t)
    {
        cin >> N;
        nums.assign(N, 0);
        unordered_map<ll, ll> mp;
        for (int i = 0; i < N; ++i) { cin >> nums[i]; }
        ll pcolor = 0LL;
        bool good = true;
        for (int i = 0; i < N; ++i)
        {
            ll cur = nums[i];
            if (!mp.count(cur))
            {
                pcolor++;
                mp[cur] = pcolor;
            }
            else
            {
                ll curc = mp[cur];
                if (curc < pcolor)
                {
                    good = false;
                    break;
                }
                pcolor = curc;
            }
        }

        cout << "Case #" << t << ": ";
        if (!good) { cout << "IMPOSSIBLE"; }
        else
        {
            vvl colors;
            for (auto &[k, v] : mp) { colors.pb({v, k}); }
            sort(ALL(colors));
            for (int j = 0; j < colors.size(); ++j)
            {
                cout << colors[j][1];
                if (j != colors.size() - 1) { cout << " "; }
            }
        }
        cout << endl;
    }
    return 0;
}
