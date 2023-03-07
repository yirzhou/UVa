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

ii D[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main() {
    fastio;
    int n;
    cin >> n;
    vl A(n), B(n), pre(n + 1, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + A[i - 1] * B[i - 1];
    ll ans = pre.back();
    for (int i = 0; i < n; ++i) {
        ll s = A[i] * B[i];
        for (int len = 1; len <= min(i, n - i - 1); ++len) {
            int l = i - len, r = i + len;
            s += A[r] * B[l] + A[l] * B[r];
            ans = max(ans, pre[l] + s + pre.back() - pre[r + 1]);
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        int j = i + 1;
        ll s = 0;
        for (int len = 0; len <= min(i, n - j - 1); ++len) {
            int l = i - len, r = j + len;
            s += A[r] * B[l] + A[l] * B[r];
            ans = max(ans, pre[l] + s + pre.back() - pre[r + 1]);
        }
    }
    cout << ans << endl;

    return 0;
}
