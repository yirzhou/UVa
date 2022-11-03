#include <bits/stdc++.h>

using namespace std;

#define MAX 25
#define UNVISITED 1000000

int n, m;

string line;
unordered_map<int, vector<int>> G;
unordered_map<string, int> M;
unordered_map<int, string> RM;

vector<int> dfs_num, dfs_low, S;
int id = 0, cnt = 0;
int visited[MAX];

void dfs(int u)
{
    dfs_low[u] = dfs_num[u] = cnt++;
    S.push_back(u);
    visited[u] = 1;

    for (auto& v : G[u]) {
        if (dfs_num[v] == UNVISITED)
            dfs(v);
        if (visited[v])
            dfs_low[u] = min(dfs_low[v], dfs_low[u]);
    }

    if (dfs_low[u] == dfs_num[u]) {
        while (1) {
            int v = S.back();
            S.pop_back();
            visited[v] = 0;
            cout << RM[v];
            if (u != v)
                cout << ", ";
            else {
                printf("\n");
                break;
            }
        }
    }
}

int main()
{
    int t = 0;
    while (scanf("%d %d\n", &n, &m) && (n || m)) {
        G.clear();
        S.clear();
        M.clear();
        RM.clear();
        dfs_num.assign(n + 1, UNVISITED);
        dfs_low.assign(n + 1, 0);

        memset(visited, 0, sizeof(visited));
        cnt = 0;

        id = 0;
        for (int i = 0; i < m; ++i) {
            getline(cin, line);
            int si = line.find(' ');
            string a = line.substr(0, si), b = line.substr(si + 1, line.size() - si - 1);
            if (!M.count(a)) {
                M[a] = id;
                RM[id++] = a;
            }

            if (!M.count(b)) {
                M[b] = id;
                RM[id++] = b;
            }

            G[M[a]].push_back(M[b]);
        }

        printf("Calling circles for data set %d:\n", ++t);
        for (int i = 0; i < n; ++i) {
            if (dfs_num[i] == UNVISITED)
                dfs(i);
        }
    }
}
