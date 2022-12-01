#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
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

int n, l, r;
string s, target;
map<string, int> d1, d2;

vector<string> get_neighbors(string& s)
{
    int n = s.size();
    vector<string> neighbors;

    for (int len = 1; len <= n - 1; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            string rest = s.substr(0, i) + s.substr(i + len, n - i - len + 1);
            string comp = s.substr(i, len);
            int m = rest.size();
            for (int k = 0; k < m; ++k) {
                string a = rest.substr(0, k), c = rest.substr(k, m - k);
                string neighbor = a + comp + c;
                neighbors.pb(neighbor);
            }
        }
    }

    return neighbors;
}

int bfs(string& start, string& end, bool forward = true)
{
    queue<pair<string, int>> q;
    q.push({ start, 0 });

    while (q.size()) {
        string s = q.front().fi;
        int depth = q.front().se;
        q.pop();
        if (depth > 2)
            break;
        if (s == end)
            return depth;

        if (forward) {
            if (d1.count(s))
                continue;
            d1[s] = depth;
            for (auto& nei : get_neighbors(s)) {
                if (!d1.count(nei)) {
                    q.push({ nei, depth + 1 });
                }
            }
        } else {
            if (d2.count(s))
                continue;
            d2[s] = depth;
            for (auto& nei : get_neighbors(s)) {
                if (!d2.count(nei)) {
                    q.push({ nei, depth + 1 });
                }
            }
        }
    }

    return -1;
}

int main()
{
    fastio;
    int caseno = 1;
    while (cin >> n && n) {
        int val;
        s.clear(), target.clear(), d1.clear(), d2.clear();
        for (int i = 0; i < n; ++i) {
            cin >> val;
            s.pb(val + '0');
            target.pb((i + 1) + '0');
        }

        int res = bfs(s, target);
        if (res == -1) {
            res = bfs(target, s, false);
        }

        if (res == -1) {
            res = 5;
            for (auto& [u1, p1] : d1) {
                if (d2.count(u1)) {
                    res = min(res, p1 + d2[u1]);
                }
            }
        }
        if (res == -1)
            res = 5;
        printf("Case %d: %d\n", caseno++, res);
    }
}