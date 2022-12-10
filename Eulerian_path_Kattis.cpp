#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
#define UNVISITED -1
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
typedef vector<vi> vii;

int N, M;
vii AL;
vi V;
vector<ii> degree;

vi hierholzer(int s)
{
    vi ans, idx(N, 0), st;
    st.pb(s);

    while (!st.empty()) {
        int u = st.back();
        if (idx[u] < (int)AL[u].size()) {
            st.pb(AL[u][idx[u]]);
            ++idx[u];
        } else {
            ans.pb(u);
            st.pop_back();
        }
    }

    reverse(ALL(ans));
    return ans;
}

void dfs(int u)
{
    if (V[u])
        return;
    V[u] = 1;
    for (auto& v : G[u])
        dfs(v);
}

int main()
{
    fastio;
    int u, v;
    while (cin >> N >> M && (N | M)) {
        AL.assign(N, vi());
        V.assign(N, 0);
        degree.assign(N, { 0, 0 });
        for (int i = 0; i < M; ++i) {
            cin >> u >> v;
            AL[u].pb(v);
            degree[v].se++, degree[u].fi++;
        }

        int s = 0, total = 0;
        for (int u = 0; u < N; ++u) {
            if (degree[u].fi != degree[u].se)
                total++;
            if (degree[u].fi - degree[u].se == 1)
                s = u;
        }

        vi tour = hierholzer(s);
        if (tour.size() == M + 1 && (total == 0 || total == 2)) {
            for (int i = 0; i < tour.size() - 1; ++i)
                cout << tour[i] << " ";
            cout << tour.back() << endl;
        } else {
            cout << "Impossible\n";
        }
    }
    return 0;
}