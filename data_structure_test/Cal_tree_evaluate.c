#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode n1 = { 1,NULL,NULL };  //n1,n2 parent node --> n3
TreeNode n2 = { 4,NULL,NULL };
TreeNode n3 = { '*',&n1,&n2 };

TreeNode n4 = { 30,NULL,NULL };  //n4,n5 parent node --> n6
TreeNode n5 = { 35,NULL,NULL };
TreeNode n6 = { '+',&n4,&n5 };

TreeNode n7 = { '+',&n3,&n6 };  //Super node --> n7
TreeNode* result = &n7;  //result

int evaluate(TreeNode* root) {
	if (root == NULL)  //case1 : root node == NULL  -->  Exit System
		return 0;
	else if (root->left == NULL && root->right == NULL)  
		return root->data;  
	//case2 : If root sub node each side == NULL  ->  /*extract root node data*/ 
	
	else {  //In this case existed root -> sub node(each side)
		int op1 = evaluate(root->left);  //Recursion call
		int op2 = evaluate(root->right);
		printf("%d %c %d Calculation.\n", op1, root->data, op2);

		switch (root->data){
		case'+':
			return op1 + op2;
		case'-':
			return op1 - op2;
		case'*':
			return op1 * op2;
		case'/':
			return op1 / op2;
		case'&&':
			return op1 && op2;
		case'||':
			return op1 || op2;
		}
	}
	return 0;
}

int main(void) {
	printf("Calculator result = %d\n", evaluate(result));
	return 0;
}