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

unordered_map<string, vector<string>> G;

string changed;
vector<string> res;

unordered_set<string> V;

void proc(string& s)
{
    int del = s.find(':');
    string f = s.substr(0, del);
    if (!G.count(f))
        G[f] = vector<string>();

    int i = del + 2;

    for (int j = del + 2; j < s.size(); ++j) {
        if (j == s.size() - 1 || s[j] == ' ') {
            int last = j == s.size() - 1 ? s.size() : j;
            string dep = s.substr(i, last - i);
            G[dep].pb(f);
            i = j + 1;
        }
    }
}

void dfs(string& s)
{
    if (V.count(s))
        return;

    for (auto& nei : G[s])
        dfs(nei);
    V.insert(s);
    res.pb(s);
}

int main()
{
    fastio;
    int n;
    string line;

    getline(cin, line);
    n = stoi(line);
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        proc(line);
    }

    getline(cin, changed);
    dfs(changed);
    reverse(ALL(res));
    for (auto& f : res)
        cout << f << endl;

    return 0;
}