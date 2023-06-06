#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef int element;
typedef struct DlistNode {  //���߿��� ����Ʈ������ ���Ÿ��
	element data;
	struct DlistNode* llink, * rlink;
}DlistNode;

void init(DlistNode* phead) {  //�����
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DlistNode* phead) {  //����Լ�
	DlistNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |->", p->data);
	}
	printf("\n");
}

//���߿��� ����Ʈ ������ �����Լ�
void dinsert(DlistNode* before, element data) {  //���ڷ� ������ ����� �� ���, ���ο� ����� �����͸� �����ߴ�  
	DlistNode* newnode = (DlistNode*)malloc(sizeof(DlistNode));  //���� �޸� �Ҵ����� ���ο� ������
	newnode->data = data;
	newnode->llink = before;  //���� ����� �����͸� ���θ��� ����� ���� ��ũ�ʵ忡 �����Ѵ�. ��, ���ο� ����� ���� ��ũ�ʵ尡 ���� ��带 ����Ų��
	newnode->rlink = before->rlink;  //��������� ������ ��ũ�ʵ尡 ����Ű�� ���� ���ο� ����� ������ ��ũ�ʵ忡 ����.
	//29line -> ��, ���ο� ����� ������ ��ũ�ʵ尡 ���� ��带 ����Ű�� �ȴ�.
	before->rlink->llink = newnode;  //���ο� ����� ���� ���� ����� ������ ��ũ�ʵ尡 ����Ű�� ���� ��ũ�ʵ忡 ���ο� �������
	//31line -> ��, ���� ��尡 ���ο� ��带 ����Ű�� �ȴ�.
	before->rlink = newnode;  //before ����� ������ ��ũ�ʵ忡 ���ο� ��� ����. ��, before ��尡 ���ο� ��带 ����Ų��.
}

//���߿��� ����Ʈ ������ �����Լ�
void ddlete(DlistNode* head, DlistNode* removed) {
	if (removed == head)
		return -1;
	else {
		removed->llink->rlink = removed->rlink;  /*������ ����� ������ ��ũ�ʵ尡 ����Ű�� ��带 ������ ����� ���� ��ũ�ʵ尡 ����Ű�� ����� 
												 ������ ��ũ�ʵ忡 �����ض�. �� ������ ����� �����尡 ������ ����� ���� ��带 ����Ű�� �ض�*/
		removed->rlink->llink = removed->llink;  /*������ ����� ���� ��ũ�ʵ尡 ����Ű�� ��带 ������ ����� ������ ��ũ�ʵ尡 ����Ű�� �����
												 ���� ��ũ�ʵ忡 �����ض�. ��, ������ ����� �����尡 ������ ����� ���� ��带 ����Ű�� �ض�*/
		free(removed);
	}
}