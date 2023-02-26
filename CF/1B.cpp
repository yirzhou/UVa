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
#define MOD 1000000007

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
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;

ii D[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int excel(string &s) {
    int cnt = 0;
    for (int i = 1; i < s.size(); ++i)
        if (isdigit(s[i]) && !isdigit(s[i - 1])) cnt++;
    return cnt == 1;
}

void handle(string &s) {
    int di = 0;
    while (di < s.size() && !isdigit(s[di])) di++;

    string C = s.substr(0, di);
    int r = stoi(s.substr(di)), col = 0;

    for (auto &c : C) {
        col *= 26;
        col += (c - 'A' + 1);
    }

    cout << 'R' << r << 'C' << col << endl;
}

void handle2(string &s) {
    int cidx = s.find('C');
    string r = s.substr(1, cidx - 1);
    int c = stoi(s.substr(cidx + 1));

    string C;

    while (c) {
        if (c % 26 == 0) {
            C.pb('Z');
            c -= 26;
        } else {
            int r = c % 26;
            C.pb('A' + r - 1);
        }

        c /= 26;
    }

    reverse(ALL(C));
    cout << C << r << endl;
}

int main() {
    fastio;
    int n;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        if (excel(s)) handle(s);
        else handle2(s);
    }
    return 0;
}
