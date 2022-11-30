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

#define MAX 64

ll AdjMat[MAX] = { 0 };
ll mxS = 0, V = 0, ns = 0;
void rec(ll i, ll used, ll depth)
{
    if (used == ((ll)1 << V) - (ll)1) {
        ns++;
        mxS = max(mxS, depth);
    } else {
        for (ll j = i; j < V; ++j) {
            if (!(used & ((ll)1 << j))) {
                rec(j + 1, used | AdjMat[j], depth + 1);
            }
        }
    }
}

int main()
{
    fastio;
    ll T, i, r;
    cin >> T;
    while (T--) {
        memset(AdjMat, 0, sizeof(AdjMat));
        mxS = 0, ns = 0;
        cin >> i >> r;
        V = i;
        for (ll j = 0; j < i; ++j)
            AdjMat[j] |= ((ll)1 << j);
        ll u, v;
        for (ll j = 0; j < r; ++j) {
            cin >> u >> v;
            AdjMat[u] |= ((ll)1 << v);
            AdjMat[v] |= ((ll)1 << u);
        }

        rec(0, 0, 0);
        cout << ns << endl;
        cout << mxS << endl;
    }
}