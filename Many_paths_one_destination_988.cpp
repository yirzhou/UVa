#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
vector<vi> G;

int V;
int s = 0, t;
vi memo;
set<int> deaths;

int f(int u)
{
    if (deaths.count(u)) {
        return 1;
    }

    if (memo[u] != -1)
        return memo[u];

    int ans = 0;
    for (auto& v : G[u])
        ans += f(v);

    memo[u] = ans;
    return ans;
}

int main()
{
    int n;
    int t = 0;
    while (scanf("%d", &V) != EOF) {
        if (t++)
            printf("\n");
        memo.assign(V, -1);
        G = vector<vi>(V);
        deaths.clear();
        for (int i = 0; i < V; ++i) {
            scanf("%d", &n);

            // Death
            if (n == 0) {
                deaths.emplace(i);
                continue;
            }
            int nxt;
            for (int j = 0; j < n; ++j) {
                scanf("%d", &nxt);
                G[i].push_back(nxt);
            }
        }

        int res = f(0);
        printf("%d\n", res);
    }
}