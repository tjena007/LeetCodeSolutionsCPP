class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        d1 = {}
        d2 = {}

        for st in s:
            d1[st] = d1.get(st,0) + 1
        
        for st in t:
            d2[st] = d2.get(st,0) + 1
        
        return d1 == d2
        