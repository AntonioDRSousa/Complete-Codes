#include<stdio.h>
#include<stdlib.h>

int phell(int x, int * r){
	int exp;
	for(exp=0,*r=x;*r>=(2*exp+1);exp++){
		*r -= 2*exp+1;
	}
	return exp;
}

int main(){
	int x, exp, r;
	scanf("%d",&x);
	
	exp = phell(x,&r);
	printf("square root of %d ->\n",x);
	printf("integer result -> %d\n",exp);
	printf("remainder -> %d\n",r);
	return 0;
}