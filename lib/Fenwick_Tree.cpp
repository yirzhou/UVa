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

#define LSOne(S) ((S) & -(S))

class FenwickTree {
  private:
    vl ft;

  public:
    FenwickTree(int m) { ft.assign(m + 1, 0); }

    FenwickTree(const vl &f) { build(f); }

    FenwickTree(int m, const vl &s) {
        vl f(m + 1, 0);
        for (int i = 0; i < s.size(); ++i) ++f[s[i]];
        build(f);
    }

    void build(const vl &f) {
        int m = (int)f.size() - 1;
        ft.assign(m + 1, 0);
        for (int i = 1; i <= m; ++i) {
            ft[i] += f[i];
            if (i + LSOne(i) <= m) ft[i + LSOne(i)] += ft[i];
        }
    }

    int rsq(int j) {
        int sum = 0;
        for (; j; j -= LSOne(j)) sum += ft[j];
        return sum;
    }

    int rsq(int i, int j) { return rsq(j) - rsq(i - 1); }

    void update(int i, int j) {
        for (; i < (int)ft.size(); i += LSOne(i)) ft[i] += j;
    }

    int select(ll k) {
        int lo = 1, hi = ft.size() - 1;
        for (int i = -0; i < 30; ++i) {
            int mid = (lo + hi) / 2;
            (rsq(1, mid) < k) ? lo = mid : hi = mid;
        }
        return hi;
    }
};

class RUPQ {
  private:
    FenwickTree ft;

  public:
    RUPQ(int m) : ft(FenwickTree(m)){};
    void range_update(int ui, int uj, int v) {
        ft.update(ui, v);
        ft.update(uj + 1, -v);
    }

    ll point_query(int i) { return ft.rsq(i); }
};

class RURQ {
  private:
    RUPQ rupq;
    FenwickTree purq;

  public:
    RURQ(int m) : rupq(RUPQ(m)), purq(FenwickTree(m)) {}

    void range_update(int ui, int uj, int v) {
        rupq.range_update(ui, uj, v);
        purq.update(ui, v * (ui - 1));
        purq.update(uj + 1, -v * uj);
    }

    ll rsq(int j) { return rupq.point_query(j) * j - purq.rsq(j); }

    ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); }
};
