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

bool solve(int m, int n, int r, int c)
{
    int L = c, R = n - c - 1;
    int U = r, D = m - r - 1;

    return (L ^ R ^ U ^ D) == 0;
}

int main()
{
    fastio();
    int t, m, n, r, c;
    cin >> t;

    while (t--) {
        cin >> m >> n >> r >> c;
        if (solve(m, n, r, c))
            cout << "Hansel\n";
        else
            cout << "Gretel\n";
    }
}