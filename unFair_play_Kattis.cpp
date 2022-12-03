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
    map<ii, int> EMap;

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
        EMap[{ u, v }] = EL.size() - 1;
        EL.emplace_back(u, (directed ? 0 : w), 0);
        AL[v].pb(EL.size() - 1);
        EMap[{ v, u }] = EL.size() - 1;
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

    int get_edge_flow(int u, int v)
    {
        return get<2>(EL[EMap[{ u, v }]]);
    }
};

int main()
{
    fastio;
    int N, M;
    vi points;
    while (cin >> N && N != -1) {
        cin >> M;
        points.assign(N + 1, 0);
        for (int i = 1; i <= N; ++i)
            cin >> points[i];
        int a, b;

        vector<ii> matches(M);

        int pointsN = points.back();
        int m_prime = 0;
        for (int i = 0; i < M; ++i) {
            cin >> a >> b;
            matches[i] = { a, b };
            if (a == N || b == N)
                pointsN += 2;
            else
                m_prime++;
        }

        int s = 0, t = N + 1, initialV = N + 2 + M;
        max_flow mf(initialV);
        bool can = true;
        for (auto& point : points) {
            if (point >= pointsN) {
                can = false;
                break;
            }
        }

        if (!can) {
            cout << "NO\n";
            continue;
        }

        int matchidx;
        for (int i = 0; i < M; ++i) {
            auto [a, b] = matches[i];
            matchidx = t + i + 1;
            if (a != N && b != N) {
                // connect source

                mf.add_edge(s, matchidx, 2);
                // Connect match index
                mf.add_edge(matchidx, a, 2);
                mf.add_edge(matchidx, b, 2);
            }
        }

        for (int i = 1; i < N; ++i)
            mf.add_edge(i, t, pointsN - points[i] - 1);

        int f = mf.dinic(s, t);
        if (f != 2 * m_prime) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < M; ++i) {
            int u = matches[i].fi, v = matches[i].se;
            if (u == N)
                cout << "0";
            else if (v == N)
                cout << "2";
            else {
                int matchidx = t + i + 1;
                if (mf.get_edge_flow(matchidx, u) == 2)
                    cout << "0";
                else if (mf.get_edge_flow(matchidx, v) == 2)
                    cout << "2";
                else
                    cout << "1";
            }
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}