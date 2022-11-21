#include <bits/stdc++.h>
#include <climits>
#include <cmath>

using namespace std;

#define INF 1000000000
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)

#define pll(a, b) printf("%lld %lld\n", a, b)
#define plll(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;

ll x, y, d;
void extended_euclid(ll a, ll b)
{
    if (b == 0) {
        x = 1;
        y = 0;
        d = a;
        return;
    }

    extended_euclid(b, a % b);
    ll x1 = y, y1 = x - (a / b) * y;
    x = x1, y = y1;
}

int main()
{
    ll C, c1, n1, c2, n2;
    while (cin >> C && C) {
        cin >> c1 >> n1 >> c2 >> n2;
        extended_euclid(n1, n2);
        if (C % d != 0) {
            cout << "failed\n";
            continue;
        }
        ll t1 = (ll)ceil(-(double)x * C / n2);
        ll t2 = (ll)floor((double)y * C / n1);
        if (t2 < t1) {
            cout << "failed\n";
            continue;
        }

        ll cost1 = (C / d) * (c1 * x + c2 * y) + t1 * (c1 * n2 - c2 * n1) / d;
        ll cost2 = (C / d) * (c1 * x + c2 * y) + t2 * (c1 * n2 - c2 * n1) / d;
        ll t;
        if (cost1 < cost2)
            t = t1;
        else
            t = t2;
        ll k1 = (x * C + n2 * t) / d;
        ll k2 = (y * C - n1 * t) / d;
        cout << k1 << " " << k2 << endl;
    }
}