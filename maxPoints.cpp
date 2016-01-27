#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
 struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};


class Solution{
public:
        int maxPoints(vector<Point> &points){
            unordered_map<float,int>map;
            int Max = 99999;
            int maxNum = 0;
            int same = 0;
            for(int i = 0;i < points.size();i++){
                map.clear();
                map[-99999] = 0;      //这边要注意的是当只有一个点的时候，不会写入map此时map为空则不会走最后一步，所以要使map中起码有一个点
                same = 0;
                for(int j = 0; j < points.size();j++){
                    if(i == j)  continue;
                    if(points[i].x == points[j].x && points[i].y == points[j].y){
                        same++;
                        continue;
                    }
                  //   cout<<"aa"<<endl;
                    float slope = points[i].x == points[j].x ? Max : (float)(points[i].y - points[j].y)/(float)(points[i].x - points[j].x);
                    map[slope]++;
                }
                unordered_map<float,int>::iterator iter = map.begin();
                for(;iter != map.end();iter++){
                    if(iter->second + same + 1 > maxNum){
                        maxNum = iter->second+same+1;
                    }
                }
            }
            return maxNum;
        }
};
int main()
{

    Solution sol;
    vector<Point> points;
    for(int i =0;i < 1;i++)
    {
        Point pos;
        cin>>pos.x;
        cin>>pos.y;
        points.push_back(pos);
    }
    cout<<sol.maxPoints(points)<<endl;
}
