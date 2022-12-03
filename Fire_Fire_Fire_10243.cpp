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
int N;
vector<unordered_set<int>> al;
vi V;

vector<vi> dp;

int MVC(int prev, int u, int flag)
{
    if (dp[u][flag] != -1)
        return dp[u][flag];
    int ans = flag;
    if (flag == 0) {
        for (auto& v : al[u])
            if (v != prev)
                ans += MVC(u, v, 1);
    } else {
        for (auto& v : al[u])
            if (v != prev)
                ans += min(MVC(u, v, 1), MVC(u, v, 0));
    }

    return dp[u][flag] = ans;
}

int main()
{
    fastio;
    int cnt, v;
    while (cin >> N && N) {
        al.assign(N + 1, unordered_set<int>());
        V.assign(N + 1, 0);
        dp.assign(N + 1, vi(2, -1));
        for (int u = 1; u <= N; ++u) {
            cin >> cnt;
            while (cnt--) {
                cin >> v;
                al[u].insert(v);
            }
        }

        int ans = min(MVC(0, 1, 0), MVC(0, 1, 1));
        cout << (N == 1 ? 1 : ans) << endl;
    }

    return 0;
}