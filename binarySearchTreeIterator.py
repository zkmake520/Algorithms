class TreeNode:
	def __init__(self,x):
		self.val = x
		self.left = None
		self.right = None
class BSTIterator:
    # @param root, a binary search tree's root node
    def __init__(self, root):
        self.root = root
        self.currentNode = None
        self.stack = list()
       	self.call = 0
       	self.popRes = None
    # @return a boolean, whether we have a next smallest number
    def hasNext(self):
        if self.call == 0:
            if self.root == None:
                return False
            root = self.root
            while root.left !=None:
                self.stack.append(root)
                root = root.left
            self.stack.append(root)
            self.call = 1
            return True
        else:
            if self.popRes.right != None:
                root =self.popRes.right
                self.stack.append(root)
                while root.left !=None:
                    self.stack.append(root)
                    root = root.left
                self.stack.append(root)
            if not self.stack:
                return False
            return True
    # @return an integer, the next smallest number
    def next(self):
    	res = self.stack.pop(len(self.stack)-1)
    	self.popRes=res
    	return res.val
        
a1 = TreeNode(7)
a2 = TreeNode(6)
a3 = TreeNode(1)
a4 = TreeNode(5)
a5 = TreeNode(4)
a6 = TreeNode(3)
a7 = TreeNode(2)
a1.left = a2
a1.right = None
a2.left = a3
a2.right = None
a3.left = None
a3.right = a4
a4.left = a5
a4.right =None
a5.left = a6
a5.right =None
a6.left = a7
a6.right =None
a7.left = None
a7.right =None

i,v = BSTIterator(a1),[]
while i.hasNext():
	v.append(i.next())
print v

