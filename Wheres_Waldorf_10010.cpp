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

vector<ii> dirs = { { 0, -1 }, { 0, 1 }, { 1, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 0 }, { -1, 0 } };
vector<vector<char>> G;
string word;

bool backtrack(string& s, int i, int r, int c, int dir)
{
    int di = dirs[dir].first, dj = dirs[dir].second;
    if (i == s.size()) {
        return true;
    }
    if (r < 0 || r >= G.size() || c < 0 || c >= G[0].size())
        return false;

    if (s[i] == G[r][c]) {
        return backtrack(s, i + 1, r + di, c + dj, dir);
    }
    return false;
}
int main()
{
    int cases;
    si(cases);
    int m, n, k;
    while (cases--) {
        scanf("\n");
        sii(m, n);
        G = vector<vector<char>>(m, vector<char>(n));
        scanf("\n");
        for (int i = 0; i < m; ++i) {
            getline(cin, word);
            for (auto& c : word)
                c = tolower(c);
            for (int j = 0; j < word.size(); ++j)
                G[i][j] = word[j];
        }
        si(k);
        scanf("\n");
        while (k--) {
            getline(cin, word);
            for (auto& c : word)
                c = tolower(c);

            bool found = false;
            for (int i = 0; i < m && !found; ++i) {
                for (int j = 0; j < n && !found; ++j) {
                    if (G[i][j] != word[0])
                        continue;
                    for (int dir = 0; dir < dirs.size(); ++dir) {
                        if (backtrack(word, 0, i, j, dir)) {
                            printf("%d %d\n", i + 1, j + 1);
                            found = true;
                            break;
                        }
                    }
                }
            }
        }

        if (cases)
            puts("");
    }
}