#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define pll(a, b) printf("%lld %lld\n", a, b)
#define pff(a, b) printf("%f %f\n", a, b)
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

ii D[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

vi order;
vector<double> a, b;
double n, lo, hi;

double f(double L)
{
    double last = a[order[0]];
    for (int i = 1; i < n; ++i) {
        double total = last + L;
        if (total <= b[order[i]]) {
            last = max(a[order[i]], total);
        } else
            return 1.0;
    }
    return last - b[order[n - 1]];
}

int main()
{
    fastio;
    int caseno = 1;
    while (cin >> n && n) {
        order.assign(n, 0);
        a.assign(n, 0.0);
        b.assign(n, 0.0);
        for (int i = 0; i < n; ++i) {
            cin >> lo >> hi;
            order[i] = i, a[i] = lo * 60, b[i] = hi * 60;
        }

        double maxL = -1.0;
        do {
            double l = 0, h = 86400, L = -1;
            while (fabs(l - h) >= 1e-3) {
                L = (l + h) / 2.0;
                double ret = f(L);
                if (ret <= 0)
                    l = L;
                else
                    h = L;
            }

            maxL = max(maxL, L);

        } while (next_permutation(order.begin(), order.end()));

        maxL = (int)(maxL + 0.5);
        printf("Case %d: %d:%0.2d\n", caseno++, (int)(maxL / 60), (int)maxL % 60);
    }

    return 0;
}