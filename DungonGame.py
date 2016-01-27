import sys
class Solution:
    # @param dungeon, a list of lists of integers
    # @return a integer
    def calculateMinimumHP(self, dungeon):
        col =len(dungeon[0])
        row = len(dungeon)
        dp =[[0]*col]*row
        dp[row-1][col-1] = -dungeon[row-1][col-1] + 1 if dungeon[row-1][col-1] <= 0 else 0
        i = row-1
        j = col -1
        tmp = 0
       	while i >= 0:
       		j = col -1
       		while j >=0:
       			if(i == row-1) and (j == col-1):
       				pass
       			else:
	       			right = down = 0
	       			if j +1 < col:
	       				right = dp[i][j+1] 
	       			else:
	       				right = sys.maxint
	       			if i +1 < row:
	       				down = dp[i+1][j]
	       			else: 
	       				down = sys.maxint	
	       			if dungeon[i][j] <= 0:
	       				tmp = min(right,down)
	       				if tmp > 0:
	       					dp[i][j] = -dungeon[i][j]+ min(right,down)
	       				else:
	       					dp[i][j] = -dungeon[i][j]+ tmp+1
	       				
	       			elif dungeon[i][j] >0:
	       				tmp = min(right,down)
	       				
	       				if dungeon[i][j]-tmp >= 1:
	       					 dp[i][j] = 0   
	       		    	else: 
	
	       		    		 dp[i][j] = tmp-dungeon[i][j]
	       		    		 
	       		    		 	
	       		j -= 1
       		i -= 1	
       	if dp[0][0] == 0:
       		dp[0][0] +=1
       	return dp[0][0]


res = Solution()
print res.calculateMinimumHP([[3,-20,30],[-3,4,0]])