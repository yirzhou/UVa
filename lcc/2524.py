from collections import defaultdict
from typing import List


class Solution:
    def maxFrequencyScore(self, nums: List[int], k: int) -> int:

        MOD = 1_000_000_007
        ans = 0
        count = defaultdict(int)

        def slide(num_in, num_out, total):
            nonlocal count
            if num_in == num_out:
                return total

            count[num_in] += 1

            if count[num_in] == 1:
                total += num_in
            else:
                total -= pow(num_in, count[num_in] - 1)
                total += pow(num_in, count[num_in])

            count[num_out] -= 1
            if count[num_out] == 0:
                total -= num_out
            else:
                total -= pow(num_out, count[num_out] + 1)
                total += pow(num_out, count[num_out])

            return total % MOD

        i = j = total = 0
        while j < k:
            count[nums[j]] += 1
            j += 1

        for num, f in count.items():
            total = (total + pow(num, f)) % MOD

        ans = total

        while j < len(nums):
            num_out = nums[i]
            i += 1
            num_in = nums[j]
            j += 1
            total = slide(num_in, num_out, total)
            ans = max(ans, total)

        return int(ans % MOD)


nums = [
    122,
    122,
    122,
    122,
    165,
    122,
    162,
    122,
    122,
    122,
    122,
    165,
    122,
    122,
    122,
    122,
    122,
    182,
    182,
    132,
    122,
    122,
    122,
    122,
    140,
    54,
    180,
    168,
    122,
    122,
    122,
    18,
    33,
    122,
    122,
    54,
    122,
    122,
    120,
    131,
    85,
    122,
    67,
    122,
    54,
    180,
    168,
    188,
    122,
    57,
    18,
    57,
    122,
    131,
    122,
]

k = 25

sol = Solution()
ans = sol.maxFrequencyScore(nums, k)
print(f"Expected = {999362230}; Actual = {ans}")
