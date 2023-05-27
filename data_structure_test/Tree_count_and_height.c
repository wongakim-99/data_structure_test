#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

int get_node_count(TreeNode* node) {  //Tree Node count
	int count = 0;
	
	if (node != NULL) 
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	
	return count;
}

int get_leaf_count(TreeNode* node) {  //finding terminal node
	int count = 0;

	if (node != NULL) {
		if (node->left == NULL && node->right == NULL)
			return 1;
		else
			count = get_leaf_count(node->left) + get_leaf_count(node->right);
	}
	return count;
}

void inorder(TreeNode* root) {  //Inorder method
	if (root != NULL) {  //Root node =/= NULL  -->  Recursion method select
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}

void pre_order(TreeNode* root) {  //Preorder method
	if (root != NULL) {   //Root node =/= NULL  -->  Recursion method select
		printf("[%d] ", root->data);
		pre_order(root->left);
		pre_order(root->right);
	}
}

void post_order(TreeNode* root) {  //post_order method
	if (root != NULL) {    //Root node =/= NULL  -->  Recursion method select
		post_order(root->left);
		post_order(root->right);
		printf("[%d] ", root->data);
	}
}

int get_height(TreeNode* node) {  //Calculating Tree height
	int height = 0;

	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));

	return height;
}

//Creating Level3 Node --> n1,n2,n3,n4 node level == 3

//                    n11
//                /       \
//             n9             n10
//           /   \           /   \
//          n5    n6      n7      n8
//        /  \   /       / 
//      n1   n2  n3     n4 

/*51~54 level4 node*/
TreeNode n1 = { 6,NULL,NULL };
TreeNode n2 = { 10,NULL,NULL };
TreeNode n3 = { 11,NULL,NULL };
TreeNode n4 = { 2,NULL,NULL };

/**/
TreeNode n5 = { 13,&n1,&n2 };
TreeNode n6 = { 20,&n3,NULL };
TreeNode n7 = { 34,&n4,NULL };
TreeNode n8 = { 200,NULL,NULL };

TreeNode n9 = { 100,&n5,&n6 };
TreeNode n10 = { 212,&n7,&n8 };

TreeNode n11 = { 12,&n9,&n10 };

void select_service_number() {
	printf("What do you want to service?\n\n");
	printf("1. Find number of nodes.\n");
	printf("2. Finding number of terminal nodes.\n");
	printf("3. Find height of nodes.\n");
	printf("4. Select tree traversal method.\n");
	printf("5. End program.\n");
}

void TreeTraversalMethod() {
	printf("\n\n1. Preorder method\n");
	printf("2. Inorder method\n");
	printf("3. Postorder method\n");
	printf("4. End program\n");
}

int main(void) {
	int service_num;  //all service number
	int tree_traversal;  //Tree traversal service number

	while (1) {
		select_service_number();
		printf("\nSelect service number : ");
		scanf("%d", &service_num);

		if (service_num == 1) {
			printf("Node counting result = %d\n", get_node_count(&n11));
			break;
		}
		else if (service_num == 2) {
			printf("Node counting result = %d\n", get_leaf_count(&n11));
			break;
		}
		else if (service_num == 3) {
			printf("Tree height result = %d\n", get_height(&n11));
			break;
		}
		else if (service_num == 4) {
			while (1) {
				TreeTraversalMethod();
				printf("\nSelect tree traversal number : ");
				scanf("%d", &tree_traversal);
				
				if (tree_traversal == 1) {
					printf("Preorder result = ");
					pre_order(&n11);
					exit(1);
				}
				else if (tree_traversal == 2) {
					printf("Inorder result = ");
					inorder(&n11);
					exit(1);
				}
				else if (tree_traversal == 3) {
					printf("Postorder result = ");
					post_order(&n11);
					exit(1);
				}
				else if (tree_traversal == 4) {
					printf("End system...\n");
					exit(1);
				}
				else {
					printf("Not avaliable value.\nPlease return back input valuable value.\n");
					continue;
				}
			}
		}
		else if (service_num == 5) {
			printf("Exit program:)\n");
			exit(1); 
		}
		else {
			printf("not avaliable value.\nplease return back input number\n\n");
			continue;
		}
	}

	return 0;
}