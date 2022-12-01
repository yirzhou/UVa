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

#define MAXN 105
int G[MAXN][MAXN];
int N, n1, n2, n3;

ii D[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

int bfs()
{
    queue<vi> q;
    q.push({ n1, n2, 0 });
    set<ii> V;
    while (q.size()) {
        int a = q.front()[0], b = q.front()[1], d = q.front()[2];
        q.pop();
        ii s = { a, b };
        if (a == n3 || b == n3)
            return d;
        if (V.count(s))
            continue;
        V.insert(s);
        if (G[a][b] != 0 && !V.count({ G[a][b], b }))
            q.push({ G[a][b], b, d + 1 });
        if (G[b][a] != 0 && !V.count({ a, G[b][a] }))
            q.push({ a, G[b][a], d + 1 });
    }
    return -1;
}

int main()
{
    fastio;
    int gameno = 1;
    while (cin >> N && N) {
        memset(G, 0, sizeof(G));
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                cin >> G[i][j];
            }
        }
        cin >> n1 >> n2 >> n3;
        int res = bfs();
        cout << "Game #" << gameno++ << endl;
        if (res == -1)
            cout << "Destination is Not Reachable !\n";
        else
            cout << "Minimum Number of Moves = " << res << endl;
        cout << endl;
    }
    return 0;
}