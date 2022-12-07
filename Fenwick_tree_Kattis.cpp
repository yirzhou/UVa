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
    cin.tie(nullptr)
#define precision(a) \
    cout << fixed;   \
    cout.precision(a)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vll;

#define LSOne(S) ((S) & -(S))

int n, q;

#define LSOne(S) ((S) & -(S))

class FenwickTree {
private:
    vll ft;

public:
    FenwickTree(int m) { ft.assign(m + 1, 0); }

    FenwickTree(const vll& f) { build(f); }

    FenwickTree(int m, const vll& s)
    {
        vll f(m + 1, 0);
        for (int i = 0; i < s.size(); ++i)
            ++f[s[i]];
        build(f);
    }

    void build(const vll& f)
    {
        int m = (int)f.size() - 1;
        ft.assign(m + 1, 0);
        for (int i = 1; i <= m; ++i) {
            ft[i] += f[i];
            if (i + LSOne(i) <= m)
                ft[i + LSOne(i)] += ft[i];
        }
    }

    ll rsq(int j)
    {
        ll sum = 0;
        for (; j > 0; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }

    ll rsq(int i, int j)
    {
        return rsq(j) - rsq(i - 1);
    }

    void update(int i, int j)
    {
        for (; i < (int)ft.size(); i += LSOne(i))
            ft[i] += j;
    }

    int select(ll k)
    {
        int lo = 1, hi = ft.size() - 1;
        for (int i = -0; i < 30; ++i) {
            int mid = (lo + hi) / 2;
            (rsq(1, mid) < k) ? lo = mid : hi = mid;
        }
        return hi;
    }
};

int main()
{
    fastio;
    cin >> n >> q;
    FenwickTree ft(n + 1);
    char op;
    ll val;
    int i;
    while (q--) {
        cin >> op;
        if (op == '?') {
            cin >> i;
            ll res = ft.rsq(i);
            cout << res << endl;
        } else {
            cin >> i >> val;
            ft.update(i + 1, val);
        }
    }

    return 0;
}