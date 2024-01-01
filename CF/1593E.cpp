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

vector<unordered_set<int>> G;

int main()
{
    fastio;
    int t, n, k, u, v;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        G.assign(n + 1, unordered_set<int>());
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> u >> v;
            G[u].insert(v), G[v].insert(u);
        }
        if (n <= 2)
        {
            cout << 0 << endl;
            continue;
        }

        queue<int> q;
        for (int i = 1; i <= n; ++i)
            if (G[i].size() == 1) q.push(i);

        int cnt = n;
        while (q.size() && cnt > 2 && k)
        {
            int sz = q.size();
            for (int i = 0; i < sz; ++i)
            {
                int u = q.front();
                q.pop();
                cnt--;
                if (G[u].size())
                {
                    int v = *G[u].begin();
                    G[u].clear();
                    G[v].erase(u);
                    if (G[v].size() == 1) q.push(v);
                }
            }
            k--;
        }

        if (cnt <= 2)
        {
            if (k) cout << 0;
            else cout << cnt;
        }
        else cout << cnt;
        cout << endl;
    }
    return 0;
}
