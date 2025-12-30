class Solution:
    def countOdds(self, low: int, high: int) -> int:
        if (high - low + 1) %2 == 0:
            print("here")
            return int((high-low+1)/2)
        else:
            # return int((high-low+1)/2) if low %2 == 1 else int((high-low)/2)
            if low %2 == 1:
                print("here1")
                return int((high-low)/2)+1
            else:
                print("here2")
                return int((high-low)/2)

        