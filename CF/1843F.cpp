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
vi pre, nums, changes;
vvi segs;

bool f(int c) {
    int n = nums.size();
    nums.assign(n, 0);
    pre.assign(n + 1, 0);
    for (int i = 0; i < c; ++i) {
        nums[changes[i]]++;
    }

    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + nums[i - 1];
    }
    for (auto &v : segs) {
        int l = v[0], r = v[1];
        int d = r - l + 1;
        int sum = pre[r + 1] - pre[l];
        if (sum > (d - sum)) {
            return true;
        }
    }
    return false;
}

int main() {
    fastio;
    int t, m, n, l, r, q;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        nums.assign(n, 0);
        pre.assign(n + 1, 0);
        segs = vvi(m);
        for (int i = 0; i < m; ++i) {
            cin >> l >> r;
            segs[i] = {l - 1, r - 1};
        }
        cin >> q;
        changes = vi(q);
        for (int i = 0; i < q; ++i) {
            cin >> changes[i];
            changes[i]--;
        }

        int lo = 0, hi = q + 1, m;
        while (lo < hi) {
            m = lo + (hi - lo) / 2;
            if (f(m)) {
                hi = m;
            } else {
                lo = m + 1;
            }
        }
        cout << (hi == q + 1 ? -1 : lo) << endl;
    }
}
