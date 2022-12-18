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

int A[10005];
int n, sum;

void solve()
{
    int mindiff = INT_MAX;
    sort(A, A + n);

    int a, b;

    int l = 0, r = n - 1;
    while (l < r) {
        int s = A[l] + A[r];
        if (s == sum) {
            if (abs(A[l] - A[r]) < mindiff)
                mindiff = abs(A[l] - A[r]), a = A[l], b = A[r];
            l++, r--;
            while (l < r && A[l] == A[l - 1])
                l++;
            while (l < r && A[r] == A[r + 1])
                r--;
        } else if (s < sum)
            l++;
        else
            r--;
    }

    printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
}

int main()
{
    fastio;

    while (si(n) != EOF) {
        for (int i = 0; i < n; ++i)
            si(A[i]);
        si(sum);
        solve();
    }

    return 0;
}
