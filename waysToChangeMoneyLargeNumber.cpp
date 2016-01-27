#include<iostream>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<fstream>
#include<ostream>
#include<vector>
#include<stdio.h>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;

int cupNumber, totalNumber;
vector<int> cupVolume;
long result = 0;

void countMethods(int leftNumber, int lastV){
    if(leftNumber == 0){
        result++;
        return;
    }
    else if(leftNumber <0)  return ;
    else{
        for(int i = 0 ; i< cupNumber; i++){
            if(cupVolume[i] < lastV) continue;
            countMethods(leftNumber-cupVolume[i], cupVolume[i]);
        }
    }
}
int main(){
    cin>>cupNumber;
    cin>>totalNumber;
    int temp;
    for(int i = 0; i < cupNumber; i++){
        cin >> temp;
        cupVolume.push_back(temp);
    }
    int lastV =-1;
    countMethods(totalNumber,lastV);
    cout<<result;
}
