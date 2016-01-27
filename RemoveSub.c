#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
	int parent;
	bool valid = true; 
	bool visited = false;
};
typedef struct node Node;


bool removeIdx(Node *root,int i,int idx){
	Node *tmp = root + i;

	if(tmp->visited == true){
		return tmp->valid;
	}
	tmp->visited = true;
	if(i == idx){
		tmp->valid = false;
		tmp->visited = true;
		
		return false;
	}
	if(tmp->parent == -1){

		tmp->valid  = true;
		return true;
	}
	tmp->valid = removeIdx(root,tmp->parent,idx);
	
	return tmp->valid;
}
void RemoveSubTree(Node * root, int idx, int n){
	for(int i= 0; i < n; i++){
		bool valid = removeIdx(root,i,idx);
		if(valid == false){
			printf("Remove index:%d\n",i);
		}
	}
}


int main(){
	Node n[8];
	
	n[0].parent = 7;
	n[1].parent = 5;
	n[2].parent = 4;
	n[3].parent = 4;
	n[4].parent = 6;
	n[5].parent = 7;
	n[6].parent = 7;
	n[7].parent = -1;
	RemoveSubTree(n,7,8);
}