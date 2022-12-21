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

int I, C, O;
vi items;
vii combos, orders;

string str(vi& order)
{
    string res;
    for (int i = 0; i < I; ++i)
        res.pb(order[i] + '0');
    return res;
}

unordered_map<string, ll> memo;

bool check(int c, string& s)
{
    for (int i = 0; i < I; ++i)
        if (s[i] < combos[c][i] + '0')
            return false;
    return true;
}

string target;

ll f(string& mask)
{
    if (mask == target) {
        return 0;
    }

    if (memo.count(mask))
        return memo[mask];
    ll ans = INT_MAX;

    for (int i = 0; i < I; ++i) {
        if (mask[i] > '0') {
            mask[i]--;
            ans = min(ans, items[i] + f(mask));
            mask[i]++;
        }
    }

    for (int c = 0; c < C; ++c) {
        if (check(c, mask)) {
            for (int i = 0; i < I; ++i)
                mask[i] -= combos[c][i];
            ans = min(ans, combos[c].back() + f(mask));
            for (int i = 0; i < I; ++i)
                mask[i] += combos[c][i];
        }
    }

    return memo[mask] = ans;
}

int create_mask(vi& order)
{
    int num = 0;
    for (int i = 0; i < I; ++i)
        num = num * 10 + order[i];
    return num;
}

int main()
{
    fastio;
    while (cin >> I) {
        target.clear();
        memo.clear();
        for (int i = 0; i < I; ++i)
            target.pb('0');
        items.assign(I, 0);
        for (int i = 0; i < I; ++i)
            cin >> items[i];
        cin >> C;
        combos = vii(C, vi(I + 1, 0));
        for (int i = 0; i < C; ++i) {
            for (int j = 0; j < I; ++j)
                cin >> combos[i][j];
            cin >> combos[i][I];
        }

        cin >> O;
        orders = vii(O, vi(I, 0));
        for (int i = 0; i < O; ++i) {
            for (int j = 0; j < I; ++j)
                cin >> orders[i][j];
        }

        ll res = 0;
        for (int o = 0; o < O; ++o) {
            string mask = str(orders[o]);
            res = f(mask);
            cout << res << endl;
        }
    }

    return 0;
}
