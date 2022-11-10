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

#define MAXN 205

int N, R;
int d[MAXN];
int total, s;

int adj[MAXN][MAXN];
int visited[MAXN];

unordered_set<int> nodes;

void dfs(int u)
{
    if (visited[u])
        return;
    total++;
    visited[u] = 1;
    for (int v = 0; v < N; ++v) {
        if (adj[u][v] > 0 && !visited[v])
            dfs(v);
    }
}

bool check()
{
    for (auto& u : nodes) {
        if (d[u] % 2) {
            return false;
        }
    }
    total = 0;
    dfs(s);

    return total == nodes.size();
}

int main()
{
    while (sii(N, R) != EOF) {
        memset(d, 0, sizeof(d));
        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));
        nodes.clear();

        int u, v;
        s = -1;
        while (R--) {
            sii(u, v);
            d[u]++;
            d[v]++;
            adj[u][v]++;
            if (s == -1)
                s = u;
            nodes.emplace(u), nodes.emplace(v);
        }
        bool res = check();
        printf(res ? "Possible\n" : "Not Possible\n");
    }
}