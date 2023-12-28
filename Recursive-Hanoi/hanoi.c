#include<stdio.h>

void hanoi(int,char,char,char);

int main(){
	int n;
	printf("n = ");
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	return 0;
}

void hanoi(int n,char orig,char dest,char aux){
	if(n>0){
		hanoi(n-1,orig,aux,dest);
		printf("%c -> %c\n",orig,dest);
		hanoi(n-1,aux,dest,orig);
	}
}
