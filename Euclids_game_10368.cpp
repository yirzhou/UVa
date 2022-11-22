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
#define nl endl

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

int f(int a, int b)
{
    if (b == 0)
        return 0;
    if (a / b > 1)
        return 1;
    return f(max(a - b, b), min(a - b, b)) + 1;
}

int main()
{
    fastio();
    int a, b;
    while (cin >> a >> b && (a || b)) {
        if (a < b)
            swap(a, b);
        int cnt = f(a, b);
        cout << ((cnt & 1) ? "Stan " : "Ollie ") << "wins" << endl;
    }
}