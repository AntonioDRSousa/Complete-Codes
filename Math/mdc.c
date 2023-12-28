#include<stdio.h>

int mdc(int,int);

int main(){
	int x,y;
	printf("Digite x e y: ");
	scanf("%d %d",&x,&y);
	printf("mdc(%d,%d) = %d\n",x,y,mdc(x,y));
	return 0;
}

int mdc(int x, int y){
	if(y==0){
		return x;
	}
	else{
		return mdc(y,x%y);
	}
}
