#include <cstring>
#include <iostream>
#include <iterator>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define fastio                                                                                                         \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(0)
#define precision(a)                                                                                                   \
    cout << fixed;                                                                                                     \
    cout.precision(a)

#define oo INT_MAX
#define UNVISITED -1
#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define pll(a, b) printf("%lld %lld\n", a, b)
#define plll(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define oo INT_MAX
#define UNVISITED -1
#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;

int n, m;
ll g1[405][405], g2[405][405];

int main()
{
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) fill(g1[i], g1[i] + n + 1, INF);
    for (int i = 1; i <= n; ++i) fill(g2[i], g2[i] + n + 1, 1);
    int u, v;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        g1[u][v] = g1[v][u] = 1;
        g2[u][v] = g2[v][u] = INF;
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                g1[i][j] = min(g1[i][j], g1[i][k] + g1[k][j]);
                g2[i][j] = min(g2[i][j], g2[i][k] + g2[k][j]);
            }
        }
    }

    int ans = max(g1[1][n], g2[1][n]);
    if (ans == INF) cout << "-1" << endl;
    else cout << ans << endl;
}
