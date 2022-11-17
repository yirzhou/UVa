#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int main()
{
    int n;
    double d, v, u;
    cin >> n;
    for (int i = 1; i <= n; ++i) {

        cin >> d >> v >> u;
        if (v == 0 || u == 0 || v >= u) {
            printf("Case %d: can't determine\n", i);
            continue;
        }

        double case1 = d / u;
        double case2 = d / sqrt((u * u - v * v));
        double P = fabs((double)(case2 - case1));
        printf("Case %d: %.3lf\n", i, P);
    }
}