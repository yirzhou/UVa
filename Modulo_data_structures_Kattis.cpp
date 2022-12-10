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

#define MAXN 200005

int A[MAXN] = { 0 };
int N, Q, a, b, c, d, t, sqrt_n;

vii buckets;

int main()
{
    fastio;
    cin >> N >> Q;
    sqrt_n = sqrt(N) + 1;
    buckets.assign(sqrt_n + 1, vi(sqrt_n + 1, 0));
    for (int q = 0; q < Q; ++q) {
        cin >> t;
        if (t == 1) {
            cin >> a >> b >> c;
            if (b <= sqrt_n) {
                buckets[b][a] += c;
            } else {
                for (int j = a; j <= N; j += b)
                    A[j] += c;
            }
        } else {
            cin >> d;
            int res = A[d];
            for (int b = 1; b <= sqrt_n; ++b)
                res += buckets[b][d % b];
            cout << res << endl;
        }
    }
    return 0;
}