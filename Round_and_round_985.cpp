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

#define N 4

ii D[] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
map<ii, int> IDX = { { { -1, 0 }, 0 }, { { 0, 1 }, 1 }, { { 1, 0 }, 2 }, { { 0, -1 }, 3 } };

int f(vector<vector<vector<ii>>>& G, int i, int j, int ti, int tj)
{
    set<vi> V;
    queue<vi> q;
    q.push({ i, j, 0, 0 });

    int R = G.size(), C = G[0].size();

    while (q.size()) {
        vi v = q.front();
        q.pop();
        int r = v[0], c = v[1], x = v[2], d = v[3];
        if (r == ti && c == tj)
            return d;
        if (V.count({ r, c, x }))
            continue;
        V.insert({ r, c, x });
        int nx = (x + 1) % N;
        for (auto& direction : G[r][c]) {
            int oi = IDX[direction], idx = (oi + x) % N;
            int ni = D[idx].fi + r, nj = D[idx].se + c;
            if (ni >= 0 && ni < R && nj >= 0 && nj < C && !V.count({ ni, nj, nx }))
                q.push({ ni, nj, nx, d + 1 });
        }
    }

    return -1;
}

int main()
{
    fastio;
    int R, C;

    while (cin >> R >> C) {
        vector<vector<vector<ii>>> G(R, vector<vector<ii>>(C));
        string s;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (r == R - 1 && c == C - 1)
                    break;
                cin >> s;
                for (auto& cha : s) {
                    ii dir;
                    if (cha == 'N')
                        dir = { -1, 0 };
                    else if (cha == 'E')
                        dir = { 0, 1 };
                    else if (cha == 'S')
                        dir = { 1, 0 };
                    else
                        dir = { 0, -1 };
                    G[r][c].pb(dir);
                }
            }
        }

        int res = f(G, 0, 0, R - 1, C - 1);
        if (res == -1)
            cout << "no path to exit" << endl;
        else
            cout << res << endl;
    }
}