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

int t, n;
char AL[51][51];

string memo[51][51];
int V[51][51];

string dp(int i, int j)
{
    string ans = "";
    if (V[i][j] != -1)
        return memo[i][j];
    if (i == j) {
        V[i][j] = 0;
        return memo[i][j] = "";
    }

    int maxlen = 1;
    ans = AL[i][j];

    for (int k = i; k <= j; ++k) {
        char a = AL[i][k];
        for (int l = j; l >= k; --l) {
            char b = AL[l][j];
            if (a != '*' && a == b) {
                string mid = dp(k, l), nstr = a + mid + a;
                int nlen = 2 + mid.size();
                if (nlen > maxlen) {
                    maxlen = nlen, ans = nstr;
                } else if (nlen == maxlen) {
                    if (nstr < ans)
                        ans = nstr;
                }
            }
        }
    }

    V[i][j] = maxlen, memo[i][j] = ans;

    return ans;
}

int main()
{
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 51; ++i)
            fill(memo[i], memo[i] + 51, "");
        memset(V, -1, sizeof V);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> AL[i][j];
            }
        }

        string ans = dp(0, n - 1);
        if (ans.size())
            cout << ans << endl;
        else
            cout << "NO PALINDROMIC PATH\n";
    }

    return 0;
}
