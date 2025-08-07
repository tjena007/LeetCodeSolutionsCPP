class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l,r = 0,0
        d = {}
        ans = 0
        max_freq = 0

        while r< len(s):
            d[s[r]] = d.get(s[r],0) + 1

            max_freq = max(max_freq,d[s[r]])
            window_size = r-l+1
            if (l <= r and window_size - max_freq > k):
                d[s[l]] -= 1
                l += 1
                
            
            ans = max(ans, r-l + 1)
            r += 1
        
        return ans

        
        