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

int f(string &s) {
    int n = s.size();
    char c = 0;
    int ans = -1;
    if (n == 1) return ans;
    for (int i = 0; i < n; ++i) {
        char cur = s[i];
        if (i == 0) {
            char nxt = s[i + 1];
            if (nxt == cur - 1) {
                if (cur >= c) {
                    ans = i;
                    c = cur;
                }
            }

        } else if (i == n - 1) {
            char prev = s[i - 1];
            if (prev == cur - 1) {
                if (cur >= c) {
                    ans = i;
                    c = cur;
                }
            }
        } else {
            char nxt = s[i + 1];
            char prev = s[i - 1];
            if (prev == cur - 1 || nxt == cur - 1) {
                if (cur >= c) {
                    ans = i;
                    c = cur;
                }
            }
        }
    }

    return ans;
}

int main() {
    fastio;
    int len;
    string s;
    cin >> len;
    for (int i = 0; i < len; ++i) {
        char c;
        cin >> c;
        s.pb(c);
    }

    int pos = f(s), ans = 0;
    while (pos != -1) {
        ans++;
        s.erase(pos, 1);
        pos = f(s);
    }

    cout << ans << endl;
}
