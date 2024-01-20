
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
vi nums;
int t, n, k;

ll f(int i, int y) {
    if (nums[i] >= y) {
        return 0L;
    }
    if (i == n - 1 && nums[i] < y) {
        return INF;
    }
    return y - nums[i] + f(i + 1, y - 1);
}

bool can(int y) {
    for (int i = 0; i < n; ++i) {
        if (f(i, y) <= k) {
            return true;
        }
    }
    return false;
}

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int l = 0, r = 0;
        nums.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
            r = max(r, nums[i]);
        }
        r += k + 1;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (can(m)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        cout << l - 1 << endl;
    }
}
