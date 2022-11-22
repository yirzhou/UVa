#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define pb push_back
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int f(ull id, ull p, ull n)
{
    if (p >= n)
        return id == 0 ? 0 : 1;
    if (id == 0)
        return f(1 - id, p * 9, n);
    return f(1 - id, p * 2, n);
}

int main()
{
    fastio();

    ull n;
    while (cin >> n) {
        if (f(0, 1, n))
            cout << "Stan";
        else
            cout << "Ollie";
        cout << " wins.\n";
    }
}