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

int dfs_counter, numSCC, ans = 0;
vi dfs_num, dfs_low, S, visited;
vii AL, AL_T;

unordered_map<string, int> M;
int V;
string s;

struct C {
    string name, lang;
    unordered_set<string> understand;
};

vector<C> chars;

void tarjanSCC(int u)
{
    dfs_low[u] = dfs_num[u] = dfs_counter;
    dfs_counter++;
    S.pb(u);
    visited[u] = 1;
    for (auto& v : AL[u]) {
        if (dfs_num[v] == UNVISITED)
            tarjanSCC(v);
        if (visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u] == dfs_num[u]) {
        ++numSCC;
        int count = 0;
        while (1) {
            int v = S.back();
            S.pop_back();
            visited[v] = 0;
            count++;
            if (u == v)
                break;
        }
        ans = max(ans, count);
    }
}

void process()
{
    for (int u = 0; u < V; ++u) {
        getline(cin, s);
        int i = 0, cnt = 0, len;
        string name, can_speak;
        unordered_set<string> understand;
        for (int j = 0; j <= s.size(); ++j) {
            if (s[j] == ' ' || j == s.size() - 1) {
                len = j == s.size() - 1 ? j - i + 1 : j - i;
                if (cnt == 0) {
                    name = s.substr(i, len), M[name] = u;
                } else if (cnt == 1)
                    can_speak = s.substr(i, len);
                else if (cnt > 1)
                    understand.emplace(s.substr(i, len));
                i = j + 1;
                cnt++;
            }
        }
        chars.pb({ name, can_speak, understand });
    }

    AL.assign(V, vi());
    int u, v;

    for (int i = 0; i < V; ++i) {
        u = M[chars[i].name];
        for (int j = 0; j < V; ++j) {
            if (i == j)
                continue;
            v = M[chars[j].name];
            if (chars[i].lang == chars[j].lang) {
                AL[u].pb(v);
            } else if (chars[j].understand.count(chars[i].lang)) {
                AL[u].pb(v);
            }
        }
    }
}

void solve()
{
    dfs_num.assign(V, UNVISITED);
    dfs_low.assign(V, 0);
    visited.assign(V, 0);
    dfs_counter = numSCC = 0;
    for (int u = 0; u < V; ++u) {
        if (dfs_num[u] == UNVISITED) {
            tarjanSCC(u);
        }
    }
}

int main()
{
    fastio;
    getline(cin, s);
    V = stoi(s);
    process();
    solve();
    cout << V - ans << endl;
    return 0;
}