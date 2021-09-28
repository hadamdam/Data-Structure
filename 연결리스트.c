#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable : 4996)

struct NODE
{
	struct NODE* next;
	int data;
};

void addFirst(struct NODE* target, int data)
{
	struct NODE* newNode = malloc(sizeof(struct NODE));
	newNode->next = target->next;
	newNode->data = data;
	target->next = newNode;
}

void removeFirst(struct NODE* target)    // 기준 노드의 다음 노드를 삭제하는 함수
{
	struct NODE* removeNode = target->next;    // 기준 노드의 다음 노드 주소를 저장
	target->next = removeNode->next;     // 기준 노드의 다음 노드에 삭제할 노드의 다음 노드를 지정

	free(removeNode);    // 노드 메모리 해제
}

void insertNode(struct NODE* head)
{
	int node_place;
	int node_data;

	puts("<추가>: 추가할 노드의 위치와 data 값을 입력하세요");
	fputs("노드 위치: ", stdout);
	scanf("%d", &node_place);
	fputs("노드 값: ", stdout);
	scanf("%d", &node_data);

	struct NODE* target = head;

	int i;
	for (i = 0; i < (node_place - 1); i++)
	{
		target = target->next;
	}

	addFirst(target, node_data);
	fputs("\n", stdout);
}

void deleteNode(struct NODE* head)
{
	int node_place;

	puts("<삭제>: 삭제할 노드의 위치를 입력하세요");
	fputs("노드 위치: ", stdout);
	scanf("%d", &node_place);
	
	struct NODE* target = head;

	int i;
	for (i = 0; i < (node_place - 1); i++)
	{
		target = target->next;
	}

	removeFirst(target);
	fputs("\n", stdout);
}

void updateNode(struct NODE* head)
{
	int node_place;
	int new_data;

	puts("<변경>: 노드의 위치와 새로운 data 값을 입력하세요");
	fputs("노드 위치: ", stdout);
	scanf("%d", &node_place);
	fputs("새 노드 값: ", stdout);
	scanf("%d", &new_data);

	struct NODE* target = head;

	int i;
	for (i = 0; i < node_place; i++)
	{
		target = target->next;
	}

	target->data = new_data;
	fputs("\n", stdout);
}

void printArr(struct NODE* head)
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
	while (curr != NULL)    
	{
		struct NODE* next = curr->next; 
		free(curr);        
		curr = next;     
	}

	free(head);

	return 0;
}