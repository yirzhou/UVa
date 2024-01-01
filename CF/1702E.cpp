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
#define fastio                                                                                                         \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(0)
#define precision(a)                                                                                                   \
    cout << fixed;                                                                                                     \
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

unordered_map<ll, vl> AL;
int V[200005] = {0};
int dfs(int u)
{
    V[u] = 1;
    for (auto &v : AL[u])
    {
        if (!V[v]) return dfs(v) + 1;
    }
    return 1;
}

int main()
{
    fastio;
    ll t, n, a, b;
    cin >> t;
    while (t--)
    {
        cin >> n;
        AL.clear();
        memset(V, 0, sizeof V);
        bool can = true;
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b;
            AL[a].pb(b), AL[b].pb(a);
            if (a == b || AL[a].size() > 2 || AL[b].size() > 2) { can = false; }
        }

        if (!can) { cout << "NO\n"; }
        else
        {
            for (int u = 1; u <= n; ++u)
            {
                if (!V[u] && dfs(u) % 2 == 1)
                {
                    can = false;
                    break;
                }
            }

            if (!can) { cout << "NO\n"; }
            else cout << "YES\n";
        }
    }
    return 0;
}
