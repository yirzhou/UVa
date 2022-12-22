#include <algorithm>
#include <assert.h>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

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

int n, a, b, c, s, caseno = 1, ans = -1;
vii C;

int V[85];

void f(int m1, int score)
{
    if (m1 == (1 << 9) - 1) {
        ans = max(ans, score);
    }

    for (int i = 0; i < n; ++i) {
        if (V[i])
            continue;
        if ((C[i][0] & m1) == 0) {
            V[i] = 1;
            f(m1 | C[i][0], C[i][1] + score);
            V[i] = 0;
        }
    }
}

int main()
{
    fastio;
    while (cin >> n && n) {
        memset(V, 0, sizeof V);
        cout << "Case " << caseno++ << ": ";
        C = vii(n);
        for (int i = 0; i < n; ++i) {
            cin >> a >> b >> c >> s;
            a--, b--, c--;
            C[i] = { (1 << a) | (1 << b) | (1 << c), s };
        }
        ans = -1;
        f(0, 0);
        cout << ans << endl;
    }

    return 0;
}
