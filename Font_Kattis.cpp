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

int N;

vi AL;

int ans = 0;

void backtrack(int m1, int m2, int i, int depth)
{
    if ((m1 | m2) == ((1 << 26) - 1)) {
        ans++;
    }

    if (i == N)
        return;

    // Put into current set
    backtrack(m1 | AL[i], 0, i + 1, depth);
    // Start a new set
    backtrack(m1, AL[i], i + 1, depth + 1);
}

int main()
{
    fastio;
    cin >> N;
    AL = vi(N, 0);
    string s;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        for (auto& c : s)
            AL[i] |= (1 << (c - 'a'));
    }

    backtrack(0, 0, 0, 1);
    cout << ans / 2 << endl;
    return 0;
}