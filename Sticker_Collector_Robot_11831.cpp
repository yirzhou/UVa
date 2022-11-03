#include <bits/stdc++.h>

#define MAXN 100
#define MAXS 50000

char G[MAXN][MAXN];
int N, M, S;
int x, y;
char dir;

using namespace std;

typedef pair<int, int> ii;

unordered_map<char, ii> ACC = { { 'N', { -1, 0 } }, { 'S', { 1, 0 } }, { 'L', { 0, 1 } }, { 'O', { 0, -1 } } };
unordered_map<char, vector<char>> NXT = { { 'N', { 'L', 'O' } }, { 'S', { 'O', 'L' } }, { 'L', { 'S', 'N' } }, { 'O', { 'N', 'S' } } };

int main()
{
    while (scanf("%d %d %d\n", &N, &M, &S) && (N || M || S)) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                scanf("%c", &G[i][j]);
                if (G[i][j] == 'N' || G[i][j] == 'S' || G[i][j] == 'L' || G[i][j] == 'O') {
                    x = i, y = j;
                    dir = G[i][j];
                }
            }
            scanf("\n");
        }
        char inst;
        int res = 0;
        for (int i = 0; i < S; ++i) {
            scanf("%c", &inst);
            if (inst == 'D' || inst == 'E') {
                dir = NXT[dir][inst - 'D'];
            } else {
                int dx = ACC[dir].first, dy = ACC[dir].second;
                int nx = x + dx, ny = y + dy;
                if (0 <= nx && nx < N && 0 <= ny && ny < M && G[nx][ny] != '#') {
                    x = nx, y = ny;
                    if (G[x][y] == '*') {
                        res++;
                        G[x][y] = '.';
                    }
                }
            }
        }

        printf("%d\n", res);
    }
    return 0;
}
