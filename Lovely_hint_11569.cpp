#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
#define UNVISITED -1
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
typedef vector<vi> vii;

unordered_set<int> A;

unordered_map<int, vi> G;

ii dp[30] = { { -1, -1 } };

void proc(string& s)
{
    A.clear();
    G.clear();
    for (int i = 0; i < 30; ++i)
        dp[i] = { -1, -1 };
    for (auto& c : s) {
        if (c >= 'A' && c <= 'Z') {
            A.insert(c - 'A' + 1);
            if (!G.count(c - 'A' + 1))
                G[c - 'A' + 1] = vi();
        }
    }

    for (auto& u : A) {
        for (auto& v : A)
            if (5 * u <= 4 * v)
                G[u].pb(v);
    }
}

ii f(int i)
{
    if (dp[i].fi != -1)
        return dp[i];

    int ans = 1, cnt = 1;
    for (auto& j : G[i]) {
        ii res = f(j);
        int len = 1 + res.fi;
        if (len > ans)
            ans = len, cnt = res.se;
        else if (len == ans)
            cnt += res.se;
    }
    return dp[i] = { ans, cnt };
}

int main()
{
    fastio;
    string s;
    int t;
    getline(cin, s);
    t = stoi(s);
    while (t--) {
        getline(cin, s);
        proc(s);

        int res = 0, cnt = 0;
        for (auto& [u, _] : G) {
            ii p = f(u);
            if (p.fi > res)
                res = p.fi, cnt = p.se;
            else if (p.fi == res)
                cnt += p.se;
        }
        cout << res << " " << cnt << endl;
    }
    return 0;
}