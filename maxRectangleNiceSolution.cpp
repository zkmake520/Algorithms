//
//  maxRectangleNiceSolution.cpp
//  
//
//  Created by zkwangchao on 14-4-11.
//
//
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row = matrix.size();
        if(!row)    return 0;
        int col = matrix[0].size();
        if(!row || !col)    return 0;
        int maxArea = 0;
        int cur = -1;
        vector<vector<int >> H (row+1,vector<int>(col+1,0));
        vector<vector<int >> L (row+1,vector<int>(col+1,0));
        vector<vector<int >> R (row+1,vector<int>(col+1,0));
        for(int i = 0; i < row; i++){ // find the height of each unit;
            for(int j = 0; j < col; j++){
                H[i][j] = matrix[i][j] == '1'?1:0;
                H[i][j] = (H[i][j] == 1 && i-1>=0)? H[i][j]+H[i-1][j]:H[i][j];
                
            }
        }
        for(int i = 0 ; i <row; i++)//for each unit find the right and left that can expand to
        {
            for(int j = 0; j< col;j++){ // expand to left
                L[i][j] = j;
                while(L[i][j] > 0){
                    if(H[i][j] <= H[i][L[i][j]-1]){
                        L[i][j] = L[i][L[i][j]-1];
                    }
                    else break;
                }
            }
            for(int j = col-1; j >= 0; j--){  //expand to right
                R[i][j] = j;
                while(R[i][j] < col-1){
                    if(H[i][j] <= H[i][R[i][j] + 1]){
                        R[i][j] = R[i][R[i][j]+1];
                    }
                    else break;
                    
                }
            }
        }
        /*for(int i = 0; i < row;i++){
         cout<<""<<endl;
         for(int j = 0 ; j <col;j++){
         cout<<R[i][j];
         }
         }
         for(int i = 0; i < row;i++){
         cout<<""<<endl;
         for(int j = 0 ; j <col;j++){
         cout<<L[i][j];
         }
         }*/
        for(int i = 0; i < row;i++){
            //    cout<<""<<endl;
            for(int j = 0 ; j <col;j++){
                //        cout<<H[i][j];
                if(H[i][j]){
                    maxArea  = maxArea > (R[i][j]-L[i][j]+1)*H[i][j]?maxArea:(R[i][j]-L[i][j]+1)*H[i][j];
                }
            }
        }
        return maxArea;
        
    }
    
};

