# Definition for singly-linked list.
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution:
    # @param two ListNodes
    # @return the intersected ListNode
    def getIntersectionNode(self, headA, headB):
    	hA = headA
    	hB = headB
    	y = 1
    	while headA.next != None:
    		headA = headA.next
    	while headB.next != None:
    		headB = headB.next
    		y  += 1
    	headA.next = hA
    	one = hB
    	two = hB
    	while(one.val != two.val or one.val == hB.val):
    		one = one.next
    		two =two.next.next
    	headA.next = None
    	return one.val
ha = ListNode(1)
hb = ListNode(3)
h1 = ListNode(2)
h2 = ListNode(4)
h3 = ListNode(5)
h4 = ListNode(6)
h5 = ListNode(7)
h6 = ListNode(8)
ha.next = h1
hb.next= h2
h2.next = h3
h3.next = h4
h4.next =h5
h5.next = h6
h1.next = h4
kk = Solution();
print kk.getIntersectionNode(ha,hb)
