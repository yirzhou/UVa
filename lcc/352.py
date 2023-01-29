from typing import List

from sortedcontainers import SortedList


class Interval:
    def __init__(self, start, end):
        self.start = start
        self.end = end

    def __lt__(self, other):
        return self.start < other.start

    def __eq__(self, other):
        return self.start == other.start and self.end == other.end


class SummaryRanges:

    # Input
    # ["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
    # [[], [1], [], [3], [], [7], [], [2], [], [6], []]
    # Output
    # [null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

    # Explanation
    # SummaryRanges summaryRanges = new SummaryRanges();
    # summaryRanges.addNum(1);      // arr = [1]
    # summaryRanges.getIntervals(); // return [[1, 1]]
    # summaryRanges.addNum(3);      // arr = [1, 3]
    # summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
    # summaryRanges.addNum(7);      // arr = [1, 3, 7]
    # summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
    # summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
    # summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
    # summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
    # summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]

    def __init__(self):
        self.L = SortedList()
        self.S = set()

    def print(self, sl):
        for interval in sl:
            print(f"({interval.start}, {interval.end})")
        print("---")

    def addNum(self, value: int) -> None:
        if value in self.S:
            return
        interval = Interval(value, value)
        pos = self.L.bisect_left(interval)
        self.S.add(value)
        if pos < len(self.L) and self.L[pos].start <= value <= self.L[pos].end:
            return

        prevp, postp = pos - 1, pos
        # merge with prev and post
        if (
            prevp >= 0
            and postp < len(self.L)
            and self.L[prevp].end + 1 == value
            and self.L[postp].start == value + 1
        ):
            start = self.L[prevp].start
            end = self.L[postp].end

            self.L.pop(prevp)
            self.L.pop(postp - 1)
            self.L.add(Interval(start, end))

        elif prevp >= 0 and self.L[prevp].end + 1 == value:
            self.L[prevp].end = value
        elif postp < len(self.L) and self.L[postp].start - 1 == value:
            self.L[postp].start = value
        else:
            self.L.add(interval)

    def getIntervals(self) -> List[List[int]]:
        return [[interval.start, interval.end] for interval in self.L]


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(value)
# param_2 = obj.getIntervals()
