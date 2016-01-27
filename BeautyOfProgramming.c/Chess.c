#include<stdio.h>
#include<string.h>


#define FULL_MASK 255
#define HALF_SIZE 4
#define RMASK (FULL_MASK>>HALF_SIZE)
#define LMASK (FULL_MASK<<HALF_SIZE)
#define lSet(var,n) (var = (var&RMASK) ^ (n<<HALF_SIZE))
#define rSet(var,n) (var = (var&LMASK) ^ n)
#define lGet(var) (var >> HALF_SIZE)
#define rGet(var) (RMASK & var)
int main(int argc,char *argv[]){
	unsigned char var;
	for(lSet(var,1); lGet(var) <= 9; lSet(var,(lGet(var)+1))){
		for(rSet(var,1); rGet(var) <= 9; rSet(var,rGet(var)+1)){
			if(lGet(var) %3 != rGet(var) %3){
				printf("A=%d,B=%d\n",lGet(var),rGet(var));
			}
		}
	}
}