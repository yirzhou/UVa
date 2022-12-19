#include <algorithm>
#include <assert.h>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

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

vii bits;
vector<char> res;

string s;

int count(int r1, int c1, int r2, int c2)
{
    int rows = r2 - r1 + 1, cols = c2 - c1 + 1;
    int total = rows * cols, ones = 0, zeros = 0;

    for (int r = r1; r <= r2; ++r) {
        for (int c = c1; c <= c2; ++c)
            if (bits[r][c] == 1)
                ones++;
            else
                zeros++;
    }

    if (ones == total)
        return 1;
    else if (zeros == total)
        return 0;
    return 2;
}

void f1(int r1, int c1, int r2, int c2)
{
    int rows = r2 - r1 + 1, cols = c2 - c1 + 1;
    if (rows == 0 || cols == 0)
        return;

    int cnt = count(r1, c1, r2, c2);
    if (cnt != 2) {
        res.pb(cnt + '0');
        return;
    }
    res.pb('D');
    int rl = rows % 2 ? rows / 2 + 1 : rows / 2, cl = cols % 2 ? cols / 2 + 1 : cols / 2;
    f1(r1, c1, r1 + rl - 1, c1 + cl - 1);
    f1(r1, c1 + cl, r1 + rl - 1, c2);
    f1(r1 + rl, c1, r2, c1 + cl - 1);
    f1(r1 + rl, c1 + cl, r2, c2);
}

int ptr = 0;

void f2(int r1, int c1, int r2, int c2)
{
    int rows = r2 - r1 + 1, cols = c2 - c1 + 1;
    if (rows == 0 || cols == 0)
        return;
    char sym = s[ptr++];
    if (sym == 'D') {
        int rl = rows % 2 ? rows / 2 + 1 : rows / 2, cl = cols % 2 ? cols / 2 + 1 : cols / 2;
        f2(r1, c1, r1 + rl - 1, c1 + cl - 1);
        f2(r1, c1 + cl, r1 + rl - 1, c2);
        f2(r1 + rl, c1, r2, c1 + cl - 1);
        f2(r1 + rl, c1 + cl, r2, c2);
    } else {
        for (int r = r1; r <= r2; ++r)
            for (int c = c1; c <= c2; ++c)
                bits[r][c] = sym - '0';
    }
}

void print_header(char type, int rows, int cols)
{
    cout << (type == 'B' ? 'D' : 'B');
    int b1 = (int)log10(rows) + 1, b2 = (int)log10(cols) + 1;
    for (int i = 0; i < 4 - b1; ++i)
        cout << ' ';

    cout << rows;
    for (int i = 0; i < 4 - b2; ++i)
        cout << ' ';
    cout << cols;
    cout << endl;
}

int main()
{
    fastio;

    char c;
    int rows, cols;

    while (cin >> c && c != '#') {
        cin >> rows >> cols;
        bits = vii(rows, vi(cols, 0));
        print_header(c, rows, cols);
        if (c == 'B') {
            res.clear();
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    cin >> c;
                    bits[i][j] = c - '0';
                }
            }

            f1(0, 0, rows - 1, cols - 1);
            for (int i = 0; i < res.size(); ++i) {
                if (i > 0 && i % 50 == 0)
                    cout << endl;

                cout << res[i];
            }

        } else {
            cin >> s;
            ptr = 0;
            f2(0, 0, rows - 1, cols - 1);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    int idx = (i * cols + j);
                    if (idx > 0 && idx % 50 == 0)
                        cout << endl;

                    cout << bits[i][j];
                }
            }
        }
        cout << endl;
    }

    return 0;
}
