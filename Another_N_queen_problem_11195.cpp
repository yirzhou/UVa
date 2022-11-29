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

int ans = 0, OK;
vector<unordered_set<int>> bad;

void f(int rw, int ld, int rd, int col)
{
    if (rw == OK) {
        ans++;
        return;
    }

    int pos = OK & (~(rw | ld | rd));
    for (auto& row : bad[col]) {
        if (((pos >> row) & 1) == 1) {
            pos ^= (1 << row);
        }
    }

    while (pos) {
        int p = pos & -pos;
        pos -= p;
        f(rw | p, (ld | p) << 1, (rd | p) >> 1, col + 1);
    }
}

int main()
{
    fastio;
    int n, caseno = 1;
    ;
    while (cin >> n && n) {
        char c;
        bad = vector<unordered_set<int>>(n);
        ans = 0;
        OK = (1 << n) - 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> c;
                if (c == '*')
                    bad[j].insert(i);
            }
        }

        f(0, 0, 0, 0);
        cout << "Case " << caseno++ << ": " << ans << endl;
    }
}