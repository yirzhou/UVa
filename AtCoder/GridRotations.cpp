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
#define fastio                                                                 \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(0)
#define precision(a)                                                           \
    cout << fixed;                                                             \
    cout.precision(a)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vi> vii;

ii D[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int h, w, q, a, b;

void print(vector<vector<char>> &A) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j)
            cout << A[i][j];
        cout << endl;
    }
}

int rotate_x(int pos, int x, int len) { return (pos - x + len) % len; }

int rotate_len_minus_x(int pos, int x, int len) {
    return (pos - (len - x) + len) % len;
}

int main() {
    fastio;
    cin >> h >> w;
    vector<vector<char>> A = vector<vector<char>>(h, vector<char>(w));

    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> A[i][j];

    cin >> q;

    int r = 0, c = 0;
    for (int i = 1; i <= q; ++i) {
        cin >> a >> b;
        // odd => rotate x
        if (i % 2 == 1) {
            r = rotate_x(r, a, h), c = rotate_x(c, b, w);
        } else {
            // even => rotate len-x
            r = rotate_len_minus_x(r, a, h), c = rotate_len_minus_x(c, b, w);
        }
    }

    vector<vector<char>> B(h, vector<char>(w));

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            // odd => reverse
            int ni = (i + r + h) % h, nj = (j + c + w) % w;
            if (q % 2 == 0) {
                B[ni][nj] = A[i][j];
            } else {
                B[h - ni - 1][w - nj - 1] = A[i][j];
            }
        }
    }
    print(B);
    return 0;
}
