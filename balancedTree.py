class TreeNode:
    def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None
class Solution:
	balanced = True
	def isBalanced(self,root):
		if root == None:
			return True
		self.height(root)
		return self.balanced

	def height(self,root):
		if(root == None):
			return 0
		l = self.height(root.left)
		r = self.height(root.right)
		if(l >= r+2 or r >=l +2):
			self.balanced = False
		return l+1 if l>r else r+1

