#include <bits/stdc++.h>

using namespace std;

#define MAXV 50
#define INF 1000000000

typedef vector<int> vi;

int res[2 * MAXV][2 * MAXV];

int M, W, mf, f, s, t;
vi p;

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
        vi dist(2 * M + 1, INF);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        p.assign(2 * M + 1, -1);

        while (q.size()) {
            int u = q.front();
            q.pop();
            if (u == t)
                break;
            for (int v = 1; v <= 2 * M; ++v) {
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
    while (scanf("%d %d", &M, &W) && M && W) {
        memset(res, 0, sizeof(res));
        s = 1, t = M;
        for (int i = 0; i < M - 2; ++i) {
            int id, cost;
            scanf("%d %d", &id, &cost);
            int vin = id, vout = id + M;

            res[vin][vout] = res[vout][vin] = cost;
        }

        for (int i = 0; i < W; ++i) {
            int j, k, d;
            scanf("%d %d %d", &j, &k, &d);
            int jin = j, jout = j + M, kin = k, kout = k + M;
            if (j == 1 || j == M) {
                res[j][k] = d;
                if (1 < k && k < M) {
                    res[kout][j] = d;
                } else {
                    res[k][j] = d;
                }
            } else if (k == 1 || k == M) {
                res[k][j] = d;
                if (1 < j && j < M) {
                    res[jout][k] = d;
                } else {
                    res[j][k] = d;
                }
            } else {
                res[jout][kin] = res[kout][jin] = d;
            }
            // printf("%d %d %d %d\n", jin, jout, kin, kout);
        }

        ek();

        cout << mf << endl;
    }
}