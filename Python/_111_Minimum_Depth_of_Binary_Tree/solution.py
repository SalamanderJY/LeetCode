# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        else:
            left = self.minDepth(root.left)
            right = self.minDepth(root.right)
            return min(left, right) + 1 if min(left, right) > 0 else max(left, right) + 1
