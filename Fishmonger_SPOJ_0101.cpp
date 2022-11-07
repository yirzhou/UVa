#include <bits/stdc++.h>

/*
- he has to pay as little money for tolls as possible
- he has to be at the market within a certain time
*/

using namespace std;

#define INF 1000000000

typedef vector<int> vi;
typedef pair<int, int> ii;

int n, t, u, v;
vector<vi> gtime, gtoll;
vector<vector<ii>> memo;

ii f(int cur, int t_left)
{
    if (t_left < 0)
        return ii(INF, INF);
    if (cur == v)
        return ii(0, 0);
    if (memo[cur][t_left] != ii(-1, -1))
        return memo[cur][t_left];
    ii ans = ii(INF, INF);
    for (int i = 0; i < n; ++i) {
        if (i != cur) {
            ii nxt = f(i, t_left - gtime[cur][i]);
            if (nxt.first + gtoll[cur][i] < ans.first) {
                ans.first = nxt.first + gtoll[cur][i];
                ans.second = nxt.second + gtime[cur][i];
            }
        }
    }

    return memo[cur][t_left] = ans;
}

int main()
{
    while (scanf("%d %d", &n, &t) && n && t) {
        gtime = vector<vi>(n, vi(n, 0));
        gtoll = vector<vi>(n, vi(n, 0));
        memo = vector<vector<ii>>(n, vector<ii>(t + 1, { -1, -1 }));

        u = 0, v = n - 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &gtime[i][j]);
            }
        }

        scanf("\n");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &gtoll[i][j]);
            }
        }

        ii res = f(0, t);
        printf("%d %d\n", res.first, res.second);

        scanf("\n");
    }
}