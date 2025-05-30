class Solution:
    def trap(self, height: List[int]) -> int:
        l,r = 0,len(height) - 1
        maxLeft = height[l]
        maxRight = height[r]

        ans = 0
        while l < r:
            if maxLeft <= maxRight:
                l += 1
                maxLeft = max(maxLeft,height[l])
                ans += maxLeft - height[l]
            else:
                r -= 1
                maxRight = max(maxRight,height[r])
                ans += maxRight - height[r]
            
        return ans
