#include<iostream>
#include<string>
#include <algorithm>
#include<stdlib.h>
#include<math.h>
#include<fstream>
#include<vector>
#include<stdio.h>
#include<unordered_map>
#include<stack>
#define  NIL -1;
#define NUM 4;
int NewTurn[4];
int GetPositionFromLaday(int ladayArray[][4], int laday, int man){
    for(int i = 0; i<4;i++)
        if(ladayArray[laday][i] == man)
            return i;
    return -1;
}
void ChoosePartener(std::stack<int>& manStack, int manPos, int manArray[][4], int ladayArray[][4],int manPerfer[]
                    ,int manStartPos[], int ladayNow[]){
    
    int perferLaday = manArray[manPos][manStartPos[manPos]];
    
    if(ladayNow[perferLaday] == -1){
        ladayNow[perferLaday] = manPos;
        manPerfer[manPos] = perferLaday;
    }
    else{
        int oldPos = GetPositionFromLaday(ladayArray, perferLaday, ladayNow[perferLaday]);
        int newPos = GetPositionFromLaday(ladayArray, perferLaday, manPos);
        if(oldPos < newPos)
        {
            manStartPos[manPos]++;//说明该女生更喜欢现在拥有的，选心目中第二位
            manStack.push(manPos);
        }
        else{
            //被甩的男友恢复自由身份
            if(NewTurn[ladayNow[perferLaday]] == 1){
                manStartPos[ladayNow[perferLaday]] = 0;
                NewTurn[ladayNow[perferLaday]] = 0;
            }
            else  manStartPos[ladayNow[perferLaday]]++;
            manStack.push(ladayNow[perferLaday]);
            ladayNow[perferLaday] = manPos;
            manPerfer[manPos] = perferLaday;
            
        }
    }
    
}
int main(){
    int manArray[4][4] = {{2,3,1,0},{2,1,3,0},{0,2,3,1},{1,3,2,0}};
    int ladayArray[4][4] = {{0,3,2,1},{0,1,2,3},{0,2,3,1},{1,0,3,2}};
    int manPrefer[4] = {0};
    int manStartPos[4] = {0};
    int ladayNow[4]={-1,-1,-1,-1};
    
    std::stack<int> manStack;
    for(int pos = 0; pos < 4; pos++)
        ChoosePartener(manStack,pos,manArray,ladayArray,manPrefer,manStartPos,ladayNow);
    while(manStack.size()!=0){
        int manPos = manStack.top();
        manStack.pop();
        ChoosePartener(manStack,manPos,manArray,ladayArray,manPrefer,manStartPos,ladayNow);
        
    }
    NewTurn[0] = NewTurn[1] = NewTurn[2] = NewTurn[3] = 1;
    for(int i = 0;i <4;i++)
        std::cout<<"Man NO.:  "<<i<<" Laday No. :" << manPrefer[i] <<std::endl;
    //for(int i = 0; i < NUM;i++)
    //  cout<<"Man NO.: "<<i<<" Laday NO.: "<<manPerfer[i]<<endl;
    int manArray1[4][4] = {{2,3,1,0},{2,3,1,0},{0,2,3,1},{1,3,2,0}};
    int ladayArray1[4][4] = {{0,3,2,1},{0,1,2,3},{0,2,3,1},{1,0,3,2}};
    manStack.push(1);
    NewTurn[1] = 0;
    memset(manStartPos,0,sizeof(manStartPos));
    manStartPos[1] = 1;
    ladayNow[1] = -1;
    while(manStack.size()!=0){
        int manPos = manStack.top();
        manStack.pop();
        ChoosePartener(manStack,manPos,manArray1,ladayArray1,manPrefer,manStartPos,ladayNow);
    }
    for(int i = 0;i <4;i++)
        std::cout<<"Man NO.:  "<<i<<" Laday No. :" << manPrefer[i] <<std::endl;
    
}

