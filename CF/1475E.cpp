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

ll nCr(ll n, ll r) {
    ll sum = 1;
    for (int i = 1; i <= r; i++) {
        sum = ((sum % MOD) * ((n - r + i) % MOD) / i);
    }
    return sum;
}

int main() {
    fastio;
    int n, k, t;
    cin >> t;

    int nums[1005][1005];
    memset(nums, 0, sizeof nums);
    for (int i = 0; i < 1001; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (!j) nums[i][j] = 1;
            else nums[i][j] = (nums[i - 1][j] + nums[i - 1][j - 1]) % MOD;
        }
    }
    while (t--) {
        cin >> n >> k;
        int num;
        map<int, int, greater<int>> mp;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            mp[num]++;
        }
        for (auto &[num, cnt] : mp) {
            if (cnt >= k) {
                cout << nums[cnt][k] << endl;
                break;
            }
            k -= cnt;
        }
    }
    return 0;
}
