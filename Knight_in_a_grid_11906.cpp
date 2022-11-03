#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
int G[100][100], cnt[100][100], V[100][100];

int M, N, R, C, W, T;
int odds, evens;
vector<ii> dirs;

int main()
{
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        for (int i = 0; i < 100; ++i) {
            memset(G[i], 0, sizeof(G[i]));
            memset(cnt[i], 0, sizeof(cnt[i]));
            memset(V[i], 0, sizeof(V[i]));
        }
        scanf("%d %d %d %d", &R, &C, &M, &N);
        scanf("%d", &W);
        while (W--) {
            int x, y;
            scanf("%d %d", &x, &y);
            G[x][y] = 1;
        }

        if (M == 0 && N == 0) {
            dirs = { { 0, 0 } };
        } else if (M == 0) {
            dirs = { { M, N }, { M, -N }, { N, M }, { -N, M } };
        } else if (N == 0) {
            dirs = { { N, M }, { N, -M }, { M, N }, { -M, N } };
        } else if (M == N) {
            dirs = { { M, N }, { -M, N }, { N, -M }, { -N, -M } };
        } else {
            dirs = { { M, N }, { M, -N }, { -M, N }, { -M, -N }, { N, M }, { -N, M }, { N, -M }, { -N, -M } };
        }

        evens = 0, odds = 0;
        queue<ii> q;
        q.push({ 0, 0 });

        while (q.size()) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            if (V[x][y])
                continue;
            V[x][y] = 1;
            for (auto& d : dirs) {
                int nx = x + d.first, ny = y + d.second;
                if (0 <= nx && nx < R && 0 <= ny && ny < C && G[nx][ny] == 0) {
                    q.push({ nx, ny });
                    cnt[x][y]++;
                }
            }
            if (cnt[x][y] % 2 == 0) {
                evens++;
            } else {
                odds++;
            }
        }

        printf("Case %d: %d %d\n", t, evens, odds);
    }
}
