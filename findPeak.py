class Solution:
	def findPeakElement(self,num):
		return self.find(num,0,len(num)-1)

	def find(self,num,l,r):
		if l == r:
			return l
		if l+1 == r:
			return l if num[l]>num[r] else r
		mid = (l+r)/2
		if num[mid] < num[mid-1]:
			return self.find(num,l,mid-1)
		else:
			return self.find(num,mid,r)

kk = Solution()
print kk.findPeakElement([1,3,4,2,3])
