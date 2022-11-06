#include <bits/stdc++.h>

using namespace std;
#define MAXV 100
#define INF 1000000000

typedef vector<int> vi;

int res[MAXV + 1][MAXV + 1];
vi p;

int s, t, c, n, mf, f;

void augment(int v, int min_edge)
{
    if (v == s) {
        f = min_edge;
        return;
    } else if (p[v] != -1) {
        augment(p[v], min(min_edge, res[p[v]][v]));
        res[p[v]][v] -= f, res[v][p[v]] += f;
    }
}

void ek()
{
    mf = 0;
    while (1) {
        f = 0;
        vi dist(n + 1, INF);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        p.assign(n + 1, -1);

        while (q.size()) {
            int u = q.front();
            q.pop();
            if (u == t)
                break;
            for (int v = 1; v <= n; ++v) {
                if (res[u][v] > 0 && dist[v] == INF)
                    dist[v] = dist[u] + 1, q.push(v), p[v] = u;
            }
        }
        augment(t, INF);
        if (f == 0)
            break;
        mf += f;
    }
}

int main()
{
    int net = 1;

    while (scanf("%d", &n) && n) {
        printf("Network %d\n", net++);
        memset(res, 0, sizeof(res));
        scanf("%d %d %d", &s, &t, &c);

        while (c--) {
            int u, v, d;
            scanf("%d %d %d", &u, &v, &d);
            res[u][v] += d;
            res[v][u] += d;
        }

        ek();
        printf("The bandwidth is %d.\n\n", mf);
    }
}