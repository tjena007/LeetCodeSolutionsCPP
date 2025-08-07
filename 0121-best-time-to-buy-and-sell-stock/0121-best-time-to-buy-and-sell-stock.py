class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans = float('-inf')
        min_price = prices[0]

        for price in prices:
            if price < min_price:
                min_price = price
            
            ans = max(ans,price - min_price)
        

        return ans