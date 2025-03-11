class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set(nums)  # Use a set instead of a dictionary
        ans = 0

        for num in num_set:
            if num - 1 in num_set:  # Skip if not the start of a sequence
                continue

            c = 1  # Count starts from 1
            while num + c in num_set:
                c += 1
            
            ans = max(ans, c)  # Update max sequence length
        
        return ans
