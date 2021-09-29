#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable : 4996)

struct NODE
{
	struct NODE* next;
	int data;
};

void addFirst(struct NODE* target, int data)	//target이 가리키는 노드 바로 뒤에 data를 갖는 새로운 노드를 연결시켜주는 함수
{
	struct NODE* newNode = malloc(sizeof(struct NODE));
	newNode->next = target->next;
	newNode->data = data;
	target->next = newNode;
}

void removeFirst(struct NODE* target)    //target이 가리키는 노드 바로 다음 노드를 제거해주는 함수
{
	struct NODE* removeNode = target->next;    
	target->next = removeNode->next;     

	free(removeNode);    
}

void insertNode(struct NODE* head)	//노드추가함수 
{
	int node_place;		//추가하는 노드의 위치
	int node_data;		//추가하는 노드의 data 값

	puts("<추가>: 추가할 노드의 위치와 data 값을 입력하세요");	//사용자에게 입력 받음
	fputs("노드 위치: ", stdout);
	scanf("%d", &node_place);
	fputs("노드 값: ", stdout);
	scanf("%d", &node_data);

	struct NODE* target = head;

	int i;
	for (i = 0; i < (node_place - 1); i++)	//target을 head로 초기화한뒤 (node_place-1)번 이동시켜 새 노드의 바로 앞의 노드를(새 노드를 가리킬 노드) 가리키도록 한다.
	{
		target = target->next;
	}	//ex) node_place가 3이면 target은 두번째 노드를 가리킨다.

	addFirst(target, node_data);	//사용자에게 입력받은 node_data를 인자로 전달한다.
	fputs("\n", stdout);	//구분을 위해 엔터 출력
}

void deleteNode(struct NODE* head)	//노드 삭제 함수
{
	int node_place;		//사용자가 입력하는 삭제할 노드 위치

	puts("<삭제>: 삭제할 노드의 위치를 입력하세요");
	fputs("노드 위치: ", stdout);
	scanf("%d", &node_place);
	
	struct NODE* target = head;

	int i;
	for (i = 0; i < (node_place - 1); i++)	//target이 삭제할 노드의 바로 앞의 노드를(삭제할 노드를 가리키는 노드) 가리키도록 한다.
	{
		target = target->next;
	}

	removeFirst(target);
	fputs("\n", stdout);
}

void updateNode(struct NODE* head)	//이미 존재하는 노드의 data 값을 변경해주는 함수
{
	int node_place;	//변경하고자 하는 노드의 위치
	int new_data;	//새로운 data 값

	puts("<변경>: 노드의 위치와 새로운 data 값을 입력하세요");
	fputs("노드 위치: ", stdout);
	scanf("%d", &node_place);
	fputs("새 노드 값: ", stdout);
	scanf("%d", &new_data);

	struct NODE* target = head;

	int i;
	for (i = 0; i < node_place; i++)	//target은 변경할 노드를 가리킨다.(node_place)번 이동함. (node_place-1) 아님에 주의!
	{
		target = target->next;
	}

	target->data = new_data;	//data변수에 새 data 값 대입
	fputs("\n", stdout);
}

void printArr(struct NODE* head)	//현재 연결리스트 상태를 출력
{
	struct NODE* curr = head->next;
	int i=1;

	fputs("현재 리스트 출력: ", stdout);
	fputs("[head]", stdout);

	while (curr != NULL)
	{
		printf(" -> [%d: %d]", i++, curr->data);
		curr = curr->next;
	}
	
	puts(" -> NULL");
}

int main(void)
{
	struct NODE* head = malloc(sizeof(struct NODE));

	head->next = NULL;

	addFirst(head, 30);
	addFirst(head, 20);
	addFirst(head, 10);
	//[head] -> [1: 10] -> [2: 20] -> [3: 30] -> NULL로 초기화

	int choose=0;

	while (choose != 4) {
		printArr(head);
		puts("1. 추가 2. 삭제 3. 변경 4. 종료");
		fputs("기능을 선택하세요: ",stdout);
		scanf("%d", &choose);
		fputs("\n", stdout);

		switch (choose)
		{
		case 1:
			insertNode(head);
			break;
		case 2:
			deleteNode(head);
			break;
		case 3:
			updateNode(head);
			break;
		case 4:
			break;
		}
	}
	
	struct NODE *curr = head->next;      
	while (curr != NULL)    //메모리 해제
	{
		struct NODE* next = curr->next; 
		free(curr);        
		curr = next;     
	}

	free(head);

	return 0;
}