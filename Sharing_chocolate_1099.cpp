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

ii D[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

int n, x, y;
int parts[15];

int memo[105][1 << 15];

int sum(int mask)
{
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (((mask >> i) & 1) == 0)
            res += parts[i];
    }
    return res;
}

bool dp(int w, int h, int mask)
{
    if (memo[w][mask] != -1)
        return memo[w][mask] > 0;

    int num = 0, su = 0;
    for (int i = 0; i < n; ++i) {
        if (((mask >> i) & 1))
            num++, su += parts[i];
    }

    if (num == 1 && su == w * h)
        return memo[w][mask] = 1;

    for (int bits = (mask - 1) & mask; bits != 0; bits = (bits - 1) & mask) {
        int sum = 0;
        for (int i = 0; i < n; ++i)
            if (((bits >> i) & 1))
                sum += parts[i];
        if (sum % w == 0 && dp(w, sum / w, bits) && dp(w, h - sum / w, mask ^ bits))
            return memo[w][mask] = 1;
        if (sum % h == 0 && dp(sum / h, h, bits) && dp(w - sum / h, h, mask ^ bits))
            return memo[w][mask] = 1;
    }
    return memo[w][mask] = 0;
}

int main()
{
    fastio;
    int caseno = 1;
    while (cin >> n && n) {
        cin >> x >> y;
        memset(parts, 0, sizeof parts);
        memset(memo, -1, sizeof memo);
        int total = 0;
        for (int i = 0; i < n; ++i) {
            cin >> parts[i];
            total += parts[i];
        }
        cout << "Case " << caseno++ << ": ";
        if (total != x * y) {
            cout << "No\n";
            continue;
        }
        bool res = dp(x, y, (1 << n) - 1);
        cout << (res ? "Yes\n" : "No\n");
    }
    return 0;
}