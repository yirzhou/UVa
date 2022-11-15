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
#define MAXN 200

string a, b;
int memo[MAXN][MAXN];
int ops[MAXN][MAXN];

int dp(string& a, int i, string& b, int j)
{
    if (memo[i][j] != -1)
        return memo[i][j];
    if (i == a.size()) {
        // insert
        for (int k = j; k < b.size(); ++k)
            ops[i][k] = 0;
        return memo[i][j] = b.size() - j;
    }
    if (j == b.size()) {
        // delete
        for (int k = i; k < a.size(); ++k)
            ops[k][j] = 2;
        return memo[i][j] = a.size() - i;
    }

    if (a[i] == b[j])
        return memo[i][j] = dp(a, i + 1, b, j + 1);

    // Insert, replace, delete
    int r1 = 1 + dp(a, i, b, j + 1);
    int r2 = 1 + dp(a, i + 1, b, j + 1);
    int r3 = 1 + dp(a, i + 1, b, j);
    int minval = min(r1, min(r2, r3));
    if (r1 == minval)
        ops[i][j] = 0;
    else if (r2 == minval)
        ops[i][j] = 1;
    else if (r3 == minval)
        ops[i][j] = 2;

    return memo[i][j] = minval;
}

void trace(int i, int j, int t, int cnt)
{
    if (i == a.size() && j == b.size())
        return;
    int op = ops[i][j];
    if (op != -1) {
        printf("%d ", cnt++);
        int pos = i + t;
        if (op == 0)
            printf("Insert %d,%c", pos, b[j]);
        else if (op == 1)
            printf("Replace %d,%c", pos, b[j]);
        else if (op == 2)
            printf("Delete %d", pos);
        puts("");
    }

    if (op == -1 || op == 1)
        trace(i + 1, j + 1, t, cnt);
    else if (op == 0)
        trace(i, j + 1, t + 1, cnt);
    else
        trace(i + 1, j, t - 1, cnt);
}

int main()
{
    int caseno = 0;
    while (getline(cin, a) && a.size()) {
        if (caseno)
            puts("");
        getline(cin, b);
        for (int i = 0; i < MAXN; ++i) {
            fill(memo[i], memo[i] + MAXN, -1);
            fill(ops[i], ops[i] + MAXN, -1);
        }

        int ops = dp(a, 0, b, 0);
        cout << ops << endl;
        trace(0, 0, 1, 1);
        caseno++;
    }
}