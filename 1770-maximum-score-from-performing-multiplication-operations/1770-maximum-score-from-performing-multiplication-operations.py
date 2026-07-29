class Solution:
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
        m=len(multipliers)
        n=len(nums)
        @cache
        def dp(left:int,right:int,k:int)->int:
            if k>=m or left>=n or right<0 :
                return 0
            a=dp(left+1,right,k+1)+(nums[left]*multipliers[k])
            b=dp(left,right-1,k+1)+(nums[right]*multipliers[k])
            return max(a,b)
        return dp(0,n-1,0)
