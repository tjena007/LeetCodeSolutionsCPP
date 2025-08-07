class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l,r = 0,0
        chars = {}
        ans = 0

        while r < len(s):
            while s[r] in chars:
                del chars[s[l]]
                l += 1
            
            chars[s[r]] = 1
            ans = max(ans,r-l+1)
            r += 1
        
        return ans


        