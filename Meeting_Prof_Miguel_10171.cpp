#include <bits/stdc++.h>

using namespace std;

const int V = 26;
const int INF = 1e9;

int N;
int d1[V][V], d2[V][V];

typedef vector<int> vi;

int main()
{
    while (scanf("%d\n", &N) && N) {
        char mode, dir, uc, vc;
        int u, v, c;
        for (int i = 0; i < V; ++i) {
            fill(d1[i], d1[i] + V, INF);
            fill(d2[i], d2[i] + V, INF);
        }
        while (N--) {
            scanf("%c %c %c %c %d\n", &mode, &dir, &uc, &vc, &c);
            u = uc - 'A', v = vc - 'A';
            if (mode == 'Y') {
                d1[u][v] = min(c, d1[u][v]);
                if (dir == 'B')
                    d1[v][u] = min(c, d1[v][u]);

            } else {
                d2[u][v] = min(c, d2[u][v]);
                if (dir == 'B')
                    d2[v][u] = min(c, d2[v][u]);
            }
        }

        char s1, s2;
        scanf("%c %c", &s1, &s2);
        int u1 = s1 - 'A', u2 = s2 - 'A';

        for (int i = 0; i < 26; ++i) {
            d1[i][i] = d2[i][i] = 0;
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    d1[i][j] = min(d1[i][j], d1[i][k] + d1[k][j]);
                    d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]);
                }
            }
        }

        int res = INF;
        vector<int> chosen;
        for (int i = 0; i < 26; ++i) {
            res = min(res, d1[u1][i] + d2[u2][i]);
        }
        for (int i = 0; i < 26; ++i) {
            if (d1[u1][i] + d2[u2][i] == res) {
                chosen.push_back(i);
            }
        }

        if (res >= INF)
            printf("You will never meet.\n");
        else {
            printf("%d ", res);
            for (int i = 0; i < chosen.size(); ++i) {
                printf(i == chosen.size() - 1 ? "%c\n" : "%c ", chosen[i] + 'A');
            }
        }
    }
}
