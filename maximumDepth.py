class Solution:
	def merge(self,A,m,B,n):
		i = j = 0
		copyA = []
		while j < n and i < m:
			if B[j] <= A[i]:
				copyA.append(B[j])
				j += 1
			else:
				copyA.append(A[i])
				i += 1
			print i,j,copyA
		if i <m:
			copyA += A[i:m]
		if j <n:
			copyA +=B[j:n]
		i = 0
		for j in copyA:
			A[i] = j
			i +=1
		return 
kk = Solution()
A = [2,4,6,7,11,0,0,0,0,0,0,0,0,0,0]
B = [3,4,5,7,9,13]
kk.merge(A,5,B,6)
print A
