class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int >    res;
        int i,j;
        if(n <= 0)   return res;
        res.push_back(0);
        res.push_back(1);
        for(i = 2; i <= n; i++){
            int high = 1<<(i-1);
            int len = res.size();
            for(j = len-1; j>=0; j--){
                res.push_back(high+res[j]);
            }
        }
        return res;
    }
};