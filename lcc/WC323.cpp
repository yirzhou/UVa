#include <bits/stdc++.h>

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

ii D[] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

int V[1005][1005];

struct cmp {
    bool operator()(const vi& a, const vi& b)
    {
        return a[0] > b[0];
    }
};

class Solution {
public:
    int R, C;

    vi order;

    void proc(vii& grid)
    {
        priority_queue<vi, vii, cmp> q;
        q.push({ grid[0][0], 0, 0 });
        memset(V, 0, sizeof V);

        while (q.size()) {
            int val = q.top()[0], i = q.top()[1], j = q.top()[2];
            q.pop();
            if (V[i][j])
                continue;
            V[i][j] = 1;
            order.pb(val);

            for (auto& [di, dj] : D) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < R && nj >= 0 && nj < C && !V[ni][nj])
                    q.push({ grid[ni][nj], ni, nj });
            }
        }

        int maxsf = INT_MIN;
        for (int i = 0; i < order.size(); ++i) {
            maxsf = max(maxsf, order[i]);
            order[i] = maxsf;
        }
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries)
    {
        int k = queries.size();
        R = grid.size(), C = grid[0].size();

        vi ans(k, 0);
        proc(grid);

        for (int i = 0; i < k; ++i) {
            auto it = lower_bound(ALL(order), queries[i]);
            ans[i] = it - order.begin();
        }

        return ans;
    }
};