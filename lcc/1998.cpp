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
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;

class Solution {
public:
    const static int MAXN = (1e5) + 5;

    bitset<MAXN> bs;
    ll _sieve_size;
    vi primes;
    unordered_map<int, vi> M, G;

    struct DSU {
        vi parent;
        DSU(int n)
        {
            parent.assign(n, 0);
            for (int i = 0; i < n; ++i)
                parent[i] = i;
        }

        int find(int x)
        {
            if (x != parent[x])
                parent[x] = find(parent[x]);
            return parent[x];
        }

        int connected(int p, int q) { return find(p) == find(q); }

        void connect(int p, int q)
        {
            int pp = find(p), pq = find(q);
            if (pp == pq)
                return;
            parent[pq] = pp;
        }
    };

    void add(int p, int i)
    {
        if (M.count(i))
            for (auto& k : M[i])
                G[p].pb(k);
    }

    void sieve(ll upperbound)
    {
        _sieve_size = upperbound + 1;
        bs.set();
        bs[0] = bs[1] = 0;
        for (ll i = 2; i <= _sieve_size; ++i) {
            if (bs[i]) {
                for (ll j = i; j <= _sieve_size; j += i)
                    add(i, j), bs[j] = 0;
                primes.pb((int)i);
            }
        }
    }
    bool gcdSort(vector<int>& nums)
    {
        int upperbound = *max_element(ALL(nums));
        for (int i = 0; i < nums.size(); ++i)
            M[nums[i]].pb(i);
        sieve(upperbound);
        DSU dsu(nums.size());
        for (auto& [p, V] : G)
            for (int i = 1; i < V.size(); ++i)
                dsu.connect(V[i - 1], V[i]);

        vvi A;
        for (int i = 0; i < nums.size(); ++i)
            A.pb({ nums[i], i });
        sort(ALL(A));
        for (int i = 0; i < nums.size(); ++i) {
            int u = A[i][1], v = i;
            if (!dsu.connected(u, v))
                return false;
        }

        return true;
    }

    void print(vl& nums)
    {
        for (auto& num : nums)
            cout << num << " ";
        cout << endl;
    }
};

// int main()
// {
//     int t, n;
//     cin >> t;
//     while (t--) {
//         cin >> n;
//         vi nums(n);
//         for (int i = 0; i < n; ++i)
//             cin >> nums[i];
//         cout << Solution().gcdSort(nums) << endl;
//     }
// }

/*
You are given an integer array nums, and you can perform the following operation any number of times on nums:

- Swap the positions of two elements nums[i] and nums[j] if gcd(nums[i], nums[j]) > 1 where gcd(nums[i], nums[j]) is the greatest common divisor of nums[i] and nums[j].

Return true if it is possible to sort nums in non-decreasing order using the above swap method, or false otherwise.

Input: nums = [7,21,3]
Output: true
Explanation: We can sort [7,21,3] by performing the following operations:
- Swap 7 and 21 because gcd(7,21) = 7. nums = [21,7,3]
- Swap 21 and 3 because gcd(21,3) = 3. nums = [3,7,21]
*/
