class Objext:
    def __init__(self, v: int, n=None, p=None):
        self.n=n
        self.v=v
        self.p=p
class MyCircularDeque:

    def __init__(self, k: int):
        self.first=None
        self.last=None
        self.maxsize=k
        self.size=0

        

    def insertFront(self, value: int) -> bool:
        if self.size+1 > self.maxsize:
            return False
        if self.first == None:
            self.first = Objext(value)
            self.last = self.first
        else:
            tmp = Objext(value,self.first,None)
            self.first.p = tmp
            self.first = tmp
        self.size+=1
        return True

    def insertLast(self, value: int) -> bool:
        if self.size+1 > self.maxsize:
            return False
        if self.first == None:
            self.first = Objext(value)
            self.last = self.first
        else:
            tmp = Objext(value,None,self.last)
            self.last.n = tmp
            self.last = tmp
        self.size+=1       
        return True

    def deleteFront(self) -> bool:
        if self.size == 0:
            return False
        self.first = self.first.n
        if self.first:
            self.first.p = None
        else:
            self.last = None
        self.size -=1
        return True        
        

    def deleteLast(self) -> bool:
        if self.size == 0:
            return False
        self.last = self.last.p
        if self.last:
            self.last.n = None
        else:
            self.first = None
        self.size -=1
        return True        

    def getFront(self) -> int:
        if self.size == 0:
            return -1
        return self.first.v
  

    def getRear(self) -> int:
        if self.size == 0:
            return -1
        return self.last.v        

    def isEmpty(self) -> bool:
        return self.size == 0
        

    def isFull(self) -> bool:
        return self.size == self.maxsize
        


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()