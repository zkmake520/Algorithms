class Solution {
public:
    bool isHappy(int n) {
    	unordered_set<int> map;
    	map.insert(n);
    	if( n == 1){
    		return true;
    	}
    	while(true){
    		int tmp = n;
    		std::vector<int> v;
    		while(tmp != 0){
    			v.push_back(tmp%10);
    			tmp = tmp / 10;
    		}
    		int sum = 0;
    		for(int i = 0; i < v.size(); i++){
    			sum += v[i] * v[i];
    		}
    		if(sum==1){
    			return true;
    		}
    		else if(map.find(sum) != map.end())
                return false;
            else{
            	n = sum;
            	map.insert(n);
            }
    	}

    }
};