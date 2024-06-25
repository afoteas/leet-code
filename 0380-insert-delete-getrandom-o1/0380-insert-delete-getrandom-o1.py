import random
class RandomizedSet:

    def __init__(self):
        self.s=set()
        self.l=0

    def insert(self, val: int) -> bool:
        if val in self.s:
            return False
        else:
            self.s.add(val)
            self.l+=1
            return True

    def remove(self, val: int) -> bool:
        if val in self.s:
            self.s.remove(val)
            self.l-=1
            return True
        else:
            return False

    def getRandom(self) -> int:
        return  random.choice(list(self.s))
        # return self.s[random.randint(0,self.l-1)]
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()