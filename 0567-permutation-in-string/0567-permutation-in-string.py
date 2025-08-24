class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        
        d1 = {}
        d2 = {}

        for char in s1:
            d1[char] = d1.get(char,0) + 1
        
        window = len(s1)
        l,r = 0,0

        while r-l < window:
            # print(r-l,d2,window)
            d2[s2[r]] = d2.get(s2[r],0) + 1
            r += 1

        # print(d1,d2)
        if d1 == d2:
            return True
        
        while r < len(s2):
            if d1 == d2:
                return True
            
            d2[s2[l]] = d2.get(s2[l],0) - 1
            if d2[s2[l]] == 0:
                del d2[s2[l]]
            l += 1
            d2[s2[r]] = d2.get(s2[r],0) + 1
            r += 1
        
        if d1 == d2:
            return True

        return False

