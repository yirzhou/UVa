#include <bits/stdc++.h>

using namespace std;

#define MAXN 38
#define INF 100000000

int res[MAXN][MAXN];
int s = 0, t = 37, mf = 0, f = 0, target = 0;

string S;

typedef vector<int> vi;
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

void EK()
{
    mf = 0;
    while (1) {
        f = 0;
        vi dist(MAXN, INF);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        p.assign(MAXN, -1);

        while (q.size()) {
            int u = q.front();
            q.pop();
            if (u == t)
                break;
            for (int v = 0; v < MAXN; ++v) {
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

void solve()
{
    EK();
    if (mf != target)
        printf("!");
    else {
        for (int i = 27; i <= 36; ++i) {
            bool assigned = false;
            for (int j = 1; j <= 26; ++j) {
                if (res[i][j] == 1) {
                    printf("%c", j - 1 + 'A');
                    assigned = true;
                    break;
                }
            }
            if (!assigned)
                printf("_");
        }
    }
    printf("\n");
}

int main()
{
    memset(res, INF, sizeof(res));

    while (getline(cin, S)) {
        if (!S.size()) {
            solve();
            f = 0;
            p.clear();
            memset(res, 0, sizeof(res));
            mf = target = 0;
            continue;
        }

        int app = S[0] - 'A' + 1, X = S[1] - '0';
        res[s][app] = X;
        target += X;
        for (int i = 3; S[i] != ';'; ++i) {
            int computer = S[i] - '0' + 27;
            res[app][computer] = INF;
            res[computer][t] = 1;
        }
    }
    solve();
}