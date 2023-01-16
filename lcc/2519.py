# You are given a 0-indexed integer array nums and a positive integer k.

# We call an index i k-big if the following conditions are satisfied:

# There exist at least k different indices idx1 such that idx1 < i and nums[idx1] < nums[i].
# There exist at least k different indices idx2 such that idx2 > i and nums[idx2] < nums[i].
# Return the number of k-big indices.

from typing import List

# Input: nums = [2,3,6,5,2,3], k = 2
# Output: 2
# Explanation: There are only two 2-big indices in nums:
# - i = 2 --> There are two valid idx1: 0 and 1. There are three valid idx2: 2, 3, and 4.
# - i = 3 --> There are two valid idx1: 0 and 1. There are two valid idx2: 3 and 4.
from sortedcontainers import SortedList


class Solution:
    def kBigIndices(self, nums: List[int], k: int) -> int:
        l1 = SortedList()
        l2 = SortedList()

        n = len(nums)
        ans = 0
        left = [0] * n
        right = [0] * n

        for i, num in enumerate(nums):
            left[i] = l1.bisect_left(num)
            l1.add(num)

        for i in range(n - 1, -1, -1):
            num = nums[i]
            right[i] = l2.bisect_left(num)
            l2.add(num)

        for i in range(n):
            if left[i] >= k and right[i] >= k:
                ans += 1

        return ans


nums = [2, 3, 6, 5, 2, 3]
sol = Solution()

ans = sol.kBigIndices(nums, 2)
assert ans, 2
