#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

typedef struct ListNode {  //����Ʈ ���Ÿ��
	int coef;  //���
	int expon;  //����
	struct ListNode* link;
}ListNode;

typedef struct ListType {  //����Ʈ ���Ÿ��
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

void error(char* message) {  //���� �޽��� ��� �Լ�
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}
//plist�� ���� ����Ʈ�� ����� ����Ű�� ������, coef�� ���
//expon�� ����

void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));  //���� �޸� �Ҵ����� ��� ����
	if (temp == NULL)   //���� �����Ҵ� �ߴµ� NULL�̸� ���� �޽��� ���
		perror("���� �޸� �Ҵ� ����:(\n");
	temp->coef = coef;  //��� �ʵ忡 ��� �� ����
	temp->expon = expon;  //���� �ʵ忡 ���� �� ����
	temp->link = NULL;  //��ũ �ʵ忡 null�� ����

	if (plist->tail == NULL) {   //���� tail �� ����Ű�� ���� NULL�̴�? -> ListNode�� �ϳ��� ���ٴ� ��
		plist->head = plist->tail = temp;  //����� head�� tail �� ���� ������ ��带 �������ش�.
	}
	else {  
		plist->tail->link = temp;  //tail�� ��ũ�ʵ尡 ����Ű�°��� ���� ������ ��带 ����Ű��� ��
		plist->tail = temp;  //tail�� ���� ������ ��带 ����Ŵ
	}
	plist->size++;  //��带 ���� �ϳ� �߰� �����Ƿ� ��ü ���� ������ +1
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {  //���׽� A,B,C ��� �����ϸ� ��
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;

	while (a && b) {
		if ((a->expon) == (b->expon)) {  //������ �������
			sum = a->coef + b->coef;   //����� ����
			if (sum != 0)  //���� sum�� 0�� �ƴѰ��
				insert_last(plist3, sum, a->expon);  //��� �����ϴ� ���� insert_last�Լ��� ���� (���׽� C�� �����Ѵ� ����)
			a = a->link;  //�� ���� ����Ű�� a(������) �� ���� ������ �̵�
			b = b->link;  //�� ���� ����Ű�� b(������) �� ���� ������ �̵�
		}
		else if (a->expon > b->expon) {  //a�� ������ �� ū ���
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		} 
		else {  //b�� ������ �� ū ���
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}
}

void poly_print(ListType* plist) {
	ListNode* p = plist->head;

	printf("polynomial = ");
	for (; p; p = p->link) {
		printf("%d^%d + ", p->coef, p->expon);
	}
	printf("\n");
}

//int main(void) {
//	return 0;
//}