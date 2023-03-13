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
    int t, n;
    int s[200005];
    cin >> t;
    while (t--) {
        cin >> n;
        vi ones;
        for (int i = 0; i < n; ++i) {
            char c;
            cin >> c;
            s[i] = c - '0';
            if (s[i] & 1) ones.pb(i);
        }
        if (n & 1 || s[0] != 1 || s[n - 1] != 1 || ones.size() & 1) {
            cout << "NO\n";
            continue;
        }

        vector<char> ans1(n, '0'), ans2(n, '0');
        for (int i = 0; i < ones.size() / 2; ++i)
            ans1[ones[i]] = ans2[ones[i]] = '(';
        for (int i = ones.size() / 2; i < ones.size(); ++i)
            ans1[ones[i]] = ans2[ones[i]] = ')';
        bool open = true;
        for (int i = 0; i < n; ++i) {
            if (ans1[i] != '0') continue;
            else {
                if (open) ans1[i] = '(', ans2[i] = ')';
                else ans1[i] = ')', ans2[i] = '(';
                open = (open ? false : true);
            }
        }

        cout << "YES\n";
        for (int i = 0; i < n; ++i) cout << ans1[i];
        cout << endl;
        for (int i = 0; i < n; ++i) cout << ans2[i];
        cout << endl;
    }
    return 0;
}
