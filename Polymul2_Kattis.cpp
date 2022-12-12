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
typedef complex<double> cd;

const double PI = acos(-1.0);

void pre(vi& polynomial)
{
    int sz = 1 << (int)ceil(log2((double)polynomial.size()));
    while (polynomial.size() < sz)
        polynomial.pb(0);
}

void FFT(vector<cd>& A)
{
    int n = A.size();
    if (n == 1)
        return;

    vector<cd> A0(n / 2), A1(n / 2);

    for (int k = 0; 2 * k < n; ++k) {
        A0[k] = A[2 * k];
        A1[k] = A[2 * k + 1];
    }

    FFT(A0);
    FFT(A1);

    for (int k = 0; 2 * k < n; ++k) {
        cd x = cd(cos(2 * PI * k / n), sin(2 * PI * k / n));
        A[k] = A0[k] + x * A1[k];
        A[k + n / 2] = A0[k] - x * A1[k];
    }
}

vector<cd> FFT(vi& polynomial)
{
    pre(polynomial);
    vector<cd> A(polynomial.begin(), polynomial.end());
    FFT(A);
    return A;
}

void IFFT(vector<cd>& A)
{
    for (auto& p : A)
        p = conj(p);

    FFT(A);

    for (auto& p : A)
        p = conj(p);

    for (auto& p : A)
        p /= A.size();
}

vector<cd> IFFT(vi& polynomial)
{
    pre(polynomial);
    vector<cd> A(polynomial.begin(), polynomial.end());
    IFFT(A);
    return A;
}

vi multiply(vi& p1, vi& p2)
{
    int n = 1;
    while (n < p1.size() + p2.size() - 1)
        n <<= 1;

    vector<cd> A(p1.begin(), p1.end());
    vector<cd> B(p2.begin(), p2.end());

    A.resize(n);
    B.resize(n);

    FFT(A);
    FFT(B);

    vector<cd> C(n);
    for (int k = 0; k < n; ++k)
        C[k] = A[k] * B[k];

    IFFT(C);

    vi res;
    for (auto& p : C)
        res.pb(round(p.real()));

    res.resize(p1.size() + p2.size() - 1);

    return res;
}

int main()
{
    fastio;
    int T;
    cin >> T;

    int n1, n2;
    cin >> n1;
    vi p1(n1 + 1);
    for (int i = 0; i <= n1; ++i) {
        cin >> p1[i];
    }

    cin >> n2;
    vi p2(n2 + 1);
    for (int i = 0; i <= n2; ++i) {
        cin >> p2[i];
    }

    vi res = multiply(p1, p2);
    cout << res.size() - 1 << endl;

    for (int i = 0; i < res.size() - 1; ++i)
        cout << res[i] << " ";
    cout << res.back() << endl;
    return 0;
}