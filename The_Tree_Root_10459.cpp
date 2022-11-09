#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef vector<int> vi;
typedef pair<int, int> ii;

#define MAXN 5005
vector<vi> G;
int N, maxd, e;

unordered_set<int> best;
unordered_set<int> worst;
vi dist;

void dfs(int u, int p, int d)
{
    dist[u] = max(dist[u], d);
    if (d > maxd) {
        maxd = d;
        e = u;
    }

    for (auto& v : G[u]) {
        if (v != p)
            dfs(v, u, d + 1);
    }
}

int main()
{
    while (si(N) != EOF) {
        dist.assign(N + 1, 0);
        best.clear(), worst.clear();
        int K, v;
        G = vector<vi>(N + 1);
        for (int i = 1; i <= N; ++i) {
            si(K);
            for (int j = 0; j < K; ++j) {
                si(v);
                G[i].push_back(v);
            }
        }
        maxd = 0;
        dfs(1, 0, -1);
        dfs(e, 0, -1);
        dfs(e, 0, -1);

        int mind = INF;
        for (int i = 1; i <= N; ++i)
            mind = min(mind, dist[i]);
        vector<int> B, W;
        for (int i = 1; i <= N; ++i) {
            if (dist[i] == maxd)
                W.pb(i);
            if (dist[i] == mind)
                B.pb(i);
        }
        printf("Best Roots  : ");
        for (int i = 0; i < B.size(); ++i)
            printf(i == B.size() - 1 ? "%d\n" : "%d ", B[i]);
        printf("Worst Roots : ");
        for (int i = 0; i < W.size(); ++i)
            printf(i == W.size() - 1 ? "%d\n" : "%d ", W[i]);
    }
}