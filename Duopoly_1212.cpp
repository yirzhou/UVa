#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX
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
typedef tuple<int, ll, ll> edge;

const ll INFTY = 1e18;

class max_flow {
private:
    int V;
    vector<edge> EL;
    vector<vi> AL;
    vi d, last;
    vector<ii> p;

    bool BFS(int s, int t) // Find augmenting path
    {
        d.assign(V, -1);
        d[s] = 0;
        queue<int> q({ s });
        p.assign(V, { -1, -1 }); // record BFS sp tree
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == t)
                break;
            for (auto& idx : AL[u]) {
                auto& [v, cap, flow] = EL[idx];
                if ((cap - flow > 0) && (d[v] == -1))
                    d[v] = d[u] + 1, q.push(v), p[v] = { u, idx };
            }
        }
        return d[t] != -1; // has an augmenting path.
    }

    ll send_one_flow(int s, int t, ll f = INFTY) // send on flow from s->t
    {
        if (s == t) // bottleneck edge f found
            return f;
        auto& [u, idx] = p[t];
        auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
        ll pushed = send_one_flow(s, u, min(f, cap - flow));
        flow += pushed;
        auto& rflow = get<2>(EL[idx ^ 1]); // Back edge
        rflow -= pushed; // back flow
        return pushed;
    }

    ll DFS(int u, int t, ll f = INFTY) // Traverse from s->t
    {
        if ((u == t) || (f == 0))
            return f;
        for (int& i = last[u]; i < (int)AL[u].size(); ++i) { // from last edge
            auto& [v, cap, flow] = EL[AL[u][i]];
            if (d[v] != d[u] + 1)
                continue; // not part of the layer graph
            if (ll pushed = DFS(v, t, min(f, cap - flow))) {
                flow += pushed;
                auto& rflow = get<2>(EL[AL[u][i] ^ 1]); // Back edge
                rflow -= pushed; // back flow
                return pushed;
            }
        }
        return 0;
    }

public:
    max_flow(int initialV)
        : V(initialV)
    {
        EL.clear();
        AL.assign(V, vi());
    }

    void add_edge(int u, int v, ll w, bool directed = true)
    {
        if (u == v)
            return;
        EL.emplace_back(v, w, 0);
        AL[u].pb(EL.size() - 1);
        EL.emplace_back(u, (directed ? 0 : w), 0);
        AL[v].pb(EL.size() - 1);
    }

    ll edmonds_karp(int s, int t)
    {
        ll mf = 0;
        while (BFS(s, t)) {
            ll f = send_one_flow(s, t);
            if (f == 0)
                break;
            mf += f;
        }
        return mf;
    }

    ll dinic(int s, int t)
    {
        ll mf = 0;
        while (BFS(s, t)) {
            last.assign(V, 0);
            while (ll f = DFS(s, t))
                mf += f;
        }
        return mf;
    }
};

int T, N, P;

unordered_map<int, unordered_set<int>> A, B;

unordered_map<int, vi> REV;

int proc(string& s, int id, unordered_map<int, unordered_set<int>>& S)
{
    int weight = -1, num = 0;
    istringstream in(s);
    in >> weight;

    while (in >> num) {
        S[id].insert(num);
    }

    return weight;
}

int main()
{
    fastio;
    string line;
    getline(cin, line);
    T = stoi(line);

    for (int caseno = 1; caseno <= T; ++caseno) {
        if (caseno > 1)
            cout << endl;

        A.clear(), B.clear(), REV.clear();
        getline(cin, line);

        cout << "Case " << caseno << ":\n";
        getline(cin, line);
        N = stoi(line);

        int s = 0, t = 1, total = 0;
        vi b1, b2;
        for (int i = 0; i < N; ++i) {
            getline(cin, line);
            int weight = proc(line, i, A);
            b1.pb(weight);
            total += weight;
        }

        for (auto& [u, c] : A) {
            for (auto& elem : c)
                REV[elem].pb(u + 2);
        }

        getline(cin, line);
        N = stoi(line);

        for (int i = 0; i < N; ++i) {
            getline(cin, line);
            int weight = proc(line, i, B);
            b2.pb(weight);
            total += weight;
        }

        max_flow mf(A.size() + B.size() + 2);

        for (auto& [i, _] : A)
            mf.add_edge(s, i + 2, b1[i]);

        for (auto& [i, _] : B)
            mf.add_edge(2 + A.size() + i, t, b2[i]);

        for (auto& [j, c1] : B) {
            int v = 2 + A.size() + j;
            for (auto& elem : c1) {
                if (REV.count(elem)) {
                    for (auto& u : REV[elem])
                        mf.add_edge(u, v, INFTY);
                }
            }
        }

        int res = total - mf.dinic(s, t);
        cout << res << endl;
    }

    return 0;
}