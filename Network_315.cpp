#include <bits/stdc++.h>

using namespace std;

#define MAXN 100
#define UNVISITED 1000000

int N;
vector<vector<int>> G;
vector<int> dfs_low, dfs_num;
int res = 0, cnt = 0;

void dfs(int u, int p)
{
    bool cut = false;

    int child = 0;
    dfs_low[u] = dfs_num[u] = ++cnt;
    for (auto& v : G[u]) {
        if (dfs_num[v] == UNVISITED) {
            ++child;
            dfs(v, u);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            if (dfs_low[v] >= dfs_num[u])
                cut = true;
        } else if (v != p)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }

    if ((child > 1 || p != -1) && cut)
        res++;
}

int main()
{
    while (scanf("%d\n", &N) && N) {
        G = vector<vector<int>>(N + 1);
        char c;

        while (scanf("%c", &c) && c != '0') {
            int u = c - '0';
            while (scanf("%c", &c) && c != ' ') {
                u *= 10;
                u += c - '0';
            }

            while (scanf("%c", &c) && c != '\n') {
                int v = c - '0';
                while (scanf("%c", &c) && (c != ' ' && c != '\n')) {
                    v *= 10;
                    v += c - '0';
                }
                G[u].push_back(v);
                G[v].push_back(u);
                if (c == '\n')
                    break;
            }
        }

        dfs_low.assign(N + 1, 0);
        dfs_num.assign(N + 1, UNVISITED);
        res = cnt = 0;

        dfs(1, -1);

        printf("%d\n", res);
    }
}
