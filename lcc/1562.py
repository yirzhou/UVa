from collections import defaultdict

from sortedcontainers import SortedList


class Solution:
    def findLatestStep(self, arr, m):
        cnt = defaultdict(int)
        S = SortedList()
        ans = -1
        for i, num in enumerate(arr):
            p = (num, num)
            it = S.bisect_left(p)

            to_pop = []
            if it > 0 and S[it - 1][1] + 1 == p[0]:
                cnt[S[it - 1][1] - S[it - 1][0] + 1] -= 1
                p = (S[it - 1][0], p[0])
                to_pop.append(S[it - 1])

            if it != len(S) and p[1] == S[it][0] - 1:
                cnt[S[it][1] - S[it][0] + 1] -= 1
                p = (p[0], S[it][1])
                to_pop.append(S[it])

            for pair in to_pop:
                S.remove(pair)
            S.add(p)

            cnt[p[1] - p[0] + 1] += 1
            if cnt[m] > 0:
                ans = i + 1
        return ans
