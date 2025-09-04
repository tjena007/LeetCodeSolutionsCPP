class TimeMap:

    def __init__(self):
        self.d = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.d[key] = self.d.get(key,[])
        self.d[key].append([timestamp,value])
        # print(self.d)
        

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.d or timestamp < self.d[key][0][0]:
            return ""
        l,r = 0, len(self.d[key]) - 1
        if timestamp >= self.d[key][r][0]:
            return self.d[key][r][1]
        
        #binary search, return l if not exact match not found
        res = ""   # default if not found

        while l <= r:
            mid = (l + r) // 2
            if self.d[key][mid][0] <= timestamp:
                res = self.d[key][mid][1]   # candidate
                l = mid + 1                 # try to go right (find larger floor)
            else:
                r = mid - 1

        return res

        
# 5,10,14 -> 6,8


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)