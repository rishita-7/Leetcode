class Solution:
    def canCross(self, stones: List[int]) -> bool:
        n=len(stones)
        s=set(stones)
        d={0:{0}}   # dictionary-> key: stone visited, key : an array of every jump size through which the stone is reached
        for st in stones:
            if st in d:
                for j in d[st]:
                    if (st+j) in s and (st+j!=st):
                        if st+j in d:
                            d[st+j].add(j)
                        else:
                            d[st+j]={j}
                    if (st+j-1) in s and (st+j-1!=st):
                        if st+j-1 in d:
                            d[st+j-1].add(j-1)
                        else:
                            d[st+j-1]={j-1}
                    if (st+j+1) in s and (st+j+1!=st):
                        if st+j+1 in d:
                            d[st+j+1].add(j+1)
                        else:
                            d[st+j+1]={j+1}

        if stones[n-1] in d:
            return True
        return False