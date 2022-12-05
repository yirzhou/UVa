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

#define N 2 << 17

int n, k, c;

vector<string> kids;
unordered_map<string, int> id;
vi E;

int dp[N], memo[N];
int sets[N];

bool check(int mask, int c)
{
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (((mask >> i) & 1)) {
            ++cnt;
            if (cnt > c)
                return false;
            for (int j = i + 1; j < n; ++j) {
                if (((mask >> j) & 1) && ((E[i] >> j) & 1))
                    return false;
            }
        }
    }
    return true;
}

void print(int mask)
{
    for (int i = 0; i < n; ++i)
        if (((mask >> i) & 1))
            cout << kids[i] << " ";
    cout << endl;
}

int f(int mask)
{
    if (mask == (1 << n) - 1)
        return 0;

    if (dp[mask] != -1)
        return dp[mask];

    int ans = INT_MAX;
    int optimal;

    int nxt = ((1 << n) - 1) ^ mask;
    for (int ss = nxt; ss; ss = (ss - 1) & nxt) {
        if (sets[ss]) {
            int res = 1 + f(mask | ss);
            if (res < ans)
                ans = res, optimal = ss;
        }
    }

    memo[mask] = optimal;
    return dp[mask] = ans;
}

void backtrack(int mask)
{
    int ss = memo[mask];
    if (ss == 0)
        return;

    backtrack(mask | ss);
    print(ss);
}

int main()
{
    fastio;
    cin >> n >> k >> c;
    string s, k1, k2;
    kids = vector<string>(n);
    E.assign(n, 0);
    memset(dp, -1, sizeof dp);
    memset(memo, 0, sizeof memo);
    memset(sets, 0, sizeof sets);

    for (int i = 0; i < n; ++i) {
        cin >> kids[i];
        id[kids[i]] = i;
    }

    for (int i = 0; i < k; ++i) {
        cin >> k1 >> k2;
        int u = id[k1], v = id[k2];
        E[u] |= (1 << v), E[v] |= (1 << u);
    }

    for (int ss = (1 << n) - 1; ss >= 0; --ss) {
        if (check(ss, c))
            sets[ss] = 1;
    }
    cout << f(0) << endl;
    backtrack(0);
    return 0;
}