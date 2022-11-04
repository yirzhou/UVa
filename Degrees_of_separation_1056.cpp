#include <bits/stdc++.h>

using namespace std;

const int MAXP = 50;
const int INF = 1e9;

int dist[MAXP][MAXP];
unordered_map<string, int> M;

char s1[100], s2[100];

string convert(char* a)
{
    string res;
    for (int i = 0; a[i] != '\0'; ++i) {
        res += a[i];
    }
    return res;
}

int main()
{
    int P, R;
    int n = 1;
    while (scanf("%d%d", &P, &R) && (P && R)) {
        for (int i = 0; i < P; ++i)
            fill(dist[i], dist[i] + P, INF);
        int id = 0;
        M.clear();
        while (R--) {
            scanf("%s%s", s1, s2);
            string a = convert(s1), b = convert(s2);
            if (M.count(a) == 0) {
                M[a] = id++;
            }
            if (M.count(b) == 0) {
                M[b] = id++;
            }

            int u = M[a], v = M[b];
            dist[u][v] = dist[v][u] = 1;
        }

        for (int i = 0; i < P; ++i) {
            dist[i][i] = 0;
        }

        for (int k = 0; k < P; ++k) {
            for (int i = 0; i < P; ++i) {
                for (int j = 0; j < P; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int diameter = 0;
        for (int u = 0; u < P; ++u) {
            for (int v = u + 1; v < P; ++v) {
                diameter = max(diameter, dist[u][v]);
            }
        }

        if (diameter < INF) {
            printf("Network %d: %d\n", n++, diameter);
        } else {
            printf("Network %d: DISCONNECTED\n", n++);
        }
        printf("\n");
    }
}
