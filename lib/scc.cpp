#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
#define INF 1000000000
#define EPS 1e-9
#define UNVISITED -1
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
typedef vector<vi> vii;
typedef vector<ll> vll;

vi dfs_num, S;
vii AL, AL_T;

// pass = 1 (original), 2 (transpose)
void Kosaraju(int u, int pass)
{
    dfs_num[u] = 1;
    vi& neighbor = (pass = 1) ? AL[u] : AL_T[u];
    for (auto& v : neighbor) {
        if (dfs_num[v] == UNVISITED)
            Kosaraju(v, pass);
    }
    S.pb(u);
}

int count_SCC()
{
    S.clear();
    int N = AL.size();
    dfs_num.assign(N, UNVISITED);
    for (int u = 0; u < N; ++u) {
        if (dfs_num[u] == UNVISITED)
            Kosaraju(u, 1);
    }

    int num_SCC = 0;

    dfs_num.assign(N, UNVISITED);
    for (int i = N - 1; i >= 0; --i) {
        if (dfs_num[S[i]] == UNVISITED)
            ++num_SCC, Kosaraju(S[i], 2);
    }

    return num_SCC;
}
