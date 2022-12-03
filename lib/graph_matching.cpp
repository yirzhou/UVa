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

class aug {
    // build unweighted Bipartite Graph with directed edge left->right set
    // that has V vertices and Vleft vertices on the left set
    unordered_set<int> freeV;
    vi match, vis;
    vector<vi> AL;
    int MCBM = 0, VLeft = 0;

public:
    /**
     * V: total vertices count
     * VLeft: vertices count in the left set
     */
    aug(int V, int VLeft)
        : VLeft(VLeft)
    {
        match.assign(V, -1);

        for (int L = 0; L < VLeft; ++L)
            freeV.insert(L);

        MCBM = 0;
        for (int L = 0; L < VLeft; ++L) {
            vi candidates;
            for (auto& R : AL[L])
                if (match[R] == -1)
                    candidates.pb(R);
            if ((int)candidates.size() > 0) {
                ++MCBM;
                freeV.erase(L); // L is matched.
                int a = rand() % (int)candidates.size(); // Randomize this.
                match[candidates[a]] = L;
            }
        }
    }

    int mcbm()
    {
        for (auto& f : freeV) {
            vis.assign(VLeft, 0);
            MCBM += Aug(f);
        }

        return MCBM;
    }

    void add_edge(int u, int v)
    {
        AL[u].pb(v);
    }

    int Aug(int L)
    {
        if (vis[L])
            return 0;
        vis[L] = 1;
        for (auto& R : AL[L])
            if ((match[R] == -1) || Aug(match[R])) {
                match[R] = L;
                return 1;
            }
        return 0;
    }
};