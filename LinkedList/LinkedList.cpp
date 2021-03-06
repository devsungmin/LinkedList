/* 프로그램 정보
개발자 : 김성민
프로그램 설명 : 데이터를 삽입하여 연결리스트를 만들어 삽입/검색/출력/삭제 하는 프로그램
*/
#include "stdafx.h"
#include "stdlib.h"
#include "string.h"

void first();//프로그램 설명
void headline();//작업 선택
void insert(); //연결리스트의 제일 뒤에 삽입
void exploration();//검색
void onedelet();//노드 하나 삭제
void print();//출력
void end();//종료

/*연결리스트 생성*/
typedef struct Node
{
	int data;
	struct Node *next;
}node;
node *head;

/*메인 함수*/
int main()
{
	int cho = 0;
	while (cho != 6)
	{
		first();
		headline();
		node *head = NULL;//노드가 가르키는 head값은 NULL로 초기화
		printf("\t어떤 작업을 할까요? : ");
		scanf_s("%d", &cho);
		switch (cho)
		{
		case 1:// 연결리스트의 제일 뒤에 삽입
			insert();
			system("cls");
			break;
		case 2://검색
			exploration();
			break;
		case 3://노드 하나 삭제
			onedelet();
			break;
		case 4://출력
			print();
			break;
		case 5://종료
			end();
			break;
		}
	}
	return 0;
}

/*프로그램 설명*/
void first()
{
	printf("\t====================================\n");
	printf("\t\tLinked-List Program \n");
	printf("\t====================================\n\n");
}

/*메뉴 선택*/
void headline()
{
	printf("\t====================================\n");
	printf(" \t1. 연결 리스트 제일 뒤에 삽입\n");
	printf(" \t2. 검색\n");
	printf(" \t3. 노드 하나 삭제\n");
	printf(" \t4. 출력\n");
	printf(" \t5. 종료\n");
	printf("\t====================================\n");
}

/*연결리스트의 제일 뒤에 삽입*/
void insert()
{
	int num = 0;
	node *tmp, *ptr;
	tmp = (node *)malloc(sizeof(node));
	ptr = (node*)malloc(sizeof(node));
	printf("\n\t삽입할 숫자를 입력하시오 : ");
	scanf_s("%d", &num);
	printf("\n");
	if (head == NULL)
	{
		ptr->data = num;
		ptr->next = NULL;
		head = ptr;
		return;
	}
	else
	{
		ptr->data = num;
		ptr->next = NULL;
		tmp = head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = ptr;

	}
}

/*검색*/
void exploration()
{
	int num = 0;
	node *ptr, *tmp;
	tmp = (node*)malloc(sizeof(node));
	ptr = (node*)malloc(sizeof(node));
	int cnt = 0;
	printf("\t찾을 node를 입력하세요 : ");
	scanf_s("%d", &num);
	printf("\n\n");
	ptr = head;
	while (ptr->next != NULL)
	{
		cnt++;//while문 돌때마다 한번씩 증가
		if (ptr->data == num) //찾는 num값이 node에 있을 경우
		{
			system("cls");
			printf("\n\t찾는 node는 %d번째에 있습니다.\n\n", cnt);
			return;
		}
		else
		ptr = ptr->next;
	}
	if (ptr->data != num)//찾는 num값이 node에 존재 하지 않을때
	{
		system("cls");
		printf("\t입력한 node 값이 존재하지 않습니다.\n\n");
	}
	else if (ptr->next == NULL)
	{
		cnt++;
		system("cls");
		printf("\n\t찾는 node는 %d번째에 있습니다.\n\n", cnt);
	}
}

/*노드 하나 삭제*/
void onedelet()
{
	int num = 0,cnt=0;
	node *tmp = head, *del = NULL;
	if (head == NULL)
	{
		system("cls");
		printf("\t데이터가 없습니다.\n\n");
	}
	else
	{
		printf("\n\t삭제할 node를 입력하세요 : ");
		scanf_s("%d", &num);
		printf("\n\n");
		if (head->next==NULL&&num==head->data)//리스트에 값이 하나 이고 처음 값이 삭제할 값
		{
			system("cls");
			printf("\t입력한 %d값을 삭제 하였습니다.\n\n",head->data);
			free(head);
			head = NULL;
		}
		else if (head->data == num)//리스트에 값이 여러개 이고 처음 데이터가 삭제할 값
		{
			system("cls");
			printf("\t입력한 %d값을 삭제 하였습니다.\n\n", head->data);
			head = head->next;
		}
		else
		{
			while (tmp != NULL)
			{
				if (num==tmp->data)
				{
					cnt++;
					del->next = tmp->next;
				}
				del = tmp;
				tmp = NULL;
				free(tmp);
				tmp = del->next;
			}
			if (cnt == 0)
				printf("\t입력한 %d값은 node에 존재하지 않는 값입니다.\n\n");
			else
			{
				system("cls");
				printf("\t입력한 %d값을 삭제 하였습니다.\n\n", num);
			}
		}

	}
}


/*출력*/
void print()
{
	node *ptr;
	if (head == NULL)
	{
		system("cls");
		printf("\n\t데이터 없음\n\n");
		return;
	}
	ptr = head;
	system("cls");
	printf("\n\t");
	while (ptr != NULL)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n\n");
	return;
}

/*종료*/
void end()
{
	system("cls");
	printf("\t종료를 선택하셨습니다.\n\n");
	exit(0);
}