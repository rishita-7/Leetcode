class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        n = len(nums)
        def rec(start, temp_set):
            res.append(temp_set[:])
            
            for i in range(start, n):
                temp_set.append(nums[i])
                rec(i + 1, temp_set)
                temp_set.pop()  
        rec(0,[])
        return res