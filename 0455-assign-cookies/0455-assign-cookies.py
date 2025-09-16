class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()

        l,r = 0,0

        while l < len(s) and r < len(g):
            if s[l] >= g[r]:
                l += 1
                r += 1
            else:
                l += 1
        
        return r
