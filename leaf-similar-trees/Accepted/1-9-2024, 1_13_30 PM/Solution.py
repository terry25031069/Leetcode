// https://leetcode.com/problems/leaf-similar-trees

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        l = [[], []]
        def dfs(root: Optional[TreeNode], num: int):
            if root.left:
                dfs(root.left, num)
            if root.right:
                dfs(root.right, num)
            if root.left == None and root.right == None:
                l[num].append(root.val)
        dfs(root1, 0)
        dfs(root2, 1)
        return l[0] == l[1]