class Child:
    def __init__(self,value):
        self.rating = value
        self.candies = 1
        self.previous = None
        self.next = None

    def give_candies(self, propagate=False):
        updated = False
        if self.next:
            if propagate:
                self.next.give_candies(True)
            if self.rating > self.next.rating and self.candies <= self.next.candies:
                self.candies = self.next.candies + 1
                updated = True
        if self.previous:
            if self.rating > self.previous.rating and self.candies <= self.previous.candies:
                self.candies = self.previous.candies + 1
                updated = True
        if updated:
            if self.next and self.next.rating > self.rating and self.next.candies <= self.candies:
                self.next.give_candies()
            if self.previous and self.previous.rating > self.rating and self.previous.candies <= self.candies:
                self.previous.give_candies()


class Solution:
    def candy_timeout(self, ratings: List[int]) -> int:
        len_ratings = len(ratings)
        if len_ratings < 2:
            return len_ratings
        if len_ratings > 2:
            start = Child(ratings[0])
            current = start
            for i in range(1, len_ratings):
                current.next = Child(ratings[i])
                current.next.previous = current
                current = current.next
            start.give_candies(True)
            retval = start.candies
            current = start.next
            while current:
                retval += current.candies
                current = current.next
            return retval

        else:
            if ratings[0]!=ratings[1]:
                return 3
            else:
                return 2
    
    def candy(self, R):
        n, ans = len(R), [1]*len(R)
        
        for i in range(n-1):
            if R[i] < R[i+1]:
                ans[i+1] = max(1 + ans[i], ans[i+1])
                
        for i in range(n-2, -1, -1):
            if R[i+1] < R[i]:
                ans[i] = max(1 + ans[i+1], ans[i])
        
        return sum(ans)