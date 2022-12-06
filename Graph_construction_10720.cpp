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

int compute_rhs(int k, vi& degrees)
{
    int res = 0, n = degrees.size() - 1;
    if (k == n)
        return k * (k - 1);

    for (int i = k + 1; i <= n; ++i)
        res += min(degrees[i], k);
    return res;
}

bool check(vi& degrees)
{
    int total = 0, n = degrees.size() - 1;
    for (auto& d : degrees)
        total += d;
    sort(degrees.begin() + 1, degrees.end(), [](const int& a, const int& b) { return a > b; });

    if (total % 2 == 1)
        return false;

    vi pre(degrees.size(), 0);

    for (int i = 1; i < pre.size(); ++i)
        pre[i] = pre[i - 1] + degrees[i];

    if (pre[n] > n * (n - 1))
        return false;
    int lhs = 0, rhs = 0;
    for (int k = n - 1; k >= 1; --k) {
        rhs = compute_rhs(k, degrees);
        lhs = pre[k];
        if (lhs > k * (k - 1) + rhs)
            return false;
    }

    return true;
}

int main()
{
    fastio;
    int n;
    vi degrees;
    while (cin >> n && n) {
        degrees.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            cin >> degrees[i];
        if (check(degrees))
            cout << "Possible\n";
        else
            cout << "Not possible\n";
    }
}