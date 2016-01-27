class Solution:
	def rotate(self,nums,k):
		m = k % len(nums)
		n = k / len(nums)
		if m == 0:
			return
		else:
			res = []
			res.append(nums[-m:])
			res.append(nums[0:len(nums)-k])
			res = sum(res,[])
			j = 0
			for i in res:
				nums[j] = i
				j += 1
		return 


kk = Solution()
nums = [1,2,3,4,5]
kk.rotate(nums,3)
print nums