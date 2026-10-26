class Solution:
    def maxAbsoluteSum(self, nums: list[int]) -> int:
        
        n = len(nums)
        for i in range(1, n):
            nums[i] = nums[i] + nums[i - 1]
        
        maximum = max(0, max(nums))
        minimum = min(0, min(nums))
        
        
        return maximum - minimum