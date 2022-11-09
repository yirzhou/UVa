#include <bits/stdc++.h>

using namespace std;

#define MAXN 600
#define MAXK 300
#define INF 1000000000

typedef vector<int> vi;
vi G;
int memo[MAXN + 5][MAXK + 5];
int K, N, s, t;

int dp(int pos, int nights)
{
    int sum = 0, res = INF;

    if (memo[pos][nights] != -1)
        return memo[pos][nights];

    if (nights > 0) {
        for (int i = pos; i < t; ++i) {
            sum += G[i];
            res = min(res, max(sum, dp(i + 1, nights - 1)));
        }
    } else {
        for (int i = pos; i < t; ++i)
            sum += G[i];
        res = sum;
    }

    return memo[pos][nights] = res;
}

// minimise the maximum amount of walking done in a single day

int main()
{

    while (scanf("%d %d\n", &N, &K) == 2) {
        G = vi(N + 1, 0);
        for (int i = 0; i < N + 5; ++i)
            fill(memo[i], memo[i] + MAXK + 5, -1);

        s = 0, t = N + 1;
        for (int i = 0; i < N + 1; ++i)
            scanf("%d", &G[i]);

        int res = dp(0, K);
        cout << res << endl;
    }
}