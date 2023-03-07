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
bool AL[26][26];
int degree[26], V[26];

int main() {
    fastio;
    int n;
    cin >> n;
    vector<string> names(n);
    memset(AL, 0, sizeof AL);
    memset(degree, 0, sizeof degree);
    memset(V, 0, sizeof V);
    for (int i = 0; i < n; ++i) cin >> names[i];

    for (int i = 1; i < n; ++i) {
        string a = names[i - 1], b = names[i];
        int len = min(a.size(), b.size()), j = 0;
        for (; j < len; ++j) {
            if (a[j] != b[j]) {
                AL[a[j] - 'a'][b[j] - 'a'] = 1, V[a[j] - 'a'] = 1,
                                      V[b[j] - 'a'] = 1;
                break;
            }
        }

        if (j == b.size()) {
            cout << "Impossible\n";
            return 0;
        }
    }

    for (int u = 0; u < 26; ++u)
        for (int v = 0; v < 26; ++v)
            if (AL[u][v]) degree[v]++;

    queue<int> q;
    for (int u = 0; u < 26; ++u)
        if (degree[u] == 0) q.push(u);

    vi ans;
    while (q.size()) {
        int u = q.front();
        q.pop();
        ans.pb(u);
        for (int v = 0; v < 26; ++v) {
            if (AL[u][v])
                if (--degree[v] == 0) q.push(v);
        }
    }
    if (ans.size() != 26) cout << "Impossible";
    else
        for (auto &u : ans) cout << char(u + 'a');

    cout << endl;

    return 0;
}
