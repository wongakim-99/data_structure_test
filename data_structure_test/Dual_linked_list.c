#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef int element;
typedef struct DlistNode {  //이중연결 리스트에서의 노드타입
	element data;
	struct DlistNode* llink, * rlink;
}DlistNode;

void init(DlistNode* phead) {  //헤드노드
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DlistNode* phead) {  //출력함수
	DlistNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |->", p->data);
	}
	printf("\n");
}

//이중연결 리스트 에서의 삽입함수
void dinsert(DlistNode* before, element data) {  //인자로 삽입할 노드의 전 노드, 새로운 노드의 데이터를 전달했다  
	DlistNode* newnode = (DlistNode*)malloc(sizeof(DlistNode));  //동적 메모리 할당으로 새로운 노드생성
	newnode->data = data;
	newnode->llink = before;  //이전 노드의 데이터를 새로만든 노드의 왼쪽 링크필드에 저장한다. 즉, 새로운 노드의 왼쪽 링크필드가 이전 노드를 가리킨다
	newnode->rlink = before->rlink;  //이전노드의 오른쪽 링크필드가 가리키는 값을 새로운 노드의 오른쪽 링크필드에 저장.
	//29line -> 즉, 새로운 노드의 오른쪽 링크필드가 후행 노드를 가리키게 된다.
	before->rlink->llink = newnode;  //새로운 노드의 값을 이전 노드의 오른쪽 링크필드가 가리키는 왼쪽 링크필드에 새로운 노드저장
	//31line -> 즉, 후행 노드가 새로운 노드를 가리키게 된다.
	before->rlink = newnode;  //before 노드의 오른쪽 링크필드에 새로운 노드 저장. 즉, before 노드가 새로운 노드를 가리킨다.
}

//이중연결 리스트 에서의 삭제함수
void ddlete(DlistNode* head, DlistNode* removed) {
	if (removed == head)
		return -1;
	else {
		removed->llink->rlink = removed->rlink;  /*제거할 노드의 오른쪽 링크필드가 가리키는 노드를 제거할 노드의 왼쪽 링크필드가 가리키는 노드의 
												 오른쪽 링크필드에 저장해라. 즉 제거할 노드의 선행노드가 제거할 노드의 후행 노드를 가리키게 해라*/
		removed->rlink->llink = removed->llink;  /*제거할 노드의 왼쪽 링크필드가 가리키는 노드를 제거할 노드의 오른쪽 링크필드가 가리키는 노드의
												 왼쪽 링크필드에 저장해라. 즉, 제거할 노드의 후행노드가 제거할 노드의 선행 노드를 가리키게 해라*/
		free(removed);
	}
}