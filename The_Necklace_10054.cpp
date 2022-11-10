#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> ii;

#define MAXN 1005
#define MAXC 51

int d[MAXC];
int g[MAXC][MAXC];
unordered_set<int> colors;
vi C;

int T, N;
list<int> cyc;

bool check()
{
    for (auto& i : C) {
        if (d[i] % 2)
            return false;
    }
    return true;
}

void euler_tour(list<int>::iterator i, int u)
{
    for (int v = 1; v < MAXC; ++v) {
        if (g[u][v] > 0) {
            g[u][v]--;
            for (int k = 1; k < MAXC; ++k) {
                if (k == u && g[v][k] > 0) {
                    g[v][k]--;
                    break;
                }
            }
            euler_tour(cyc.insert(i, u), v);
        }
    }
}

int main()
{
    si(T);
    for (int t = 1; t <= T; ++t) {
        if (t > 1)
            printf("\n");
        si(N);
        memset(d, 0, sizeof(d));
        memset(g, 0, sizeof(g));
        C.clear(), colors.clear();
        int u, v;
        for (int i = 0; i < N; ++i) {
            sii(u, v);
            d[u]++;
            d[v]++;
            g[u][v]++;
            g[v][u]++;
            colors.emplace(u), colors.emplace(v);
        }

        for (auto& c : colors)
            C.pb(c);

        printf("Case #%d\n", t);
        if (!check()) {
            printf("some beads may be lost\n");
            continue;
        }
        cyc.clear();
        euler_tour(cyc.begin(), C[0]);
        vector<int> res;
        for (auto it = cyc.begin(); it != cyc.end(); ++it) {
            res.pb(*it);
        }

        if (res.size() != N) {
            printf("some beads may be lost\n");
            continue;
        }

        res.pb(res[0]);
        for (int i = 1; i < res.size(); ++i) {
            printf("%d %d\n", res[i - 1], res[i]);
        }
    }
}