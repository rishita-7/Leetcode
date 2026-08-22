class Solution:
    def arr_gcd(self,numsDivide:List[int])->int:
        g=numsDivide[0]
        for n in numsDivide:
            g=math.gcd(g,n)
        return g
    def minOperations(self, nums: List[int], numsDivide: List[int]) -> int:
        g=self.arr_gcd(numsDivide)
        nums.sort()
        c=0
        for n in nums:
            if g%n==0:
                return c
            c+=1
        return -1

