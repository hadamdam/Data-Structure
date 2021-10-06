#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable : 4996)

int dat[100];
int pos = 0;

void push(int x)
{
	dat[pos] = x;
	pos++;
}

void pop() {
	pos--;
}

int top()
{
	return dat[pos - 1];
}

void search()
{
	int i;
	printf("%d", dat[0]);
	for (i = 1; i < pos; i++)
	{
		printf("-%d", dat[i]);
	}
	printf("\n\n");
}

int main()
{
	int choose = 0;

	int x;

	while (choose != 4) {
		search();
		puts("1. 추가 2. 삭제 3. 확인 4. 종료");
		fputs("기능을 선택하세요: ", stdout);
		scanf("%d", &choose);
		fputs("\n", stdout);

		switch (choose)
		{
		case 1:
			printf("추가할 값을 입력하세요: ");
			scanf("%d", &x);
			push(x);
			break;
		case 2:
			pop();
			break;
		case 3:
			printf("%d\n", top());
			break;
		case 4:
			break;
		}
	}

		return 0;
}