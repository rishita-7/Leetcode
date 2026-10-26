class Solution:
    def findTargetSumWays(self, nums: list[int], target: int) -> int:
        n = len(nums)
        memo = {} 

        def fun(index, current_sum):
            if index == n:
                return 1 if current_sum == target else 0
            
            curr = (index, current_sum)
            
            if curr in memo:
                return memo[curr]
            
            add = fun(index + 1, current_sum + nums[index])
            sub = fun(index + 1, current_sum - nums[index])
            
            memo[curr] = add + sub
            return memo[curr]

        return fun(0, 0)