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

#define MAXH 45
#define MAXW 15

int n, h, w;
int G[MAXH][MAXW];
unordered_map<int, vi> adj;
unordered_set<int> nodes, S1, S2, vis;
unordered_map<int, int> match, color;
ii dirs[4] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

int get_id(int r, int c)
{
    return r * w + c;
}

int Aug(int l)
{
    if (vis.count(l))
        return 0;
    vis.insert(l);
    for (auto& r : adj[l]) {
        if (match.count(r) == 0 || Aug(match[r])) {
            match[r] = l;
            return 1;
        }
    }
    return 0;
}

void bfs(int u)
{
    queue<ii> q;
    q.push({ u, 0 });

    while (q.size()) {
        int u = q.front().first, c = q.front().second;
        q.pop();
        if (color.count(u))
            continue;
        color[u] = c;
        for (auto& v : adj[u]) {
            if (!color.count(v)) {
                q.push({ v, !c });
            }
        }
    }
}

int main()
{
    si(n);
    while (n--) {
        sii(h, w);
        memset(G, 0, sizeof(G));
        color.clear(), nodes.clear(), S1.clear(), S2.clear(), adj.clear();
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                char val;
                scanf("%c", &val);
                if (val == '*') {
                    nodes.insert(get_id(i, j));
                    G[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (G[i][j]) {
                    adj[get_id(i, j)] = vi();
                    for (int k = 0; k < 4; ++k) {
                        int di = dirs[k].first, dj = dirs[k].second;
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < h && nj >= 0 && nj < w && G[ni][nj] == 1) {
                            adj[get_id(i, j)].pb(get_id(ni, nj));
                        }
                    }
                }
            }
        }

        // Bipartition
        for (auto& u : nodes) {
            if (!color.count(u)) {
                bfs(u);
            }
        }

        for (auto& [u, c] : color) {
            if (c == 1)
                S1.insert(u);
            else
                S2.insert(u);
        }

        int MCBM = 0, V = nodes.size();
        match.clear();
        for (auto& l : S1) {
            vis.clear();
            MCBM += Aug(l);
        }
        // printf("%d %d\n", MCBM, V);
        printf("%d\n", V - MCBM);
    }
}