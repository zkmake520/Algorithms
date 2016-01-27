class TreeNode:
    def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None

class Solution:
	def levelOrder(self,root):
		res = []
		resLevel = []
		queue = []
		if root == None:
		    return res
		queue.append((root,0))
		current_level = 0
        
		while queue:
			first = queue[0][0]
			level = queue[0][1]
			if level == current_level:
			    resLevel.append(first.val)
			else:
			    res.append(resLevel)
			    resLevel =[]
			    current_level = level
			    resLevel.append(first.val)
			queue.pop(0)
			if first.left != None:
				queue.append((first.left,level+1))
			if first.right != None:
				queue.append((first.right,level+1))
		res.append(resLevel)
		res.reverse()
		return res


