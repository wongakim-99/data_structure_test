#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct ListNode {  //리스트 노드타입
	int coef;
	int expon;
	struct ListNode* link;
}ListNode;

//연결리스트 헤더
typedef struct ListType {  //리스트 헤더타입
	int length;
	ListNode* head;
	ListNode* tail;
}ListType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create() {  //리스트 헤더 생성함수
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->length = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

//plist 는 연결 리스트의 헤더를 가리키는 포인터, coef는 계수
//expon는 지수
void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	//if (temp == NULL)
		//error("메모리 할당 에러");

	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp; 
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->length++;
}

//다항식의 덧셈과정
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;

	int sum;

	while (a && b) {
		if (a->expon == b->expon) {  //a의 다항식과 b의 다항식의 지수가 같은경우
			sum = a->coef + b->coef;
			if (sum != 0)insert_last(plist3, sum, a->expon);
			a = a->link;
			b = b->link;
		}
		else if (a->expon > b->expon) {
			inset_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}
	/*덧셈 후 각 방정식에 남은게 있다면 전부 C 방정식으로 옮기는 과정*/
	for (; a != NULL; a = a->link) {
		insert_last(plist3, a->coef, a->expon);
	}
	for (; b != NULL; b = b->link) {
		insert_last(plist3, b->coef, b->expon);
	}
}
void poly_print(ListType* plist) {
	ListNode* p = plist->head;

	printf("polynomial = ");
	for (; p; p = p->link) {
		printf("%d^%d+", p->coef, p->expon);
	}
	printf("\n");
}

int main(void) {
	ListType* list1, * list2, * list3;

	list1 = create();
	list2 = create();
	list3 = create();

	//다항식 1 생성
	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);

	//다항식 2 생성
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);

	poly_print(list1);
	poly_print(list2);

	poly_add(list1, list2, list3);
	poly_print(list3);

	free(list1);
	free(list2);
	free(list3);
}