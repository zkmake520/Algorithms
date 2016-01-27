class Solution:
	def reverseBits(self,n):
		res = ""
		for i in range(32):
			res += str(n & 1)
			n = n>>1
		return int(res,2)
kk = Solution()
print kk.reverseBits(43261596)
