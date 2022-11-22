#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define pb push_back
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;

#define MAXN 505

double pp[MAXN];
double memo[MAXN][MAXN];

double dp(int N, int W)
{
    if (N - W <= 0)
        return 1.0;
    if (memo[N][W] != -1)
        return memo[N][W];
    if (N - W - 1 == 0)
        return memo[N][W] = dp(N - 1, W) - pp[W + 1];
    return memo[N][W] = dp(N - 1, W) - dp(N - W - 2, W) * (1.0 - pp[1]) * pp[W + 1];
}

double solve(int n, double p)
{
    double E = 0.0;
    for (int i = 1; i <= n; ++i) {
        E += (double)i * (dp(n, i) - dp(n, i - 1));
    }
    return E;
}

int main()
{
    int n;
    double p;

    while (cin >> n >> p && n) {
        pp[0] = 1.0;
        for (int i = 1; i <= n; ++i)
            pp[i] = p * pp[i - 1];
        for (int i = 0; i < MAXN; ++i)
            fill(memo[i], memo[i] + MAXN, -1);

        double res = solve(n, p);
        printf("%.10f\n", res);
    }
}