#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	unsigned int id;
	int value;
	struct Node * right;
	struct Node * left;
}Node;

typedef struct BinTree{
	Node * root;
	unsigned int nlevels;
}BinTree;

// input functions

void readTree(Node * node,unsigned int id_father, unsigned int level){
	unsigned int static id=0;
	printf("id : %u | father : %u | level: %u . Write value : ",id,id_father,level);
	scanf("%d",&(node->value));
	node->id=id;
	node->left=NULL;
	node->right=NULL;
	id ++;
	if(level>1){
		node->right=(Node *) malloc(sizeof(Node));
		node->left=(Node *) malloc(sizeof(Node));
		readTree(node->right,node->id,level-1);
		readTree(node->left,node->id,level-1);
	}
}

BinTree initTree(){
	BinTree tree;
	tree = (Node *) malloc(sizeof(Node));
	printf("Write number of levels of Binary Tree: ");
	scanf("%u",&(tree.nlevels));
	readTree(tree.root,0,tree.nlevels);
	return tree;
}

// output functions

void printNode(char * s1 ,Node node,unsigned int level,char * s2){
	printf("%sid : %u | level : %u | value : %d%s",s1,node.id,level,node.value,s2);
}

void writeTree(Node node,unsigned int level){
	printNode("\n",node,level," -> ");
	if(level>1){
		printNode("\n\tleft : [",*(node.left),level-1,"] , "); 
		printNode("\n\tright : [",*(node.right),level-1,"] }\n");
		writeTree(*(node.left),level-1);
		writeTree(*(node.right),level-1);
	}
	else{
		printf("\n");
	}
}

void printTree(Node node,unsigned int nlevels){
	printf("\n------------------------\n\n");
	writeTree(node,nlevels);
	printf("\n------------------------\n");
}

// other functions

void inverte(Node * node,unsigned int level){
	Node * tmp = node->right;
	node->right=node->left;
	node->left=tmp;
	if(level>1){
		inverte(node->right,level-1);
		inverte(node->left,level-1);
	}
}

void main(){
	BinTree tree = initTree();
	
	printTree(*(tree.root),tree.nlevels);
	
	inverte(tree.root,tree.nlevels);
	
	printTree(*(tree.root),tree.nlevels);
	
	system("pause");
}