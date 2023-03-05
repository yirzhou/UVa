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

bool V[50005] = {0};
typedef pair<int, int> ii;

class Solution {
  public:
    int minJumps(vector<int> &arr) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < arr.size(); ++i) mp[arr[i]].push_back(i);
        int n = arr.size();
        memset(V, 0, sizeof V);

        queue<ii> q;
        q.push({0, 0});
        V[0] = 1;

        unordered_set<int> S;
        while (q.size()) {
            ii state = q.front();
            q.pop();
            int i = state.first, step = state.second;

            if (i == n - 1) return step;
            if (i < n - 1 && !V[i + 1]) {
                q.push({i + 1, step + 1});
                V[i + 1] = 1;
            }

            if (i - 1 >= 0 && !V[i - 1]) {
                q.push({i - 1, step + 1});
                V[i - 1] = 1;
            }
            if (!S.count(arr[i])) {
                for (auto &j : mp[arr[i]]) {
                    if (i != j && !V[j]) {
                        q.push({j, step + 1});
                        V[j] = 1;
                    }
                }
                S.insert(arr[i]);
            }
        }
        return -1;
    }
};
