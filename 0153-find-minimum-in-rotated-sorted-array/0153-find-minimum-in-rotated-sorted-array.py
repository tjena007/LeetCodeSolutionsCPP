class Solution:
    def findMin(self, nums: List[int]) -> int:
        l,r = 0, len(nums) - 1

        while l < r: #iterate to the point l == r, return l
            mid = (l+r) // 2
            # print("indexes",l,r,mid)
            # print(nums[l],nums[r],nums[mid])

            if nums[mid] > nums[r]:
                l = mid + 1
            else:
                r = mid
        

        return nums[l]