#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define pll(a, b) printf("%lld %lld\n", a, b)
#define plll(a, b, c) printf("%lld %lld %lld\n", a, b, c)
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

int get_t(string& t)
{
    int i = t.find(':');
    int h = stoi(t.substr(0, i)), m = stoi(t.substr(i + 1));
    return h * 60 + m;
}

struct customer {
    int id, a, b, c, d, t;
};

vector<customer> C;
vector<unordered_set<int>> G;

vi match, vis;
vector<vi> AL;

int Aug(int L)
{
    if (vis[L])
        return 0;
    vis[L] = 1;
    for (auto& R : AL[L])
        if ((match[R] == -1) || Aug(match[R])) {
            match[R] = L;
            return 1;
        }
    return 0;
}

int main()
{
    fastio;
    int n, m, a, b, c, d, t;
    string tstr;
    cin >> n;

    while (n--) {
        cin >> m;
        C.clear();
        for (int i = 0; i < m; ++i) {
            cin >> tstr >> a >> b >> c >> d;
            t = get_t(tstr);
            C.pb({ i, a, b, c, d, t });
        }

        AL = vector<vi>(m);
        vis = vi(m, 0);
        match = vi(m, -1);
        for (int u = 0; u < m; ++u) {
            int last = C[u].t + abs(C[u].a - C[u].c) + abs(C[u].b - C[u].d);
            for (int v = u + 1; v < m; ++v) {
                if (last + abs(C[v].a - C[u].c) + abs(C[v].b - C[u].d) < C[v].t) {
                    AL[u].pb(v);
                }
            }
        }
        int M = 0;
        for (int u = 0; u < m; ++u)
            vis.assign(m, 0), M += Aug(u);

        cout << m - M << endl;
    }

    return 0;
}