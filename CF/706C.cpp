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
#define MOD 1000000007

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define pll(a, b) printf("%lld %lld\n", a, b)
#define plll(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define fastio                                                                 \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(0)
#define precision(a)                                                           \
    cout << fixed;                                                             \
    cout.precision(a)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;

vector<string> S;
vl C;

const ll _INF = 1e14 + 5;

ll memo[2][100005];

string reverse(string &s) {
    string ans(s);
    reverse(ALL(ans));
    return ans;
}

ll dp(int prev_reversed, int i) {
    if (i == S.size()) return 0LL;
    if (memo[prev_reversed][i] != -1) return memo[prev_reversed][i];
    string prev = prev_reversed ? reverse(S[i - 1]) : S[i - 1], cur = S[i];
    ll ans = _INF;
    if (cur >= prev) ans = dp(0, i + 1);
    if (reverse(cur) >= prev) ans = min(ans, C[i - 1] + dp(1, i + 1));
    return memo[prev_reversed][i] = ans;
}

int main() {
    fastio;
    int n;
    cin >> n;
    C.assign(n, 0);
    S.assign(n + 1, "");
    for (int i = 0; i < n; ++i) cin >> C[i];
    for (int i = 1; i <= n; ++i) cin >> S[i];
    memset(memo, -1, sizeof memo);
    ll ans = dp(0, 1);
    cout << (ans >= _INF ? -1 : ans) << endl;
    return 0;
}
