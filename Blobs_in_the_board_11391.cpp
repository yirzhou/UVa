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

ii D[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } };

int r, c, n;

int memo[1 << 16][20];

bool is_one(int mask, int i, int j)
{
    return (mask >> (i * c + j)) & 1;
}

bool check(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}

int count(int mask)
{
    int cnt = 0;

    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if ((mask >> (i * c + j)) & 1)
                cnt++;

    return cnt;
}

int mark(int mask, int i, int j)
{
    return mask | (1 << (i * c + j));
}

int unmark(int mask, int i, int j)
{
    return mask ^ (1 << (i * c + j));
}

int dp(int mask, int k)
{
    if (memo[mask][k] != -1)
        return memo[mask][k];
    if (count(mask) == 1)
        return memo[mask][k] = (k == 0 ? 1 : 0);

    if (k == 0)
        return memo[mask][k] = 0;

    int ans = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (is_one(mask, i, j)) {
                for (auto& [di, dj] : D) {
                    int ni = i + di, nj = j + dj;
                    int nni = ni + di, nnj = nj + dj;
                    if (check(ni, nj) && is_one(mask, ni, nj) && check(nni, nnj) && !is_one(mask, nni, nnj)) {
                        int cmask = mask;
                        // unmark current
                        cmask ^= (1 << (i * c + j));
                        // unmark middle
                        cmask ^= (1 << (ni * c + nj));
                        // mark dest
                        cmask |= (1 << (nni * c + nnj));
                        ans += dp(cmask, k - 1);
                    }
                }
            }
        }
    }

    return memo[mask][k] = ans;
}

int main()
{
    fastio;
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case " << t << ": ";
        cin >> r >> c >> n;
        int br, bc;
        int mask = 0;
        for (int i = 0; i < n; ++i) {
            cin >> br >> bc;
            br--, bc--;
            mask = mark(mask, br, bc);
        }
        memset(memo, -1, sizeof memo);
        cout << dp(mask, n - 1) << endl;
    }

    return 0;
}
