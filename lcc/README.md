# Random Problems

## Need Revision

- [2366]: Given a number `k` and a larger number `n`, if we want to divide `n` into as fewest pieces as possible with the smallest one as large as possible, there will be `p = ceil(n/k)` pieces, and the smallest piece will be `floor(n/p)`.
- [2213]: Require a Segment Tree with point update.
- [2040]: Binary search; 4 cases based on the sign: if `-ve` products `neg < k`, we directly count non-negative products `k-neg`; else, we swap `B1` and `B2` and count `neg-k+1`.
- [[2542](https://leetcode.com/contest/biweekly-contest-96/problems/maximum-subsequence-score/)]: I have tried sorting by `nums2[i]` and running `dp(i,k)` on `nums1` to find the maximum subsequence sum, but got TLE due to `O(n^2)` running time. Should have used a priority queue. _When there is something like 'maximum of `k` element subsequence'_, running DP is too expensive as it is bounded by `O(nk)`. A pq should be used for selecting the top `k` elements.
- [[2543](https://leetcode.com/contest/biweekly-contest-96/problems/check-if-point-is-reachable/)]: given `(x,y)`, if we want to reach `(tx,ty)` with `y=y-x` or `x=x-y`, `x` and `y` must be odd and that `gcd(x,y) == 1`.
- [2003]: The key is to start with the node where `nums[node]==1` and then to its parent.
- [2551]: The first and the end are always included, so no need to worry about them; it can be seen as selecting `k-1` values of `nums[i] + nums[i+1]`.
- [2552]: Fixed range + unique elements => perfect scenario for a Fenwick Tree.
- [1960]: I got Manacher's Algorithm, and the cumulative maximum palindrome lengths; _However, for `m[i]`, it is at least `m[i+1]-2`. E.g., for a string `abayab`, `a[5] = 5; a[4] = 3`_.

## Unsolved

- [1977]: It requires: 1) O(1) substring comparison; 2) Prefix sum.
