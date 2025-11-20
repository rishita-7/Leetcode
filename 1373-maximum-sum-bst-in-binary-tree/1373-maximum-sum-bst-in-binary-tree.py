# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    
    def maxSumBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        self.max_sum=0

        def dfs(ptr):
            if not ptr:
                return (True,float('inf'),float('-inf'),0)
            L_isBST,L_min,L_max,L_sum=dfs(ptr.left)
            R_isBST,R_min,R_max,R_sum=dfs(ptr.right)
            if L_isBST and R_isBST and L_max<ptr.val and ptr.val<R_min:
                curr_sum=R_sum+L_sum+ptr.val
                self.max_sum=max(self.max_sum,curr_sum)
                return (True,min(L_min,ptr.val),max(R_max,ptr.val),curr_sum)
            else:
                return (False,0,0,0)

        dfs(root)
        return self.max_sum



        