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
#define EPS 1e-6
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

int r, k, t, n;

double R[35], K[35];

double f(double cut)
{

    double rd = cut, cd = t - cut;
    double ans = rd / R[0] + cd / K[0];
    for (int i = 1; i < n - 1; ++i)
        ans = min(ans, rd / R[i] + cd / K[i]);

    return ans - (rd / R[n - 1] + cd / K[n - 1]);
}

int main()
{
    fastio;

    while (si(t) != EOF) {
        si(n);
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &R[i]);
            scanf("%lf", &K[i]);
        }
        double lo = 0.0, hi = t;

        while (hi - lo > EPS) {
            double m1 = lo + (hi - lo) / 3.0, m2 = hi - (hi - lo) / 3.0;
            if (f(m1) < f(m2))
                lo = m1;
            else
                hi = m2;
        }

        double res = f(hi) * 3600;
        if (res >= 0.0)
            printf("The cheater can win by %d seconds with r = %.2fkm and k = %.2fkm.\n", (int)round(res), hi, t - hi);
        else
            printf("The cheater cannot win.\n");
    }

    return 0;
}
