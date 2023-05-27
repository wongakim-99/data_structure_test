#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

void inorder(TreeNode* root) {  //inorder case  -->  ������ȸ
	if (root != NULL) {
		inorder(root->left);
		printf("[%d]", root->data);
		inorder(root->right);
	}
}

void preorder(TreeNode* root) {  //preorder case  -->  ������ȸ
	if (root != NULL) {
		printf("[%d]", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode* root) {  //postorder case  -->  ������ȸ
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d]", root->data);
	}
}

int main(void) {
	printf("Hello World!\n");
	return 0;
}