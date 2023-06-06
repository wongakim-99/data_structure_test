#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

typedef struct ListNode {  //리스트 노드타입
	int coef;  //계수
	int expon;  //지수
	struct ListNode* link;
}ListNode;

typedef struct ListType {  //리스트 헤드타입
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

void error(char* message) {  //오류 메시지 출력 함수
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}
//plist는 연결 리스트의 헤더를 가리키는 포인터, coef는 계수
//expon은 지수

void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));  //동적 메모리 할당으로 노드 생성
	if (temp == NULL)   //만약 동적할당 했는데 NULL이면 오류 메시지 출력
		perror("동적 메모리 할당 에러:(\n");
	temp->coef = coef;  //계수 필드에 계수 값 저장
	temp->expon = expon;  //지수 필드에 지수 값 저장
	temp->link = NULL;  //링크 필드에 null값 저장

	if (plist->tail == NULL) {   //만약 tail 이 가리키는 것이 NULL이다? -> ListNode가 하나도 없다는 뜻
		plist->head = plist->tail = temp;  //노드의 head랑 tail 이 새로 생성한 노드를 가리켜준다.
	}
	else {  
		plist->tail->link = temp;  //tail의 링크필드가 가리키는것을 새로 생성한 노드를 가리키라는 뜻
		plist->tail = temp;  //tail이 새로 생성한 노드를 가리킴
	}
	plist->size++;  //노드를 새로 하나 추가 했으므로 전체 항의 사이즈 +1
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {  //다항식 A,B,C 라고 생각하면 됨
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;

	while (a && b) {
		if ((a->expon) == (b->expon)) {  //지수가 같은경우
			sum = a->coef + b->coef;   //계수를 더함
			if (sum != 0)  //만약 sum이 0이 아닌경우
				insert_last(plist3, sum, a->expon);  //노드 생성하는 위의 insert_last함수로 보냄 (다항식 C에 저장한다 생각)
			a = a->link;  //각 항을 가리키는 a(포인터) 를 다음 항으로 이동
			b = b->link;  //각 항을 가리키는 b(포인터) 를 다음 항으로 이동
		}
		else if (a->expon > b->expon) {  //a의 지수가 더 큰 경우
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		} 
		else {  //b의 지수가 더 큰 경우
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