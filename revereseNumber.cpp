//
//  revereseNumber.cpp
//  
//
//  Created by zkwangchao on 14-4-9.
//
//

#include "revereseNumber.h"
class Solution {
public:
    int reverse(int x) {
        int flag = x<0?-1:1;
        int ans = 0;
        while(x != 0){
            ans = ans*10+x%10;
            x=x/10;
        }
        return ans;
        
    }
};