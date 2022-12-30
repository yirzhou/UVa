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

int s, m, n;

vii teachers, apps;

ll memo[105][2 << 16];

int f(int i, ll mask)
{
    if (((mask >> (2 * i)) & 1) == 0)
        return 2 * i;

    if (((mask >> (2 * i + 1)) & 1) == 0)
        return 2 * i + 1;

    return -1;
}

void mark(int i, ll& mask)
{
    if (((mask >> (2 * i)) & 1) == 0)
        mask |= 1 << (2 * i);
    else if (((mask >> (2 * i + 1)) & 1) == 0)
        mask |= 1 << (2 * i + 1);
}

ll dp(ll i, ll mask)
{
    if (mask == (1 << (2 * s)) - 1)
        return 0;
    if (i == n)
        return INT_MAX;

    if (memo[i][mask] != -1)
        return memo[i][mask];

    ll cmask = mask;

    ll cost = apps[i][0];
    for (int j = 1; j < apps[i].size(); ++j)
        mark(apps[i][j] - 1, cmask);

    ll ans = min(cost + dp(i + 1, cmask), dp(i + 1, mask));
    return memo[i][mask] = ans;
}

bool proc(string& line)
{
    int num = 0, i = 0;
    for (int j = 0; j < line.size(); ++j) {
        if (line[j] >= '0' && line[j] <= '9')
            num = num * 10 + line[j] - '0';
        if (line[j] == ' ' || j == line.size() - 1) {
            if (i == 0)
                s = num;
            else if (i == 1)
                m = num;
            else
                n = num;

            num = 0;
            i++;
        }
    }

    return true;
}

void proc_t(string& line, int id)
{
    int num = 0;

    for (int j = 0; j < line.size(); ++j) {
        if (line[j] >= '0' && line[j] <= '9')
            num = num * 10 + line[j] - '0';
        if (line[j] == ' ' || j == line.size() - 1) {
            teachers[id].pb(num), num = 0;
        }
    }
}

void proc_a(string& line, int id)
{
    int num = 0;

    for (int j = 0; j < line.size(); ++j) {
        if (line[j] >= '0' && line[j] <= '9')
            num = num * 10 + line[j] - '0';
        if (line[j] == ' ' || j == line.size() - 1) {
            apps[id].pb(num), num = 0;
        }
    }
}

int main()
{
    fastio;

    string line;
    while (getline(cin, line)) {
        proc(line);
        if (!(s || m || n))
            break;

        teachers.assign(m, vi());
        apps.assign(n, vi());
        ll tcost = 0, mask = 0;
        for (int i = 0; i < m; ++i) {
            getline(cin, line);
            proc_t(line, i);
            tcost += *teachers[i].begin();
            for (int j = 1; j < teachers[i].size(); ++j)
                mark(teachers[i][j] - 1, mask);
        }

        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            proc_a(line, i);
        }

        memset(memo, -1, sizeof memo);
        tcost += dp(0, mask);
        cout << tcost << endl;
    }

    return 0;
}
