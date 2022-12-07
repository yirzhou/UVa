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

class SegmentTree {
private:
    int n;
    vi A, st, lazy;

    int l(int p) { return p << 1; }
    int r(int p) { return (p << 1) + 1; }

    int conquer(int a, int b)
    {
        if (a == -1)
            return b;
        if (b == -1)
            return a;
        return min(a, b);
    }

    void build(int p, int L, int R)
    {
        if (L == R)
            st[p] = A[L];
        else {
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    void propagate(int p, int L, int R)
    {
        if (lazy[p] != -1) {
            st[p] = lazy[p];
            if (L != R)
                lazy[l(p)] = lazy[r(p)] = lazy[p];
            else
                A[L] = lazy[p];
            lazy[p] = -1;
        }
    }

    int RMQ(int p, int L, int R, int i, int j)
    {
        propagate(p, L, R);
        if (i > j)
            return -1;
        if ((L >= i) && (R <= j))
            return st[p];
        int m = (L + R) / 2;
        return conquer(RMQ(l(p), L, m, i, min(m, j)), RMQ(r(p), m + 1, R, max(i, m + 1), j));
    }

    void update(int p, int L, int R, int i, int j, int val)
    {
        propagate(p, L, R);
        if (i > j)
            return;
        if ((L >= i) && (R <= j)) {
            lazy[p] = val;
            propagate(p, L, R);
        } else {
            int m = (L + R) / 2;
            update(l(p), L, m, i, min(m, j), val);
            update(r(p), m + 1, R, max(i, m + 1), j, val);
            int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
            int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
            st[p] = (lsubtree <= rsubtree) ? st[l(p)] : st[r(p)];
        }
    }

public:
    SegmentTree(int sz)
        : n(sz)
        , st(4 * n)
        , lazy(4 * n, -1) {};

    SegmentTree(const vi& initialA)
        : SegmentTree((int)initialA.size())
    {
        A = initialA;
        build(1, 0, n - 1);
    }

    void update(int i, int j, int val)
    {
        update(1, 0, n - 1, i, j, val);
    }

    int RMQ(int i, int j) { return RMQ(1, 0, n - 1, i, j); }
};

vi A;

void print(vi& A)
{
    for (auto& a : A)
        cout << a << " ";
    cout << endl;
}

vi get_idx(string& s, int orig = 1)
{
    int num = 0;
    vi idx;
    for (int j = 6; j < s.size(); ++j) {
        if (s[j] == ',' || j == s.size() - 1) {
            idx.pb(orig ? num : num - 1);
            num = 0;
        } else {
            num = num * 10 + s[j] - '0';
        }
    }
    return idx;
}

void process_shift(string& s, vi& A, SegmentTree& st)
{
    vi idx = get_idx(s, 0);

    int first_val = A[idx[0]];
    for (int i = 0; i < idx.size() - 1; ++i)
        A[idx[i]] = A[idx[i + 1]];
    A[idx.back()] = first_val;

    for (int i = 0; i < idx.size(); ++i) {
        st.update(idx[i], idx[i], A[idx[i]]);
    }
}

int process_query(string& s, SegmentTree& st)
{
    vi idx = get_idx(s);
    return st.RMQ(idx[0] - 1, idx[1] - 1);
}

int main()
{
    fastio;
    int n, q;
    cin >> n >> q;
    string s;
    int upper = pow(2, ceil(log2(n)));
    A.assign(upper, INF);
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    SegmentTree st(A);

    while (q--) {
        cin >> s;
        if (s[0] == 'q') {
            int res = process_query(s, st);
            cout << res << endl;
        } else {
            process_shift(s, A, st);
        }
    }
    return 0;
}