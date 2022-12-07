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

int n, q;
char c;

int main()
{
    fastio;

    cin >> n >> q;
    vector<FenwickTree> ft(7, FenwickTree(n + 1));
    vi V(7, 0), C(7, 0), M(n + 1);
    for (int i = 1; i <= 6; ++i)
        cin >> V[i];

    for (int i = 1; i <= n; ++i) {
        cin >> c;
        ft[c - '0'].update(i, 1);
        M[i] = c - '0';
    }

    int qt, k, p, v, l, r;
    while (q--) {
        cin >> qt;
        if (qt == 1) {
            cin >> k >> p;
            int old = M[k];
            // Erase it from this type
            ft[old].update(k, -1);
            // Add it to the new type
            ft[p].update(k, 1);
            M[k] = p;
        } else if (qt == 2) {
            cin >> p >> v;
            V[p] = v;
        } else {
            cin >> l >> r;
            ll sum = 0;
            for (int i = 1; i <= 6; ++i)
                sum += ft[i].rsq(l, r) * V[i];
            cout << sum << endl;
        }
    }

    return 0;
}