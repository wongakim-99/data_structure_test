#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define MAX_QUEUE_SIZE 100

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

typedef TreeNode* element;

typedef struct {  //Queue type --> circle queue
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message) {  //print error message
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//Empty situation function
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

//Empty situation function
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqeue(QueueType* q, element item) {  //insert calculation
	if (is_full(q))
		perror("Queue is full");
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}

element dequeue(QueueType* q) {  //delete calculation
	if (is_empty(q))
		perror("Queue is empty");
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}

void level_order(TreeNode* ptr) {
	QueueType q;
	init_queue(&q);

	if (ptr == NULL)
		return;
	enqueue(&q, ptr);

	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf(" [%d] ", ptr->data);
		if (ptr->left)
			enqueue(&q, ptr->left);
		else
			enqueue(&q, ptr->right);
	}
}