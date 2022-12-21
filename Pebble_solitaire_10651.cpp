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

int memo[1 << 12];

int dp(int mask)
{
    if (memo[mask] != -1)
        return memo[mask];
    int count = 0;
    for (int i = 0; i <= 11; ++i)
        if ((mask >> i) & 1)
            count++;

    int a, b, c;
    for (int i = 9; i >= 0; --i) {
        a = (mask >> (12 - i - 1)) & 1, b = (mask >> (12 - i - 2)) & 1, c = (mask >> (12 - i - 3)) & 1;

        if (!a && b && c) {
            count = min(count, dp(((mask | (1 << (12 - i - 1))) ^ (1 << (12 - i - 2))) ^ (1 << (12 - i - 3))));
        }

        if (!c && a && b) {
            count = min(count, dp(((mask | (1 << (12 - i - 3))) ^ (1 << (12 - i - 2))) ^ (1 << (12 - i - 1))));
        }
    }

    return memo[mask] = count;
}

int main()
{
    fastio;
    int n;
    cin >> n;
    while (n--) {
        char c;
        int mask = 0;
        memset(memo, -1, sizeof memo);
        for (int i = 11; i >= 0; --i) {
            cin >> c;
            if (c == 'o')
                mask |= (1 << i);
        }

        int res = dp(mask);
        cout << res << endl;
    }
    return 0;
}
