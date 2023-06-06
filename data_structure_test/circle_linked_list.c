#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void print_list(ListNode* head) {
	ListNode* p;
	if (head == NULL)
		return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
}

//원형 연결리스트 처음에 삽입하는 함수
ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));  //동적 메모리 할당으로 노드 생성

	node->data = data;
	if (head == NULL) {  //head 포인터가 NULL을 가리킨다 -> 盧드가 아예 없다는 의미
		head = node;     //이제 헤드 포인터가 노드를 가리킴
		node->link = head;  //노드의 링크필드에 헤드 저장
	}
	else {                //노드가 있는 경우
		node->link = head->link;   //헤드가 가리키는 노드의 링크필드를 새로 생성한 노드의 링크필드를 가리킴 --> 지가 지를 가리킴
		//왜냐하면 노드가 하나 밖에 없는 상황에서는 그럼
		head->link = node;
	}
}

//원형 연결리스트 끝에 삽입하는 함수
ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}
