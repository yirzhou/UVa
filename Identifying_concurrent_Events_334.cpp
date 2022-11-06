#include <bits/stdc++.h>

using namespace std;

#define MAXN 400

typedef vector<int> vi;
typedef pair<int, int> ii;
int dist[MAXN][MAXN];

int NC, NE, NM;
unordered_map<string, int> M;
unordered_map<int, string> RM;

string s;

int main()
{
    int t = 1;
    while (scanf("%d", &NC) && NC) {
        memset(dist, 0, sizeof(dist));
        M.clear(), RM.clear();
        int N = 0;
        while (NC--) {
            cin >> NE;
            int prev = -1;
            for (int i = 0; i < NE; ++i) {
                cin >> s;
                if (!M.count(s))
                    M[s] = N++;

                int u = prev, v = M[s];
                if (prev != -1)
                    dist[u][v] = 1;
                prev = v;
                if (!RM.count(v))
                    RM[v] = s;
            }
        }

        cin >> NM;
        string a, b;
        while (NM--) {
            cin >> a, cin >> b;
            int u = M[a], v = M[b];
            dist[u][v] = 1;
        }

        for (int i = 0; i < N; ++i)
            dist[i][i] = 1;

        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    dist[i][j] |= (dist[i][k] & dist[k][j]);
                }
            }
        }

        vector<ii> res;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (dist[i][j] == 0 && dist[j][i] == 0) {
                    res.push_back({ i, j });
                }
            }
        }

        printf("Case %d, ", t++);
        if (res.size()) {
            printf("%d concurrent events:\n", (int)res.size());
            for (int i = 0; i < min((int)res.size(), 2); ++i) {
                cout << "(" << RM[res[i].first] << "," << RM[res[i].second] << ") ";
            }
        } else {
            printf("no concurrent events.");
        }
        printf("\n");
    }
}