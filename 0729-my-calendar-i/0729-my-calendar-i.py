import bisect

class MyCalendar:

    def __init__(self):
        self.starts = []
        self.ends = []
        

    def book(self, start: int, end: int) -> bool:

        if start in self.starts:
            return False
        
        if not self.starts:
            bisect.insort(self.starts, start)
            bisect.insort(self.ends, end)
            return True

        if start >= self.ends[-1] or end <= self.starts[0]:
            bisect.insort(self.starts, start)
            bisect.insort(self.ends, end)
            return True
        pos1 = bisect.bisect_right(self.ends, start)
        pos2 = bisect.bisect_left(self.starts, end)
        if pos1 == pos2:
            bisect.insort(self.starts, start)
            bisect.insort(self.ends, end)
            return True
        return False

        


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)