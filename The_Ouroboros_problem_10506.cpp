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

int M, N;
vii AL;

vector<string> seq;

void backtrack(vector<char> s)
{
    if (s.size() == M) {
        string str = "";
        for (auto& c : s)
            str += c;
        seq.pb(str);
        return;
    }

    for (char c = '0'; c < '0' + N; ++c) {
        s.pb(c);
        backtrack(s);
        s.pop_back();
    }
}

vi hierholzer(int s)
{
    int n = AL.size();
    vi ans, idx(n, 0), st;
    st.pb(s);

    while (!st.empty()) {
        int u = st.back();
        if (idx[u] < (int)AL[u].size()) {
            st.pb(AL[u][idx[u]]);
            ++idx[u];
        } else {
            ans.pb(u);
            st.pop_back();
        }
    }

    reverse(ALL(ans));
    return ans;
}

int main()
{
    fastio;
    string line;
    while (getline(cin, line) && line.size()) {
        int sp = line.find(' ');
        M = stoi(line.substr(0, sp)) - 1, N = stoi(line.substr(sp + 1));
        seq.clear();
        vector<char> s;
        backtrack(s);
        AL.assign(seq.size(), vi());
        for (int u = 0; u < seq.size(); ++u) {
            for (int v = 0; v < seq.size(); ++v) {
                string &s1 = seq[u], &s2 = seq[v];
                if (s1.substr(1) == s2.substr(0, M - 1)) {
                    AL[u].pb(v);
                }
            }
        }

        vi tour = hierholzer(0);
        string res = "";
        for (int i = 1; i < tour.size(); ++i) {
            res += seq[tour[i]][M - 1];
        }
        cout << res << endl;
    }
    return 0;
}