#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

vector<vector<char>> G;

ii epos;
vector<ii> dirs = { { 0, -1 }, { 0, 1 }, { 1, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 0 } };

bool backtrack(string& s, int i, int r, int c, int dir)
{
    int di = dirs[dir].first, dj = dirs[dir].second;
    if (i == s.size()) {
        epos = { r - di, c - dj };
        return true;
    }

    if (r < 0 || r >= G.size() || c < 0 || c >= G.size())
        return false;

    if (s[i] == G[r][c]) {
        return backtrack(s, i + 1, r + di, c + dj, dir);
    }
    return false;
}

int main()
{

    string line;
    getline(cin, line);
    int l = stoi(line);
    G.assign(l, vector<char>(l));
    for (int i = 0; i < l; ++i) {
        getline(cin, line);
        for (int j = 0; j < l; ++j)
            G[i][j] = line[j];
    }

    while (getline(cin, line) && line != "0") {
        bool found = false;
        for (int i = 0; i < l && !found; ++i) {
            for (int j = 0; j < l && !found; ++j) {
                if (G[i][j] != line[0])
                    continue;
                for (int dir = 0; dir < dirs.size(); ++dir) {
                    if (backtrack(line, 0, i, j, dir)) {
                        printf("%d,%d %d,%d\n", i + 1, j + 1, epos.first + 1, epos.second + 1);
                        found = true;
                        break;
                    }
                }
            }
        }

        if (!found)
            printf("Not found\n");
    }
}