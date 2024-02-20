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

ll t, n, x, y, q;
unordered_map<ll, int> mp;

ll my_sqrt(long long a) {
    long long l = 0, r = 5000000001;
    while (l < r) {
        long long mid = (l + r) / 2;
        if (1ll * mid * mid <= a) l = mid + 1;
        else r = mid;
    }
    return l - 1LL;
}

ll get(ll b, ll c) {
    ll D = 1LL * b * 1LL * b - 4 * 1LL * c;
    if (D < 0) {
        return 0;
    }
    ll x1 = (b - my_sqrt(D)) / 2;
    ll x2 = (b + my_sqrt(D)) / 2;
    if (x1 + x2 != b || x1 * x2 != c) {
        return 0;
    }

    if (x1 == x2) {
        return 1LL * mp[x1] * (mp[x1] - 1) / 2LL;
    }
    return 1LL * mp[x1] * mp[x2];
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        mp.clear();
        cin >> n;
        ll num;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            mp[num]++;
        }
        cin >> q;
        for (int i = 0; i < q; ++i) {
            cin >> x >> y;
            cout << get(x, y) << " \n"[i == q - 1];
        }
    }
}
