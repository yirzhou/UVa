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

#define L 4

ii D[] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

vi rec(46);
int board[L * L];
int limit, blank, lim;
char moves[] = "URDL";

void print(int grid[L][L])
{
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < L; ++j)
            cout << grid[i][j] << " ";
        cout << endl;
    }

    cout << endl;
}

int heu(int r, int c, int nr, int nc)
{
    int target = board[nr * 4 + nc];
    int tc = target % 4, tr = target / 4;
    return -abs(tr - nr) - abs(tc - nc) + abs(tr - r) + abs(tc - c);
}

int h()
{
    int res = 0;
    for (int r = 0; r < L; ++r) {
        for (int c = 0; c < L; ++c) {
            if (r * L + c == blank)
                continue;
            res += abs(board[r * L + c] / L - r) + abs(board[r * L + c] % L - c);
        }
    }

    return res;
}

bool dfs(int u, int g, int h)
{
    if (g + h > limit)
        return false;
    if (h == 0) {
        lim = g;
        return true;
    }

    int r = u / L, c = u % L;
    for (int i = 0; i < L; ++i) {
        if (g != 0 && ((rec[g - 1] ^ 2) == i))
            continue;

        int nr = r + D[i].fi, nc = c + D[i].se;
        if (nr < 0 || nr == L || nc < 0 || nc == L)
            continue;

        int nu = nr * 4 + nc;
        int delta = heu(r, c, nr, nc);
        swap(board[u], board[nu]);
        rec[g] = i;
        if (dfs(nu, g + 1, h + delta))
            return true;
        swap(board[u], board[nu]);
    }

    return false;
}

int solve()
{
    int heuristic = h();
    for (limit = heuristic; limit <= 45; limit += 2) {
        if (dfs(blank, 0, heuristic))
            return limit;
    }
    return -1;
}

int main()
{
    fastio;
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < L * L; ++i) {
            cin >> board[i];
            if (board[i] == 0)
                blank = i, board[i] = 15;
            else
                board[i]--;
        }

        int res = 0;
        for (int i = 0; i < L * L; ++i) {
            for (int j = 0; j < i; ++j) {
                if (board[j] > board[i])
                    res++;
            }
        }

        res += blank / L + blank % L;
        if (res % 2 != 0 || solve() == -1)
            cout << "This puzzle is not solvable.";
        else {
            for (int i = 0; i < lim; ++i)
                cout << moves[rec[i]];
        }
        cout << endl;
    }

    return 0;
}