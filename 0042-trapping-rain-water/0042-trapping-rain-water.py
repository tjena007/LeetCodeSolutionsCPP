class Solution:
    def trap(self, height: List[int]) -> int:
        maxLeft = []
        maxRight = [0] * len(height)
        
        top = 0
        
        for i in range(0,len(height)):
            maxLeft.append(top)
            top = max(top,height[i])
            
        top = 0
        
        for i in range(len(height)-1,-1,-1):
            maxRight[i] = top
            top = max(top,height[i])
        
        
        ans = 0
        
        for i in range(0,len(height)):
            water = min(maxLeft[i],maxRight[i]) - height[i]
            ans += water if water > 0 else 0
        
        return ans
        