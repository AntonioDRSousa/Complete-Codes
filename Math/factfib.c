#include<stdio.h>

unsigned long int i=0;

unsigned int fib(int x){
	i++;
	if(x<=1){
		return x;
	}
	else{
		return fib(x-1)+fib(x-2);
	}
}	

unsigned int fat(int x){
	if(x==0){
		return 1;
	}
	else{
		return x*fat(x-1);
	}
}

int main(void){
	int n;
	printf("Digite um numero: ");
	scanf("%d",&n);
	printf("\nFib(%d) = %u\n",n,fib(n));
	printf("\n%d! = %u\n",n,fat(n));
	printf("%d\n",i);
	return 0;
}
