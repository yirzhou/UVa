#include <bits/stdc++.h>

using namespace std;

#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define fastio                                                                 \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(0)
#define precision(a)                                                           \
    cout << fixed;                                                             \
    cout.precision(a)

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define pll(a, b) printf("%lld %lld\n", a, b)
#define plll(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define oo INT_MAX
#define UNVISITED -1
#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;

ii D[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int t, n, k;
ll nums[100005];
ll memo[100005][31];
bool V[100005][31];

ll dp(int i, int j) {
    if (n == i) {
        return 0LL;
    }
    ll num = nums[i];
    bool &v = V[i][j];
    ll &ans = memo[i][j];
    if (0 != v) {
        return ans;
    }

    ans = max(-k + (num >> j) + dp(i + 1, j),
              (num >> (j + 1)) + dp(i + 1, min(30, j + 1)));
    v = 1;
    return ans;
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        memset(V, 0, sizeof V);
        cout << dp(0, 0) << endl;
    }
}
