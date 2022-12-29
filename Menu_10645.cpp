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

typedef pair<double, double> dd;

#define MAXN 55

int k, n, m;

int costs[MAXN], benefits[MAXN];

double dp1[25][105][MAXN][4], dp2[25][105][MAXN][4];
int trace[25][105][MAXN][4];

dd dp(int i, int budget, int p, int pcount)
{

    if (budget < 0)
        return { (double)INT_MIN, (double)INT_MAX };

    if (i == k)
        return { 0.0, 0.0 };

    if (dp1[i][budget][p][pcount] != -1)
        return { dp1[i][budget][p][pcount], dp2[i][budget][p][pcount] };

    double total_benefit = 0.0, max_benefit = (double)INT_MIN, min_cost = (double)INT_MAX, total_cost = 0;

    for (int d = 1; d <= n; ++d) {

        dd res = (d == p ? dp(i + 1, budget - costs[d], d, min(3, pcount + 1)) : dp(i + 1, budget - costs[d], d, 1));

        if (res.fi < 0.0)
            continue;

        total_benefit = (d == p && pcount >= 2) ? res.fi : (d == p && pcount == 1) ? 0.5 * (double)benefits[d] + res.fi
                                                                                   : (double)benefits[d] + res.fi;
        total_cost = costs[d] + res.se;
        if (total_benefit > max_benefit)
            max_benefit = total_benefit, min_cost = total_cost, trace[i][budget][p][pcount] = d;
        else if (total_benefit == max_benefit && total_cost < min_cost)
            min_cost = total_cost, trace[i][budget][p][pcount] = d;
    }

    return { dp1[i][budget][p][pcount] = max_benefit, dp2[i][budget][p][pcount] = min_cost };
}

int main()
{
    fastio;
    precision(1);
    while (cin >> k >> n >> m && (k || n || m)) {
        for (int i = 1; i <= n; ++i)
            cin >> costs[i] >> benefits[i];
        for (int i = 0; i < 25; ++i)
            for (int j = 0; j < 105; ++j)
                for (int l = 0; l < MAXN; ++l)
                    fill(dp1[i][j][l], dp1[i][j][l] + 4, -1.0), fill(dp2[i][j][l], dp2[i][j][l] + 4, -1.0);
        dd res = dp(0, m, 0, 0);
        if (res.fi <= 0.0)
            cout << max(res.fi, 0.0) << endl;
        else {
            cout << res.fi << endl;
            int p = 0, budget = m, pcount = 0;
            for (int i = 0; i < k; ++i) {
                int next = trace[i][budget][p][pcount];
                cout << next << " ";
                if (next == p)
                    pcount++;
                else
                    pcount = 1;
                pcount = min(pcount, 3);
                budget -= costs[next];
                p = next;
            }

            cout << endl;
        }

        cout << endl;
    }

    return 0;
}
