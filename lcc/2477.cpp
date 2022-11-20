#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;

class Solution {
public:
    vector<vi> G;
    ll ans;
    int cap;

    int dfs(int prev, int u, int people = 1)
    {
        for (auto& v : G[u]) {
            if (v != prev)
                people += dfs(u, v);
        }
        ans += (u ? (ll)ceil((double)people / cap) : 0);
        return people;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats)
    {
        int n = roads.size() + 1;
        G = vector<vi>(n);
        cap = seats;
        for (auto& p : roads) {
            int u = p[0], v = p[1];
            G[u].push_back(v);
            G[v].push_back(u);
        }

        dfs(0, 0);

        return ans;
    }
};

int main()
{
    Solution sol = Solution();
    // [[0,1],[0,2],[1,3],[3,4],[0,5],[6,3],[5,7],[3,8]]
    // 8
    vector<vi> roads = { { 0, 1 }, { 0, 2 }, { 1, 3 }, { 3, 4 }, { 0, 5 }, { 6, 3 }, { 5, 7 }, { 3, 8 } };
    int seats = 8;

    ll res = sol.minimumFuelCost(roads, seats);
    cout << res << endl;
}