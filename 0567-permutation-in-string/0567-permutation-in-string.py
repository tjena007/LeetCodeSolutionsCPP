class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        
        d1 = {}
        d2 = {}

        for c in s1:
            d1[c] = d1.get(c, 0) + 1
        
        i, j = 0, len(s1)

        for c in s2[i:j]:
            d2[c] = d2.get(c, 0) + 1

        if d1 == d2:
            return True
        
        while j < len(s2):
            # remove s2[i]
            if d2[s2[i]] == 1:
                del d2[s2[i]]
            else:
                d2[s2[i]] -= 1
            i += 1

            # add s2[j]
            d2[s2[j]] = d2.get(s2[j], 0) + 1
            j += 1

            if d1 == d2:
                return True
        
        return False
