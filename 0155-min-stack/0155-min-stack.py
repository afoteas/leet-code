class MinStack:

    def __init__(self):
        self.minimum=inf
        self.stack=[]
        

    def push(self, val: int) -> None:
        if self.minimum > val:
            self.minimum = val
        self.stack.append(val)
        

    def pop(self) -> None:
        # print(f"in_pop = {self.stack}")
        # print(f"in_min = {self.minimum}")
        if self.stack[-1] == self.minimum:
            x = self.stack.pop()
            if self.stack:
                if x == self.minimum:
                    self.minimum = min(self.stack)
            else:
                self.minimum = inf
        else:
            self.stack.pop()

        # print(f"out_pop = {self.stack}")
        # print(f"out_min = {self.minimum}")
        
   

    def top(self) -> int:
        return self.stack[-1]
        

    def getMin(self) -> int:
        return self.minimum
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()