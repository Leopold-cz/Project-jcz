#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#define random(x) (rand()%x)

using namespace std;
#define OK 1
#define ERROR 0
typedef int Status;

typedef struct Student
{
	char name[30];
	char id[15];
	char grade[10];
	char major[30];
	char Class[30];
	int mark = 0;

}Student;

typedef struct LNode
{
	Student data;
	struct LNode *next;
}LNode, *LinkList;

Status InitList(LinkList &L)
{
	L = new LNode;
	L->next = NULL;
	return OK;
}

Status CreateList(LinkList &L)
{
	fstream file;
	file.open("User.txt");
	if (!file) {
		cout << "错误！未找到文件！\n\n" << endl;
		exit(ERROR);
	}
	LNode *p, *r;
	r = new LNode;
	r = L;
	while (file.peek() != EOF) {
		p = new LNode;
		file >> p->data.id >> p->data.name >> p->data.major
			>> p->data.grade >> p->data.Class;
		r->next = p;
		p->next = NULL;
		r = p;
	}
	return OK;
}


void display(LinkList L, int x) {

	LNode *p;
	p = L->next;
	for (int i = 1; i < x; i++)
	{
		p = p->next;
	}

	cout << endl << endl << "              按p键暂停" << endl << "        Press ‘p’ key to Suspend";
	cout << endl << endl;
	cout << "           luck Student is :" << p->data.id << "   " << p->data.name << endl << endl << endl;
}

int main() {

	LinkList L;
	InitList(L);
	CreateList(L);

	srand((int)time(0));//生成随机数种子
	int Num = 0;
	cout << endl << endl << "              按键开始" << endl << "        Press any key to Start";
	_getch();
	system("cls");

	LNode p;
	while (1) {
		Num = random(19);
		display(L, Num);
		Sleep(30);//进程暂停30ms
		if (GetAsyncKeyState('P')) {
			system("pause");
		}
		system("cls");
	}
	return 0;
}

