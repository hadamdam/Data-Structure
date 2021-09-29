#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable : 4996)

struct NODE
{
	struct NODE* next;
	int data;
};

void addFirst(struct NODE* target, int data)	//target�� ����Ű�� ��� �ٷ� �ڿ� data�� ���� ���ο� ��带 ��������ִ� �Լ�
{
	struct NODE* newNode = malloc(sizeof(struct NODE));
	newNode->next = target->next;
	newNode->data = data;
	target->next = newNode;
}

void removeFirst(struct NODE* target)    //target�� ����Ű�� ��� �ٷ� ���� ��带 �������ִ� �Լ�
{
	struct NODE* removeNode = target->next;    
	target->next = removeNode->next;     

	free(removeNode);    
}

void insertNode(struct NODE* head)	//����߰��Լ� 
{
	int node_place;		//�߰��ϴ� ����� ��ġ
	int node_data;		//�߰��ϴ� ����� data ��

	puts("<�߰�>: �߰��� ����� ��ġ�� data ���� �Է��ϼ���");	//����ڿ��� �Է� ����
	fputs("��� ��ġ: ", stdout);
	scanf("%d", &node_place);
	fputs("��� ��: ", stdout);
	scanf("%d", &node_data);

	struct NODE* target = head;

	int i;
	for (i = 0; i < (node_place - 1); i++)	//target�� head�� �ʱ�ȭ�ѵ� (node_place-1)�� �̵����� �� ����� �ٷ� ���� ��带(�� ��带 ����ų ���) ����Ű���� �Ѵ�.
	{
		target = target->next;
	}	//ex) node_place�� 3�̸� target�� �ι�° ��带 ����Ų��.

	addFirst(target, node_data);	//����ڿ��� �Է¹��� node_data�� ���ڷ� �����Ѵ�.
	fputs("\n", stdout);	//������ ���� ���� ���
}

void deleteNode(struct NODE* head)	//��� ���� �Լ�
{
	int node_place;		//����ڰ� �Է��ϴ� ������ ��� ��ġ

	puts("<����>: ������ ����� ��ġ�� �Է��ϼ���");
	fputs("��� ��ġ: ", stdout);
	scanf("%d", &node_place);
	
	struct NODE* target = head;

	int i;
	for (i = 0; i < (node_place - 1); i++)	//target�� ������ ����� �ٷ� ���� ��带(������ ��带 ����Ű�� ���) ����Ű���� �Ѵ�.
	{
		target = target->next;
	}

	removeFirst(target);
	fputs("\n", stdout);
}

void updateNode(struct NODE* head)	//�̹� �����ϴ� ����� data ���� �������ִ� �Լ�
{
	int node_place;	//�����ϰ��� �ϴ� ����� ��ġ
	int new_data;	//���ο� data ��

	puts("<����>: ����� ��ġ�� ���ο� data ���� �Է��ϼ���");
	fputs("��� ��ġ: ", stdout);
	scanf("%d", &node_place);
	fputs("�� ��� ��: ", stdout);
	scanf("%d", &new_data);

	struct NODE* target = head;

	int i;
	for (i = 0; i < node_place; i++)	//target�� ������ ��带 ����Ų��.(node_place)�� �̵���. (node_place-1) �ƴԿ� ����!
	{
		target = target->next;
	}

	target->data = new_data;	//data������ �� data �� ����
	fputs("\n", stdout);
}

void printArr(struct NODE* head)	//���� ���Ḯ��Ʈ ���¸� ���
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
	//[head] -> [1: 10] -> [2: 20] -> [3: 30] -> NULL�� �ʱ�ȭ

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
	while (curr != NULL)    //�޸� ����
	{
		struct NODE* next = curr->next; 
		free(curr);        
		curr = next;     
	}

	free(head);

	return 0;
}