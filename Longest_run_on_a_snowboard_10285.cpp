#include <bits/stdc++.h>

using namespace std;

int R, C, N;
typedef vector<int> vi;
typedef pair<int, int> ii;

vector<vi> G;
vector<ii> dirs = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

char S[50];
int memo[100][100];

int f(int i, int j)
{
    if (memo[i][j] != -1)
        return memo[i][j];
    int ans = 1;
    int h = G[i][j];
    int ni, nj;
    for (auto& [di, dj] : dirs) {
        ni = i + di, nj = j + dj;
        if (0 <= ni && ni < R && 0 <= nj && nj < C && G[ni][nj] > h) {
            ans = max(ans, 1 + f(ni, nj));
        }
    }
    return memo[i][j] = ans;
}

int main()
{
    scanf("%d", &N);
    while (N--) {
        scanf("%s %d %d", S, &R, &C);
        G = vector<vi>(R, vi(C));
        for (int i = 0; i < 100; ++i)
            fill(memo[i], memo[i] + 100, -1);
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                scanf("%d", &G[i][j]);
            }
        }

        // Solve
        int res = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                res = max(res, f(i, j));
            }
        }

        printf("%s: %d\n", S, res);
    }
}