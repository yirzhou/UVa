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

int main()
{
    fastio;
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vi A(n), B(n), P(m);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < n; ++i) cin >> B[i];
        for (int i = 0; i < m; ++i) cin >> P[i];
        bool good = false;
        int x = -1;

        unordered_map<int, vi> mp;

        for (int i = 0; i < n; ++i)
            if (A[i] != B[i]) mp[B[i]].pb(i);

        int last = P.back();
        if (mp.count(last))
        {
            x = mp[last].back();
            mp[last].pop_back();
            good = true;
            if (mp[last].size() == 0) mp.erase(last);
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                if (B[i] == P.back())
                {
                    x = i, good = true;
                    break;
                }
            }
        }

        if (!good)
        {
            cout << "no\n";
            continue;
        }
        vi ans(m);
        for (int i = 0; i < m; ++i)
        {
            int p = P[i];
            if (mp.count(p))
            {
                ans[i] = mp[p].back();
                A[mp[p].back()] = p;
                mp[p].pop_back();
                if (mp[p].size() == 0) mp.erase(p);
            }
            else
            {
                ans[i] = x;
                A[x] = p;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (A[i] != B[i])
            {
                good = false;
                break;
            }
        }

        if (!good) { cout << "no\n"; }
        else
        {
            cout << "yes\n";
            for (int i = 0; i < m - 1; ++i) cout << ans[i] + 1 << " ";
            cout << ans.back() + 1 << endl;
        }
    }

    return 0;
}
