class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer
    def search(self,A,target,s,e):
    	mid = (s+e)/2
    	if A[mid] == target:
    		return mid
    	elif mid-1>=0 and A[mid-1] < target and A[mid] > target:
    		return mid
    	elif mid+1<=e and A[mid] <target and A[mid+1] >target:
    		return mid+1
    	elif mid == 0 and A[mid] > target:
    		return mid
    	elif mid == e and A[mid] < target:
    		return mid+1
    	elif A[mid] < target:
    		return self.search(A,target,mid+1,e)
    	elif A[mid] > target:
    		return self.search(A,target,s,mid-1)
    def searchInsert(self, A, target):
        return self.search(A,target,0,len(A)-1)
KK = Solution()
print KK.searchInsert([1,3],4)