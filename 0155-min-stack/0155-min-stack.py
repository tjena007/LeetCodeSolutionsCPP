class MinStack:

    def __init__(self):
        self.st = []
        self.minSt = []
        self.minEl = float('inf')
        

    def push(self, val: int) -> None:
        self.minEl = min(self.minEl,val)
        self.st.append(val)
        self.minSt.append([val,self.minEl])
        

    def pop(self) -> None:
        self.st.pop()
        self.minSt.pop()
        self.minEl = self.minSt[-1][1] if self.minSt else float('inf')
        

    def top(self) -> int:
        return self.st[-1]
        

    def getMin(self) -> int:
        return self.minSt[-1][1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()