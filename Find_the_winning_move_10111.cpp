#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define pb push_back
#define fi first
#define se second

#define ALL(v) v.begin(), v.end()
#define pii(a, b) printf("%d %d\n", a, b)
#define piii(a, b, c) printf("%d %d %d\n", a, b, c)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;

char s[5][5];

ii D[] = { { 0, 1 }, { 1, 0 }, { 1, 1 }, { 1, -1 } };

ii DL[4] = { { 0, 0 }, { 1, 1 }, { 2, 2 }, { 3, 3 } };
ii DR[4] = { { 0, 3 }, { 1, 2 }, { 2, 1 }, { 3, 0 } };

int resX = -1, resY = -1;

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool win(char c)
{
    for (int i = 0; i < 4; ++i) {
        if (count(s[i], s[i] + 4, c) == 4)
            return 1;
    }

    for (int i = 0; i < 4; ++i) {
        if (s[0][i] != '.') {
            if ((s[0][i] == c) && (s[1][i] == c) && (s[2][i] == c) && (s[3][i] == c))
                return 1;
        }
    }

    int cnt1 = 0, cnt2 = 0;
    for (auto& [i, j] : DL) {
        if (s[i][j] == c)
            cnt1++;
    }

    for (auto& [i, j] : DR) {
        if (s[i][j] == c)
            cnt2++;
    }

    return cnt1 == 4 || cnt2 == 4;
}

int solve(int turn)
{
    if (turn == 0 && win('o'))
        return 0;
    if (turn == 1 && win('x'))
        return 0;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (s[i][j] != '.')
                continue;
            s[i][j] = turn == 1 ? 'o' : 'x';
            int val = solve(!turn);
            resX = i, resY = j;
            s[i][j] = '.';
            if (val == 0)
                return 1;
        }
    }
    return 0;
}

int main()
{
    fastio();
    char c;

    while (cin >> c && c != '$') {

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j)
                cin >> s[i][j];
        }

        if (solve(0))
            cout << "(" << resX << "," << resY << ")" << endl;
        else
            cout << "#####" << endl;
    }
}