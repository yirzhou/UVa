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

#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define fastio                                                                 \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(0)
#define precision(a)                                                           \
    cout << fixed;                                                             \
    cout.precision(a)

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define pll(a, b) printf("%lld %lld\n", a, b)
#define plll(a, b, c) printf("%lld %lld %lld\n", a, b, c)
#define oo INT_MAX
#define UNVISITED -1
#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;

ii D[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int f(vvi &arr, int x) {
    int n = arr.size(), i = 0;
    for (int j = 0; j < n; ++j) {
        int a = arr[j][1], b = arr[j][2];
        if (x - 1 - a <= i && i <= b) { i++; }
    }
    return i >= x;
}

int main() {
    fastio;
    int t, n, a, b;
    cin >> t;
    while (t--) {
        cin >> n;
        vvi vec(n);
        for (int i = 1; i <= n; ++i) {
            cin >> a >> b;
            vec[i - 1] = {i, a, b};
        }

        int lo = 0, hi = n + 1, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (f(vec, mid)) lo = mid + 1;
            else hi = mid;
        }

        cout << lo - 1 << endl;
    }
}
