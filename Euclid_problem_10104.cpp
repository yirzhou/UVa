#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
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
    ll X, Y;
    while (cin >> X >> Y) {
        extended_euclid(X, Y);
        cout << x << " " << y << " " << d << endl;
    }
}