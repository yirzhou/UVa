#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define pll(a, b) printf("%lld %lld\n", a, b)
#define plll(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0)
#define precision(a) \
    cout << fixed;   \
    cout.precision(a)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vll;

#define N 105

ii D[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

double n, b, r, v, e, f;
vector<double> pos, T;

double memo[N][N];

double dp(int k, int i)
{
    if (memo[k][i] != -1)
        return memo[k][i];
    if (i == n)
        return memo[k][i] = T[pos[n] - pos[k]];

    // Change
    double v1 = T[pos[i] - pos[k]] + b + dp(i, i + 1);
    // no change
    double v2 = dp(k, i + 1);

    return memo[k][i] = min(v1, v2);
}

int main()
{
    fastio;
    precision(4);
    while (cin >> n && n) {
        pos.assign(n + 1, 0);
        for (int i = 0; i < N; ++i)
            fill(memo[i], memo[i] + N, -1.0);
        for (int i = 1; i <= n; ++i)
            cin >> pos[i];

        cin >> b >> r >> v >> e >> f;

        int maxpos = pos.back();
        T.assign(maxpos + 1, 0.0);

        for (int i = 1; i <= maxpos; ++i) {
            double x = i - 1;
            T[i] += T[i - 1] + (x >= r ? 1 / (v - e * (x - r)) : 1 / (v - f * (r - x)));
        }

        double res = dp(0, 1);
        cout << res << endl;
    }

    return 0;
}