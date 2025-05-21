class RandomizedSet:

    def __init__(self):
        self.d = {}
        self.nums = []
        

    def insert(self, val: int) -> bool:
        if val in self.d:
            return False
        else:
            self.d[val] = len(self.nums)
            self.nums.append(val)
            return True
        

    def remove(self, val: int) -> bool:
        if val not in self.d:
            return False
        else:
            last = self.nums[-1] #curent last element
            idx = self.d[val]
            # swap element at idx with last value, and then update its index in the dictionary
            self.nums[idx],self.nums[-1] = self.nums[-1],self.nums[idx]

            self.d[last] = idx
            self.nums.pop()
            del self.d[val]
            return True
        

    def getRandom(self) -> int:
        return random.choice(self.nums) 
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()