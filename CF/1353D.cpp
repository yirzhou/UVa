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

struct cmp {
    // [l,r]
    bool operator()(const vi &a, const vi &b) {
        int l1 = a[1] - a[0], l2 = b[1] - b[0];
        if (l1 == l2) return a[0] > b[0];
        return l1 < l2;
    }
};

int main() {
    fastio;
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vi ans(n);
        priority_queue<vi, vvi, cmp> pq;
        pq.push({0, n - 1});
        int i = 1;
        while (pq.size() && i <= n) {
            int l = pq.top()[0], r = pq.top()[1];
            pq.pop();
            int len = r - l + 1;
            int mid = (len % 2 == 1) ? (l + r) / 2 : (l + r - 1) / 2;
            if (len % 2 == 1) ans[mid] = i++;
            else ans[mid] = i++;

            if (mid - 1 >= l) pq.push({l, mid - 1});
            if (mid + 1 <= r) pq.push({mid + 1, r});
        }

        cout << ans[0];
        for (int i = 1; i < ans.size(); ++i) cout << " " << ans[i];
        cout << endl;
    }
    return 0;
}
