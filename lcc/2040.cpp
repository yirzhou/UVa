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
typedef vector<vi> vvi;

/*
Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.

Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
Output: 0

Input: nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
Output: -6
*/

class Solution {
public:
    ll count(vi& A, vi& B, ll k)
    {
        ll j = B.size() - 1;
        ll res = 0;
        for (ll i = 0; i < A.size(); ++i) {
            while (j >= 0 && (ll)A[i] * B[j] > k)
                j--;
            res += j + 1;
        }
        return res;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k)
    {
        vi A1, A2, B1, B2;
        for (auto& num : nums1)
            num >= 0 ? A2.pb(num) : A1.pb(-num);

        for (auto& num : nums2)
            num >= 0 ? B2.pb(num) : B1.pb(-num);

        reverse(ALL(A1)), reverse(ALL(B1));
        ll s = 1;
        ll neg = A1.size() * B2.size() + A2.size() * B1.size();
        if (neg < k)
            k -= neg;
        else
            k = neg - k + 1, s = -1, swap(B1, B2);

        ll lo = 0, hi = 1e10;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            ll res = count(A1, B1, mid) + count(A2, B2, mid);
            if (res >= k) // 若有k个比mid小, 说明当前mid是第k+1个，不符合，因此 hi = mid
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo * s;
    }
};
