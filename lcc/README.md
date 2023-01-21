# Random Problems

## Notes

- [2366]: Given a number `k` and a larger number `n`, if we want to divide `n` into as fewest pieces as possible with the smallest one as large as possible, there will be `p = ceil(n/k)` pieces, and the smallest piece will be `floor(n/p)`.
- [2213]: Require a Segment Tree with point update.
- [2040]: Binary search; 4 cases based on the sign: if `-ve` products `neg < k`, we directly count non-negative products `k-neg`; else, we swap `B1` and `B2` and count `neg-k+1`.
- [#3 Bi-weekly 96](https://leetcode.com/contest/biweekly-contest-96/problems/maximum-subsequence-score/): I have tried sorting by `nums2[i]` and running `dp(i,k)` on `nums1` to find the maximum subsequence sum, but got TLE due to `O(n^2)` running time. Should have used a priority queue. _When there is something like 'maximum of `k` element subsequence'_, running DP is too expensive as it is bounded by `O(nk)`. A pq should be used for selecting the top `k` elements.
