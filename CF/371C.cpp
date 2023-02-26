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

ll Nb, Ns, Nc, Pb, Ps, Pc, ruble;
string s;

ll nums[3] = {0};

int good(ll target) {

    ll Nb_t = target * nums[0], Ns_t = target * nums[1],
       Nc_t = target * nums[2];

    ll needs = max(0LL, Nb_t - Nb) * Pb + max(0LL, Ns_t - Ns) * Ps +
               max(0LL, Nc_t - Nc) * Pc;

    return ruble >= needs;
}

int main() {
    fastio;
    cin >> s;
    cin >> Nb >> Ns >> Nc >> Pb >> Ps >> Pc >> ruble;
    for (auto &c : s) {
        if (c == 'B') nums[0]++;
        else if (c == 'S') nums[1]++;
        else nums[2]++;
    }

    ll lo = 1, hi = 1e14;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (good(mid)) lo = mid + 1;
        else hi = mid;
    }

    cout << lo - 1LL << endl;
    return 0;
}
