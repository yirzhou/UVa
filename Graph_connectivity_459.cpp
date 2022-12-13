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

class DSU {
private:
    int n;
    vi parent;

public:
    DSU(int N)
        : n(N)
    {
        parent.assign(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    int count()
    {
        return n;
    }

    void connect(int p, int q)
    {
        int rootp = find(p), rootq = find(q);
        if (rootp == rootq)
            return;
        parent[rootq] = rootp;
        n--;
    }
};

int main()
{
    fastio;
    int T;
    string s;
    getline(cin, s);
    T = stoi(s);
    getline(cin, s);
    for (int t = 0; t < T; ++t) {
        if (t)
            cout << endl;
        getline(cin, s);
        int n = s[0] - 'A' + 1;
        DSU dsu(n);

        while (getline(cin, s) && s.size()) {
            int u = s[0] - 'A', v = s[1] - 'A';
            dsu.connect(u, v);
        }
        cout << dsu.count() << endl;
    }

    return 0;
}