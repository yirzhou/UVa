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

int n, m;

vi A, B, C;

void print(vi& A)
{
    for (int i = 0; i < A.size(); ++i) {
        if (i)
            cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void print()
{
    cout << "A=>";
    if (A.size())
        cout << "   ";
    print(A);

    cout << "B=>";
    if (B.size())
        cout << "   ";
    print(B);

    cout << "C=>";
    if (C.size())
        cout << "   ";
    print(C);
    cout << endl;
}

void solve(int count, vi& src, vi& dst, vi& intm)
{
    if (m == 0)
        return;

    if (count == 1) {
        dst.pb(src.back());
        src.pop_back();

        m--;
        print();
        return;
    }

    solve(count - 1, src, intm, dst);
    solve(1, src, dst, intm);
    solve(count - 1, intm, dst, src);
}

int main()
{
    fastio;
    int t = 1;
    while (cin >> n >> m && (n | m)) {
        A.clear(), B.clear(), C.clear();
        for (int i = n; i >= 1; --i)
            A.pb(i);
        cout << "Problem #" << t++ << endl
             << endl;
        print();
        solve(n, A, C, B);
    }

    return 0;
}