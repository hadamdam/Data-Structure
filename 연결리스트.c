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

void removeFirst(struct NODE* target)    // ���� ����� ���� ��带 �����ϴ� �Լ�
{
	struct NODE* removeNode = target->next;    // ���� ����� ���� ��� �ּҸ� ����
	target->next = removeNode->next;     // ���� ����� ���� ��忡 ������ ����� ���� ��带 ����

	free(removeNode);    // ��� �޸� ����
}

void insertNode(struct NODE* head)
{
	int node_place;
	int node_data;

	puts("<�߰�>: �߰��� ����� ��ġ�� data ���� �Է��ϼ���");
	fputs("��� ��ġ: ", stdout);
	scanf("%d", &node_place);
	fputs("��� ��: ", stdout);
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

	puts("<����>: ������ ����� ��ġ�� �Է��ϼ���");
	fputs("��� ��ġ: ", stdout);
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

	puts("<����>: ����� ��ġ�� ���ο� data ���� �Է��ϼ���");
	fputs("��� ��ġ: ", stdout);
	scanf("%d", &node_place);
	fputs("�� ��� ��: ", stdout);
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

	fputs("���� ����Ʈ ���: ", stdout);
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
		puts("1. �߰� 2. ���� 3. ���� 4. ����");
		fputs("����� �����ϼ���: ",stdout);
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