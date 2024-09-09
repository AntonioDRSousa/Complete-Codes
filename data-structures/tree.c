#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	unsigned int id;
	int value;
	struct Node * father;
	struct Node * childs;
	struct Node * next;
}Node;

typedef struct Tree{
	Node * root;
	unsigned int nlevels;
}Tree;

// input functions

unsigned int readTree(Node * node,Node * father,unsigned int level){
	unsigned int static id=0;
	unsigned int static nlevels=1;
	
	if(level>nlevels){
		nlevels=level;
	}
	
	node->id=id;
	node->father=father;
	
	printf("id : %u | father : %u | level: %u . Write value : ",id,father->id,level);
	scanf("%d",&(node->value));
	id++;
	
	unsigned int nchilds;
	printf("how many child nodes ? ");
	scanf("%d",&nchilds);
	
	if(nchilds>0){
		register int i;
		node->childs = (Node *) malloc(sizeof(Node));
		Node * p = node->childs;
		for(i=1;i<nchilds;i++){
			p->next=(Node *) malloc(sizeof(Node));
			p=p->next;
		}
		p->next=NULL;
		
		p=node->childs;
		while(p){
			readTree(p,node,level+1);
			p=p->next;
		}
	}
	else{
		node->childs=NULL;
	}
	
	return nlevels;
}

Tree initTree(){
	Tree tree;
	tree.root=(Node *) malloc(sizeof(Node));
	tree.nlevels = readTree(tree.root,tree.root,1);
	return tree;
}

// output functions

void printNode(char * s1 ,Node node,unsigned int level,char * s2){
	printf("%sid : %u | level : %u | value : %d%s",s1,node.id,level,node.value,s2);
}

void writeTree(Node node,unsigned int level){
	printNode("\n\n",node,level," -> ");
	
	if(node.childs){
		Node * p = node.childs;
		while(p){
			printNode("\n\t[",*p,level+1,"]");
			p=p->next;
		}
		p = node.childs;
		while(p){
			writeTree(*p,level+1);
			p=p->next;
		}
	}
	printf("\n");
}

void printTree(Tree tree){
	printf("\n------------------------\n\n");
	
	printf("number of levels : %d\n\n",tree.nlevels);
	
	writeTree(*(tree.root),1);
	printf("\n------------------------\n");
}

void main(){
	Tree tree = initTree();
	
	printTree(tree);
	
	system("pause");
}