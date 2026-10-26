class Solution:
    def maxAbsoluteSum(self, nums: list[int]) -> int:
        
        n = len(nums)
        for i in range(1, n):
            nums[i] = nums[i] + nums[i - 1]
        
        maximum = max(nums)
        minimum = min(nums)
        
        if(maximum<0):
            return abs(minimum)
        if(minimum>=0):
            return maximum
        return maximum - minimum