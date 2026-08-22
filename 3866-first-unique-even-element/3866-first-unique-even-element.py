class Solution:
    def firstUniqueEven(self, nums: list[int]) -> int:
        d={}
        for n in nums:
            d[n]=d.get(n,0)+1
        for n in nums:
            if n%2==0 and d[n]==1:
                return n
        return -1

        