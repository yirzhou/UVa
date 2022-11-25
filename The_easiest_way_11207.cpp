#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
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

double solve(double w, double h)
{
    double a1 = pow(min((w / 4.0), h), 2.0);
    double a2 = pow(h / 2.0, 2.0);
    return max(a1, a2);
}

int main()
{
    fastio;
    int N, w, h;
    while (cin >> N && N) {
        vector<ii> v;
        while (N--)
            cin >> w >> h, v.pb({ max(w, h), min(w, h) });
        int chosen = 1;
        double max_area = solve(v[0].fi, v[0].se);
        for (int i = 1; i < v.size(); ++i) {
            double area = solve(v[i].fi, v[i].se);
            if (area > max_area) {
                max_area = area, chosen = i + 1;
            }
        }

        cout << chosen << endl;
    }
}