class Solution:
	def hammingWeight(self,n):
		count = 0
		while n !=0:
			count += 1 if n&1 == 1 else 0
			n = n >>1
		return count 
kk = Solution()
print kk.hammingWeight(11)
