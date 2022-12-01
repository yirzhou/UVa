#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second
#define oo INT_MAX

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

#define N 10

string name;
int ans = INT_MAX;
int G[N];
int GC[N];
ii D[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

void flip(int i, int j)
{
    GC[i] ^= (1 << j);

    for (auto& [di, dj] : D) {
        int ni = i + di, nj = j + dj;
        if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
            GC[ni] ^= (1 << nj);
        }
    }
}

void solve()
{
    for (int i = 0; i < (1 << 10); ++i) {
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            if (((i >> j) & 1) == 0)
                continue;
            cnt++;
            flip(0, j);
        }

        for (int r = 1; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (((GC[r - 1] >> c) & 1)) {
                    flip(r, c);
                    cnt++;
                }
            }
        }

        if (cnt <= 100 && GC[N - 1] == 0)
            ans = min(ans, cnt);

        memcpy(GC, G, sizeof(G));
    }
}

int main()
{
    fastio;
    char c;
    while (cin >> name && name != "end") {
        ans = oo;
        memset(G, 0, sizeof(G));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> c;
                G[i] |= (c == '#' ? 0 : 1) << j;
            }
        }
        memcpy(GC, G, sizeof(G));
        solve();

        cout << name << " ";
        cout << (ans == oo ? -1 : ans) << endl;
    }
}