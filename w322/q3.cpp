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

ii D[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

class Solution {
public:
    vector<vector<ii>> G;
    int minScore(int n, vector<vector<int>>& roads)
    {
        G.assign(n + 1, vector<ii>());
        int u, v, d;
        for (auto& r : roads) {
            u = r[0], v = r[1], d = r[2];
            G[u].pb({ v, d });
            G[v].pb({ u, d });
        }

        vi vis(n + 1, 0);
        int res = oo;
        queue<int> q;
        q.push(1);

        while (q.size()) {
            int u = q.front();
            q.pop();
            if (vis[u])
                continue;
            vis[u] = 1;

            for (auto& [v, d] : G[u]) {
                if (!vis[v])
                    res = min(res, d), q.push(v);
            }
        }

        return res;
    }
};