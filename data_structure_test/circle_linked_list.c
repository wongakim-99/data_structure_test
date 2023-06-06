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

//���� ���Ḯ��Ʈ ó���� �����ϴ� �Լ�
ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));  //���� �޸� �Ҵ����� ��� ����

	node->data = data;
	if (head == NULL) {  //head �����Ͱ� NULL�� ����Ų�� -> �Ƶ尡 �ƿ� ���ٴ� �ǹ�
		head = node;     //���� ��� �����Ͱ� ��带 ����Ŵ
		node->link = head;  //����� ��ũ�ʵ忡 ��� ����
	}
	else {                //��尡 �ִ� ���
		node->link = head->link;   //��尡 ����Ű�� ����� ��ũ�ʵ带 ���� ������ ����� ��ũ�ʵ带 ����Ŵ --> ���� ���� ����Ŵ
		//�ֳ��ϸ� ��尡 �ϳ� �ۿ� ���� ��Ȳ������ �׷�
		head->link = node;
	}
}

//���� ���Ḯ��Ʈ ���� �����ϴ� �Լ�
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
