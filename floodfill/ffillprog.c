#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "floodfill.h"
//void impr(char mat[][20]);

void ffill(char mat[][20],int x,int y,char target,char replacement){
    char color_node;
    color_node=mat[x][y];
    if(color_node==replacement){
        return;
    }
    if(color_node!=target){
        return;
    }
    mat[x][y]=replacement;
    ffill(mat,x,y-1,target,replacement);
    ffill(mat,x,y+1,target,replacement);
    ffill(mat,x-1,y,target,replacement);
    ffill(mat,x+1,y,target,replacement);
    return;
}

void impr(char mat[][20]){
    register int i,j;
    printf("\n\n\n");
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            printf("%c",mat[i][j]);
        }
        printf("\n");
     }
}

int main(){
    FILE *fp;
    register int i,j;
    int x,y;
    char s[30];
    char mat[20][20];
    char c;
    printf("Digite o nome do arquivo: ");
    scanf("%s",s);
    strcat(s,".txt");    
    if((fp=fopen(s,"r+"))==NULL){
        printf("Erro arquivo inexistente\n");
        exit(1);
    }
    printf("\n\n\n");
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            c=fgetc(fp);
            printf("%c",c);
            mat[i][j]=c;
        }
        c=fgetc(fp);
        printf("\n");
    }
    fscanf(fp,"%d %d",&x,&y);
    printf("Digite as coordenadas: ");
    scanf("%d %d",&x,&y);
    ffill(mat,x,y,' ','o');
    impr(mat);
    fclose(fp);
    return 0;
}
    
