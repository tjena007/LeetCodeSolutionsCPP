class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t:
            return ""

        d = {}
        count = 0
        l, r = 0, 0
        minCount = float("inf")
        idx = -1

        # Store the frequency of characters in t
        for char in t:
            d[char] = d.get(char, 0) + 1
        
        required = len(t)  # Total number of characters we need to match
        
        while r < len(s):
            if s[r] in d:
                d[s[r]] -= 1
                if d[s[r]] >= 0:
                    count += 1

            # When we match all characters, try to shrink the window
            while count == required:
                if (r - l + 1) < minCount:
                    minCount = r - l + 1
                    idx = l

                if s[l] in d:
                    d[s[l]] += 1
                    if d[s[l]] > 0:
                        count -= 1  # We lost a needed character
            
                l += 1  # Shrink the window from the left
            
            r += 1  # Expand the window from the right
        
        return s[idx:idx + minCount] if idx != -1 else ""
