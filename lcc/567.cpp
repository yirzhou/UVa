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
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;

class Solution {
  public:
    bool checkInclusion(string &s1, string &s2) {
        if (s1.size() > s2.size()) return 0;
        unordered_map<char, int> mp;
        for (auto &c : s1) mp[c]++;

        int i = 0, j = 0, cnt = mp.size();
        for (; j < s2.size(); ++j) {
            char c = s2[j];
            if (mp.count(c)) {
                mp[c]--;
                if (mp[c] == 0) cnt--;
                while (mp[c] < 0) {
                    char p = s2[i++];
                    mp[p]++;
                    if (mp[p] == 1) cnt++;
                }
            } else {
                while (i <= j) {
                    char p = s2[i++];
                    if (mp.count(p)) {
                        mp[p]++;
                        if (mp[p] == 1) cnt++;
                    }
                }
            }
            if (cnt == 0) return 1;
        }

        return 0;
    }
};
