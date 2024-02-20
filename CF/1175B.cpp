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

bool overflow = 0;
ll MAX_VAL = (1LL << 32) - 1;
int n;
int idx = 0;

vector<pair<string, ll>> vec;

ll dfs() {
    ll ans = 0LL;
    while (idx < n) {
        pair<string, ll> p = vec[idx++];
        string s = p.fi;
        ll mult = p.se;
        if ('a' == s[0]) {
            // ADD
            ans++;
        } else if ('f' == s[0]) {
            // FOR
            ans += mult * dfs();
        } else {
            // END
            break;
        }
        if (ans > (1LL << 32) - 1) {
            overflow = true;
            return ans;
        }
    }
    return ans;
}

int main() {
    fastio;
    cin >> n;
    idx = 0;
    vec.assign(n, make_pair<>("", 0ll));
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> vec[i].fi;
        if ('f' == vec[i].fi[0]) {
            cin >> vec[i].se;
        }
    }

    ll ans = dfs();
    if (overflow) {
        cout << "OVERFLOW!!!";
    } else {
        cout << ans;
    }
    cout << endl;
}
