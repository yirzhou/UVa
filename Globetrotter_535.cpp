#include <algorithm>
#include <assert.h>
#include <bitset>
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

unordered_map<string, pair<double, double>> M;

#define PI 3.141592653589793

double haversine(double x)
{
    return (1 - cos(x)) / 2.0;
}

double gc_distance(double plat, double plong, double qlat, double qlong, double radius)
{
    double dlon = qlong - plong, dlat = qlat - plat;
    double a = pow((sin(dlat / 2)), 2) + cos(plat) * cos(qlat) * pow(sin(dlon / 2), 2);
    return 2 * radius * atan2(sqrt(a), sqrt(1 - a));
}

const double radius = 6378.00;

int main()
{
    fastio;

    char u[52], v[52];
    double lat, lo;

    while (scanf("%s", u), u[0] - '#') {
        scanf("%lf %lf", &lat, &lo);
        M[u] = { lat * PI / 180.0, lo * PI / 180.0 };
    }

    while (scanf("%s %s", u, v) && u[0] != '#' && v[0] != '#') {

        cout << u << " - " << v << endl;
        if (!M.count(u) || !M.count(v)) {
            printf("Unknown\n");
            continue;
        }

        double plat = M[u].fi, plong = M[u].se, qlat = M[v].fi, qlong = M[v].se;
        double dist = gc_distance(plat, plong, qlat, qlong, radius);
        printf("%.0lf km\n", dist);
    }

    return 0;
}
