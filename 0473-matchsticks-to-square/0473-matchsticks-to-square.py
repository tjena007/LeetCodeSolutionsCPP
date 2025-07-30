class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        if len(matchsticks) < 4:
            return False

        total = sum(matchsticks)
        if total % 4 != 0:
            return False
        target = total // 4

        matchsticks.sort(reverse=True)
        sides = [0] * 4

        def backtrack(i):
            if i == len(matchsticks):
                return sides[0] == sides[1] == sides[2] == sides[3] == target
            
            for j in range(4):
                if sides[j] + matchsticks[i] <= target:
                    sides[j] += matchsticks[i]
                    if backtrack(i + 1):
                        return True
                    sides[j] -= matchsticks[i]
                
                # Optimization: if this side is still 0 after placing attempt,
                # no point trying other identical empty sides.
                if sides[j] == 0:
                    break
            
            return False
        
        return backtrack(0)
