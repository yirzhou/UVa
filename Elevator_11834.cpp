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

bool solve(double r1, double r2, double W, double H)
{
    if (2 * r1 > W || 2 * r1 > H || 2 * r2 > W || 2 * r2 > H)
        return false;

    return sqrt(pow(W - r1 - r2, 2.0) + pow(H - r1 - r2, 2.0)) >= r1 + r2;
}

int main()
{
    fastio;
    double l, c, r1, r2;
    while (cin >> l >> c >> r1 >> r2 && (l || c || r1 || r2)) {
        if (solve(r1, r2, l, c))
            cout << "S\n";
        else
            cout << "N\n";
    }
}