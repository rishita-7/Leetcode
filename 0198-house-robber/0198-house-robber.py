class Solution:
    def rob(self, nums: List[int]) -> int:
        @cache
        def dfs(ind: int)->int:
            if ind>=len(nums):
                return 0
            rob_current=nums[ind]+dfs(ind+2)
            skip_current=dfs(ind+1)
            return max(rob_current,skip_current)

        return dfs(0)