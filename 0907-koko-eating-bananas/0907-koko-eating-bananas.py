class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l,r = 1,max(piles)
        ans = r #minimise this while being in bourndary condition

        def checkHours(n):
            count = 0
            for p in piles:
                # print('helper',p,n)
                count += math.ceil(p/n)
                if count > h:
                    return False
            
            return count <= h

        while l<=r:
            mid = (l+r) // 2

            if checkHours(mid):
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        
        return ans

