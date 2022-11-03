#include <bits/stdc++.h>

using namespace std;

#define MAXN 200

int n, l;
unordered_map<int, vector<int>> G;
unordered_map<int, int> M;

int f(int v)
{

    queue<pair<int, int>> q;
    q.push({ v, 0 });

    while (q.size()) {
        auto p = q.front();
        q.pop();
        int color = p.second;
        M[p.first] = color;
        for (auto& nei : G[p.first]) {
            if (M.count(nei) == 0) {
                q.push({ nei, 1 - color });
            } else if (M[nei] == color) {
                return 0;
            }
        }
    }

    return 1;
}

int main()
{
    while (scanf("%d", &n) && n) {
        scanf("%d", &l);
        G.clear();
        M.clear();

        while (l--) {
            int a, b;
            scanf("%d %d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }

        printf(f(0) ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");
    }
}
