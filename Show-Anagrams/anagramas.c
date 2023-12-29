#include<stdio.h>
#include<string.h>

char ch;
int numero;

void initBol(int n,int * s){
	int i;
	for(i=1;i<=n;i++){
		s[i]=0;
	}			
}

void impr(int n,char * p){
	int j;
	for(j=1;j<=(n);j++){
		printf("%c",p[j]);
	}
	printf(" ");
	if(numero%15==0){
		printf("\n");
	}
}

void perm(int n,int * s,int * np,char * p,char * v){
	int i;
	for(i=1;i<=n;i++){
		if(s[i]==0){ 
			(*np)++;
			p[(*np)]=v[i];
			s[i]=1;
	
			if((*np)==n){
				numero++;
				impr(n,p);
			}
			else{
				perm(n,s,np,p,v);
			}
			(*np)--;
			s[i]=0;
		}
	}
}

void permut(char * v,int n){
	int np=0;
	int s[9];
	char p[9];

	numero=0;
	
	initBol(n,s);
	perm(n,s,&np,p,v);
}

void prog(){
	int n;
	char v[9];
	char s[30];
	do{
		printf("digite uma string de no maximo 8 letras-> ");
		scanf("%s",s);
	}while(strlen(s)>8);
	n=strlen(s);
	int i;
	for(i=0;i<8;i++){
		v[i+1]=s[i];
	}
	permut(v,n);
}
	
int main(){
	do{
		prog();
		printf("\nDeseja continuar(caracter s)? ");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='s');
	return 0;
}
