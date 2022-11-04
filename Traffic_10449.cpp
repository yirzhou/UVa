#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
vector<vector<ii>> G;
vi V;
vi dist;
unordered_set<int> store;

// TODO: NOT done.

void bf()
{
    dist[1] = 0;
    int num_nodes = dist.size() - 1;
    for (int i = 0; i < num_nodes - 1; ++i) {
        for (int u = 1; u <= num_nodes; ++u) {
            for (auto& [v, d] : G[u]) {
                if (dist[u] != INT_MAX) {
                    dist[v] = min(dist[v], dist[u] + d);
                }
            }
        }
    }

    for (int u = 1; u <= num_nodes; ++u) {
        for (auto& [v, d] : G[u]) {
            if (dist[v] > dist[u] + d) {
                dist[v] = dist[u] + d;
                store.insert(v);
            }
        }
    }
}

int main()
{
    int n, r, q, s;
    int t = 1;
    while (scanf("%d", &n) == 1) {

        G = vector<vector<ii>>(n + 1);
        V = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &V[i]);
        }

        scanf("%d", &r);
        int u, v;
        while (r--) {
            scanf("%d%d", &u, &v);
            G[u].push_back({ v, pow(V[v] - V[u], 3.0) });
        }

        printf("Set #%d\n", t++);
        store.clear();
        dist.assign(n + 1, INT_MAX);
        bf();

        scanf("%d", &q);
        while (q--) {
            scanf("%d", &s);
            if (dist[s] < 3 || dist[s] == INT_MAX || store.count(s)) {
                printf("?\n");
            } else
                printf("%d\n", dist[s]);
        }
    }
}
