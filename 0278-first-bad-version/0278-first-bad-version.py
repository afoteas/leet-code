# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        good = -1
        bad = n
        while good+1 != bad:
            test = ((good + bad)>>1)
            if isBadVersion(test):
                bad = test
            else:
                good = test
        print(good)
        print(bad)
        return bad


        