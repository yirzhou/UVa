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

int cases;
string x, z;

bool V[10005][105];
string memo[10005][105];

string add(string& a, string& b)
{
    string res;
    reverse(ALL(a));
    reverse(ALL(b));
    int carry = 0;
    int i, j;
    for (i = 0, j = 0; i < a.size() && j < b.size(); ++i, ++j) {
        int d = a[i] - '0' + b[j] - '0' + carry;
        if (d > 9)
            carry = 1, d -= 10;
        else
            carry = 0;

        res.pb('0' + d);
    }

    while (i < a.size()) {
        int d = a[i++] - '0' + carry;
        if (d > 9)
            carry = 1, d -= 10;
        else
            carry = 0;
        res.pb('0' + d);
    }

    while (j < b.size()) {
        int d = b[j++] - '0' + carry;
        if (d > 9)
            carry = 1, d -= 10;
        else
            carry = 0;
        res.pb('0' + d);
    }

    if (carry)
        res.pb('1');

    reverse(ALL(res));
    return res;
}

string dp(int i, int j)
{
    if (V[i][j])
        return memo[i][j];
    if (j == z.size()) {
        V[i][j] = 1;
        return memo[i][j] = "1";
    }
    if (i == x.size()) {
        V[i][j] = 1;
        return memo[i][j] = "0";
    }

    string ans = "0";
    for (int k = i; k < x.size(); ++k)
        if (x[k] == z[j]) {
            string b = dp(k + 1, j + 1);
            ans = add(ans, b);
        }
    V[i][j] = 1;
    return memo[i][j] = ans;
}

int main()
{
    fastio;

    cin >> cases;
    while (cases--) {
        memset(V, 0, sizeof V);
        cin >> x >> z;
        string ans = dp(0, 0);
        cout << ans << endl;
    }

    return 0;
}
