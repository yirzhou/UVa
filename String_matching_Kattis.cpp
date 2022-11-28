#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
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

int extEuclid(int a, int b, int& x, int& y)
{
    int xx = y = 0;
    int yy = x = 1;
    while (b) {
        int q = a / b;
        int t = b;
        b = a % b;
        a = t;
        t = xx;
        xx = x - q * xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a;
}

int mod(int a, int m)
{
    return ((a % m) + m) % m;
}
int modInverse(int b, int m)
{
    int x, y;
    int d = extEuclid(b, m, x, y);
    if (d != 1)
        return -1;
    return mod(x, m);
}

class RH {
    vi P;
    vi h;
    const int p = 131, M = 1e9 + 7;

public:
    RH() { }

    void prepareP(int n)
    {
        P.assign(n, 0);
        P[0] = 1;
        for (int i = 1; i < n; ++i) {
            P[i] = ((ll)P[i - 1] * p) % M;
        }
    }

    void compute_rolling_hash(string& T)
    {
        prepareP(T.length());
        h = vi(T.size(), 0);
        for (int i = 0; i < T.length(); ++i) {
            if (i != 0)
                h[i] = h[i - 1];
            h[i] = (h[i] + ((ll)T[i] * P[i])) % M;
        }
    }

    ll hash_fast(int L, int R)
    {
        if (L == 0)
            return h[R];
        ll ans = 0;
        ans = ((h[R] - h[L - 1]) % M + M) % M;
        ans = ((ll)ans * modInverse(P[L], M)) % M;
        return ans;
    }
};

string pattern, text;

int main()
{
    fastio;
    while (getline(cin, pattern) && pattern.size()) {
        getline(cin, text);
        RH rh1, rh2;
        rh1.compute_rolling_hash(pattern), rh2.compute_rolling_hash(text);
        ll target = rh1.hash_fast(0, pattern.size() - 1);
        int N = pattern.size();
        int cnt = 0;
        for (int i = 0; i < text.size() - N + 1; ++i) {
            ll hash = rh2.hash_fast(i, i + N - 1);

            if (hash == target) {
                if (cnt++)
                    cout << " ";
                cout << i;
            }
        }

        cout << endl;
    }
}