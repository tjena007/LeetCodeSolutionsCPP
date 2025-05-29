class Solution:
    def maxArea(self, height: List[int]) -> int:
        left,right = 0,len(height) - 1

        ans = float('-inf')

        while left < right:
            h = min(height[left],height[right])
            water = h * (right - left)
            ans = max(water,ans)

            # move pointers to avoid duplicates

            if height[left] > height[right]:
                right -= 1
            else:
                left += 1
        
        return ans