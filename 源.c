#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef struct Tree{
	int data;
	struct Tree *left;
	struct Tree *right;
}*BiTree, BiNode;

typedef struct list{
	int data[MAX];
	int size;
}Sqlist;

BiTree reConstructBinaryTree(Sqlist *pre, Sqlist *in){
	if (in->size == 0){
		return NULL;
	}
	BiTree  b;
	b = NULL;
	if (pre->size!=0){
		b = (BiTree)malloc(sizeof(BiNode));
		b->data = pre->data[0];
	}
	int i = 0;
	int j = 0;
	int father = 0;
	for (i = 0; i < in->size ; i++){
		if (in->data[i] == pre->data[0]){
			father = i;
			break;
		}
	}
	Sqlist pre_left, in_left, pre_right,in_right;
	pre_left.size = 0;
	in_left.size = 0;
	pre_right.size = 0;
	in_right.size = 0;
	for (i = 0; i < father; i++){
		pre_left.data[i] = pre->data[i + 1];
		pre_left.size++;
		in_left.data[i] = in->data[i];
		in_left.size++;
	}
	for (i = father + 1,j=0; i < in->size; i++,j++){
		pre_right.data[j] = pre->data[i];
		pre_right.size++;
		in_right.data[j] = in->data[i];
		in_right.size++;
	}

	b->left = reConstructBinaryTree(&pre_left, &in_left);
	b->right = reConstructBinaryTree(&pre_right,&in_right);
	return b;
}

void Pre_Print(BiTree b){
	if (b != NULL){
		printf("%d,", b->data);
	}
	if (b->left != NULL){
		Pre_Print(b->left);
	}
	if (b->right != NULL){
		Pre_Print(b->right);
	}
}
void In_Print(BiTree b){
	if (b->left != NULL){
		Pre_Print(b->left);
	}
	if (b != NULL){
		printf("%d,", b->data);
	}
	if (b->right != NULL){
		Pre_Print(b->right);
	}
}

int main(){
	
	Sqlist  pre;
	pre.size = 0;
	Sqlist  in;
	in.size = 0;
	int i = 0;
	int num = 0;
	printf("请输入共有多少个结点：\n");
	scanf("%d", &num);
	printf("请输入先序序列：\n");
	for (i = 0; i < num; i++){
		scanf(" %d",&pre.data[i]);
		pre.size++;
	}
	printf("请输入中序序列：\n");
	for (i = 0; i < num; i++){
		scanf(" %d", &in.data[i]);
		in.size++;
	}
	reConstructBinaryTree(&pre, &in);
	Pre_Print(reConstructBinaryTree(&pre, &in));
	In_Print(reConstructBinaryTree(&pre, &in));
	system("pause");
	return 0;
}