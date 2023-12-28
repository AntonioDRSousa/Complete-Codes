#include<stdio.h>
#include<stdlib.h>

void newton(int it, double a, double chute){
	int i;
	double x;
	x=chute;
	for(i=0;i<it;i++){
		x=x-((x*x-a)/(2*x));
		printf("iteracao= %d     x%d = %lf\n",i+1,i+1,x);
	}
}

int main(){
	int it;
	double a,chute;
	printf("Digite o numero de iteracoes: ");
	scanf("%d",&it);
	printf("Digite o numero para calcular a raiz: ");
	scanf("%lf",&a);
	printf("Digite o chute inicial para calcular raiz: ");
	scanf("%lf",&chute);
	printf("\n\n\n");
	newton(it,a,chute);
	
	return 0;
}
