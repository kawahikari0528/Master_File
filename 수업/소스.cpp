#pragma warning(disable: 4996)
#pragma warning(disable:6011)
#pragma warning(disable:6031)
#include<windows.h>
//#include<math.h>
//#include <time.h> // time()함수 포함 라이브러리
//#include <string.h>
#include<stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10
int rear = 0, front = 0;
int Q[QUEUE_SIZE];


bool IsEmpty() {
	if (front == rear) return true;
	else return false;
}

bool IsFull() {
	if ((rear + 1) % QUEUE_SIZE == front) {
		printf("꽉 참\n");
		return true;
	}
	else return false;
}

void enQueue(int value) {
	if (IsFull()) return;
	else {
		rear = (rear + 1) % QUEUE_SIZE;
		Q[rear] = value;
		return;
	}
}

void deQueue() {
	if (IsEmpty()) return;
	else {
		front = (front + 1) % QUEUE_SIZE;
		printf("%d 삭제됨", Q[front]);
		Q[front] = NULL;

		return;
	}
}

void printQ() {
	if (IsEmpty()) {
		printf("비었음\n");
		return;
	}
	else {
		for (int i = front + 1; i <= rear; i = (i+1)%QUEUE_SIZE) {
			printf("%d ", Q[i]);
		}

	}
	printf("\n");
}


int main() {
	int n, value;

	printf("1. 인큐 2. 디큐 3. 프린트 else. 종료 \n입력 : ");

	while (scanf("%d", &n)) {
		switch (n)
		{
		case 1:
			printf("삽입할 값 : ");
			scanf("%d", &value);
			enQueue(value);
			break;
		case 2:
			deQueue();
			break;
		case 3:
			printQ();
			break;
		default:
			return 0;
		}
		printf("\n\n1. 인큐 2. 디큐 3. 프린트 else. 종료 \n입력 : ");
	}
}
/*
#define STACK_SIZE 10
int top = -1;
int stack[STACK_SIZE];


int IsEmpty() {
	if (top == -1)
		return true;
	else return false;
}

int IsFull() {
	if (top == STACK_SIZE - 1) return true;
	else return false;
}

void Push(int value) {
	if (IsFull()) {
		printf("꽉 참\n");
		return;
	}
	else {
		stack[++top] = value;
		printf("%d pushed\n", value);
	}
}
void pop(int value) {
	if (IsEmpty()) {
		printf("비었음\n");
		return;
	}
	else{
		stack[top--] = NULL;
		printf("pop %d\n", value);
	}
}

void print() {
	if (IsEmpty()) {
		printf("비었음\n");
		return;
	}
	else {
		printf("\n\n");
		for (int n = top; n >= 0; n--) {
			printf("%d :| %d |\n", n, stack[n]);
		}
		printf("   ㅡㅡ\n");
	}

}


int main() {
	int n,value;
	printf("1: push 2: pop 3. print  /else Exit\n");
	while (scanf("%d", &n)) {
		switch (n) {
		case 1:
			printf("push value : ");
			scanf("%d", &value);
			Push(value);
			break;
		case 2:
			printf("pop value : ");
			scanf("%d", &value);
			pop(value);
			break;
		case 3:
			print();
		}

	}
}*/


/*typedef struct ListNode {
	int data;
	struct ListNode* link;
}listnode;

typedef struct {
	listnode* head;
}headnode;




headnode* createlisthead() {
	headnode* L;
	L = (headnode*)malloc(sizeof(headnode));
	L->head = NULL;
	return L;
}//head만들기

listnode* Findlastnode(headnode* first) {
	listnode* last = first->head;
	while (last->link != first->head) {
		last = last->link;
	}
	return last;
}

void create(headnode* first, int value) {
	listnode* list = (listnode*)malloc(sizeof(listnode));

	listnode* temp = first->head;

	list->data = value;


	if (first->head == NULL) {
		list->link = list;
		first->head = list;
		return;
	}
	else if (temp->data > value) {
		listnode* last = Findlastnode(first);
		list->link = last->link;
		last->link = list;
		first->head = list;
	}
	else
	{
		while (temp->data < value)
		{
			if (temp->link == first->head || temp->link->data > value)
				break;
			temp = temp->link;

		}

		list->link = temp->link;
		temp->link = list;
		return;
	}


}
//처음에 만들기





void NodeDelete(headnode* first, int value) {
	if (first->head == NULL) {
		printf("빈 리스트입니다\n");
		return;
	}
	listnode* del = first->head;
	listnode* temp = first->head;
	listnode* last = Findlastnode(first);

	while (del->data != value) {
		if (del->link == first->head) {
			printf("삭제할 노드가 없습니다.\n");
			return;
		}
		temp = del;
		del = del->link;


	}


	if (del == first->head) {
		last->link = del->link;
		first->head = del->link;
	}
	else temp->link = del->link;
	printf("del : %d\n", del->data);
	if (del->link == del) {
		first->head = NULL;
	}

	free(del);
	return;
}

void PrintList(headnode* List, int value) {
	if (List->head == NULL) {
		printf("빈 리스트입니다\n");
		return;
	}
	else {
		printf("Head -> ");
	}
	listnode* printer = List->head;
	for (int i = 0; i < value; i++) {

		while (printer->link != List->head) {
			printf("%d -> ", printer->data);
			printer = printer->link;
		}
		printf("%d -> ", printer->data);
		printer = printer->link;
	}


	printf(". . . \n출력 끗\n");
}




int main() {
	headnode* head = createlisthead();
	int n, value;
	printf("1.삽입 2.삭제 3.출력 (0이나 숫자가 아닌 것을 입력할시 종료)\n");
	while (scanf("%d", &n)) {

		switch (n) {
		case 0:
			free(head);
			return 0;
			break;
		case 1:
			printf("삽입할 숫자 입력 : ");
			scanf("%d", &value);
			create(head, value);
			break;
		case 2:
			printf("삭제할 숫자 입력 : ");
			scanf("%d", &value);
			NodeDelete(head, value);
			system("pause");
			break;
		case 3:
			printf("리스트를 반복출력할 횟수 입력 : ");
			scanf("%d", &value);
			PrintList(head,value);
			system("pause");
			break;
		}

		system("cls");
		printf("1.삽입 2.삭제 3.출력 (숫자가 아닌 것을 입력할시 종료)\n");
	}

	free(head);
}*///원형 리스트


/*typedef struct ListNode {
	int data;
	struct ListNode* link;
}listnode;

typedef struct {
	listnode* head;
}headnode;


headnode* createlisthead() {
	headnode* L;
	L = (headnode*)malloc(sizeof(headnode));
	L->head = NULL;
	return L;
}//head만들기

void create(headnode* first, int value) {
	listnode* list = (listnode*)malloc(sizeof(listnode));

	listnode* temp = first->head;

	list->data = value;


	if (first->head == NULL) {
		list->link = first->head;
		first->head = list;
		return;
	}
	else if (temp->data>value) {
		list->link = first->head;
		first->head = list;
	}
	else 
	{
		while (temp->data < value)
		{
			if (temp->link == NULL || temp->link->data > value)
				break;
			temp = temp->link;

		} 
		list->link = temp->link;
		temp->link = list;
		return;
	}


}
//처음에 만들기





void NodeDelete(headnode* first, int value) {
	if (first->head == NULL) {
		printf("빈 리스트입니다\n");
		return;
	}
	listnode* del = first->head;
	listnode* temp = first->head;


	while (del->data != value) {
		if (del->link == NULL) {
			printf("삭제할 노드가 없습니다.\n");
			return;
		}
		temp = del;
		del = del->link;

		printf("del : %d\n",del->data);
	}
	printf("탈출\n");
	if (del == first->head) {
		first->head = del->link;
	}
	else temp->link = del->link;

	free(del);
	return;
}

void PrintList(headnode* List) {
	if (List->head == NULL) {
		printf("빈 리스트입니다\n");
		return;
	}
	else {
		printf("Head -> ");
	}
	listnode* printer = List->head;

	while (printer->link != NULL) {
		printf("%d -> ", printer->data);
		printer = printer->link;
	} 
	printf("%d -> ", printer->data);
	printf("NULL\n");
}


void DeleteAll(headnode* first,listnode* save) {
	if (first->head == NULL) {
		printf("빈 리스트\n");
		return;
	}
	if (save->link == NULL) {
		printf("삭제 %d\n", save->data);
		free(save);
		return;
	}
	listnode* next = save->link;
	printf("삭제 %d\n", save->data);
	free(save);
	DeleteAll(first,next);
}

int main() {
	headnode* head = createlisthead();
	int n,value;
	printf("1.삽입 2.삭제 3.출력 4.전부 삭제 (숫자가 아닌 것을 입력할시 종료)\n");
	while (scanf("%d", &n)) {

		switch (n) {
		case 1:
			printf("삽입할 숫자 입력 : ");
			scanf("%d", &value);
			create(head,value);
			break;
		case 2:
			printf("삭제할 숫자 입력 : ");
			scanf("%d", &value);
			NodeDelete(head,value);
			break;
		case 3:
			PrintList(head);
			break;
		case 4:
			DeleteAll(head,head->head);
			head->head = NULL;
			break;
		default:
			break;
			break;
		}
	}
	DeleteAll(head,head->head);
	free(head);
}*///단일 리스트

/*void Delete(int a[], int n) {
	int tmp;
	for (int i = 0; i < 10; i++) {
		if (a[i] == n) a[i] = NULL;
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (a[j] == NULL) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;;
			}
			if (a[j] > a[j + 1]) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;;
			}
		}
	}
}
void Add(int a[],int n) {
	int tmp;
	for (int i = 0; i < 10; i++) {
		if (a[i] == NULL) {
			a[i] = n;
			break;
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (a[j] == NULL) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;;
			}
			if (a[j] > a[j + 1]) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;;
			}
		}
	}
}
int main() {
	int a[10] = { 1,2,5,6,8,10,NULL,NULL,NULL,NULL}, n, c;
	for (int i = 0; i < 10; i++) {
		printf("%d  ", a[i]);
	}
	printf("\n");
	printf("숫자 여부 (양수는 삽입 음수는 삭제 0이면 종료)\n");
	do {
		scanf("%d %d", &n, &c);
		if (c < 0) {
			Delete(a, n);
		}
		else if (c > 0) {
			Add(a, n);
		}
		for (int i = 0; i < 10; i++) {
			printf("%d  ", a[i]);
		}
		printf("\n");

	} while (c != 0);

 }*/
/*int iii(int n) {
	if (n % 10 == 0) {

		return 10;
	}
	else 
	return 1;
}
int main() {
	int a, b, i3, i4, i5, i6;
	scanf("%d %d", &a, &b);
	i3 = a * (b % 10);
	i4 = a * (b - ((b / 100) * 100 + (b % 10)));

	i5 = a * ((b / 100) * 100);
	i6 = a * b;

	i4 = i4 / iii(i4);
	i5 = i5 / iii(i5);
	i5 = i5 / iii(i5);
	printf("%d \n%d \n%d \n%d", i3, i4, i5, i6);
}*/
/*char c[1000000] = { 0, };
int result[400000] = { 0 }, count = 0, count2 = 0, length = 0, num = 1;
int main() {


	int check = 0;
	scanf("%s", c);
	int i = 0;
	for (; c[i + 1] != 0; i++) {
		length++;
	}

	for (; i >= 0; i--) {


		if (c[i] == 49) {
			result[count2] += num;

		}
		num *= 2;


		count++;
		if (count == 3) {
			count = 0;
			num = 1;
			count2++;
		}
	}

	for (int i = 399999; i >= 0; i--) {
		if (check || result[i] != 0) {
			check = 1;
			printf("%d", result[i]);
		}
		


	}if (check == 0) printf("0");
}*/




/*int main() {
	int  count2=0;
	int score[100] = { 0 };
	int n;
	char c[100][80] = {0};
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", c[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 100 && c[i][j] != 0; j++) {
			
			if (c[i][j] == 79) {
				count2++;
				score[i] += count2;
			}
				
			else count2 = 0;

			
		}
		count2 = 0;
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", score[i]);
	}
}*/




/*void exchange(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void upper(int n[]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (n[j] > n[j + 1])exchange(&n[j], &n[j + 1]);
		}
	}
	for (int i = 0; i < 5; i++) {
		printf("%d ", n[i]);
	}
}
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	exchange(&a, &b);
	printf("%d %d\n", a, b);

	int n[5] = { 1,3,9,4,2 };
	upper(n);
}*/

/*typedef struct money {
	int number;
	int won;
}money;
money Max(money arr[], int n) {
	money maxdata = arr[0];
	for (int i = 0; i < n; i++)
		maxdata = (maxdata.won > arr[i].won) ? maxdata : arr[i];
	return maxdata;
}
int main() {
	money F[5];

	for (int i = 0; i < 5; i++) {
		printf("%d번 저축금액은? ", i + 1);
		scanf("%d", &F[i].won);
		F[i].number = i + 1;
	}
	money max = Max(F, 5);
	printf("저축왕 %d번 %d원", max.number, max.won);
}*/




/*typedef struct human {
	char name[20];
	int age;
}human;
int main() {
	human I = { "양성훈",17 };
	human F;
	printf("친한 친구의 이름과 나이를 입력하세요");
	scanf("%s %d", F.name, &F.age);
	printf("당신의 이름 : %s, 나이 : %d \n친구의 이름 : %s, 나이 : %d", I.name, I.age, F.name, F.age);
}*/



/*int main() {
	char c[100] = { 0, };
	scanf("%[^\n]s", c);
	for (int i = 0; c[i] != 0; i++) {
		if (c[i] == 32) printf("\n");
		else printf("%c", c[i]);
	}
}*/


/*int main() {
	int end=0,  fin=0;
	char c[100] = {0};
	scanf("%s", c);
	for (int i = 0; i < 100; i++) {
		if (c[i] != 0) {
			end = i;
			fin = end;
		}
	}
	for (int i = 0; i <= fin/2; i++) {
		char temp = c[i];
		c[i] = c[end];
		c[end] = temp;
		end--;
	}
	printf("입력받은 문자열의 길이는 %d입니다. \n%s", fin+1, c);

}*/


/*int main() {
	char n[10] = { 0, }, sum = 0;
	scanf("%s", n);
	for (int i = 0; i < 9; i++) {
		sum += n[i] - 48;
	}
	printf("%d", sum);
	return 0;
}*/

/*int pibo(int n) {
	if (n < 3)return 1;
	else return pibo(n - 1) + pibo(n - 2);
}
int main() {
	int n,result;
	scanf("%d", &n);
	result = pibo(n);
	printf("%d", result);
}*/

/*int count = 1;
void jaegwi(int n) {
	
	printf("%d ", count++);
	if (n <= 1) return;
	else
	jaegwi(n-1);
}
int main() {
	int n;
	scanf("%d", &n);
	jaegwi(n);
}*/



/*int main() {

	int a[3] = { 0, } ,check=1;

	printf("세 과목의 점수를 입력하세요.");
	for (int i = 0; i < 3; i++) {
		scanf("%d", &a[i]);
		if (a[i] < 40) check = 0;
	}
	float result = (a[0] + a[1] + a[2]) / 3;

	if (!check || result < 60) {
		printf("불합격");
	}
	else printf("합격");
}*/


/*float total(int a[]) {
	float result = a[0] + a[1] + a[2];
	return result / 3;
}
int main() {
	int a[3] = { 0, };
	float result;
	printf("세 과목의 점수를 입력하세요.");
	for (int i = 0; i < 3; i++) {
		scanf("%d", &a[i]);

	}
	result = total(a);
	printf("평균 %.2f", result);

}*/


/*int main() {
	int a[10] = { 0, }, n;
	do {

		scanf("%d", &n);
		if(n!=0)
		a[n % 10]++;

	} while (n != 0);
	for (int i = 0; i < 10; i++) {
		if (a[i] != 0) {
			printf("%d : %d개\n", i, a[i]);
		}
	}
}*///2번답


/*int main() {
	int a[10] = { 0, };
	int n;
	do {

		scanf("%d", &n);
		if(n > 0 && n <= 10)a[n - 1]++;
		
	} while (n > 0 && n <= 10);
	for (int i = 0; i < 10; i++) {
		if (a[i] != 0) {
			printf("%d : %d개\n", i + 1, a[i]);
		}
	}
}*///1번 답


/*int main()
{
	int i, arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	int* ptr = arr;
	int len = sizeof(arr) / sizeof(int);



	printf("%d %d %d\n\n", len, sizeof(arr), sizeof(int));
	for (i = 0; i < len; i++) {
		printf("ptr+i : %p, *(ptr+i) : %d, arr : %p\n", ptr + i, *(ptr + i), arr);
		*(ptr + i) *= 2;
	}

	for (i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}*/

/*int main() {
	int arr[4] = { 4,3,2,1 };
	int* pArr;
	pArr = (int*)malloc(sizeof(int) * 4);

	if (pArr == NULL) {
		printf("malloc error");
	}
	for (int i = 0; i < 4; i++) {
		pArr[i] = arr[i];
	}
	for (int i = 0; i < 4; i++) {
		printf("%d \n", pArr[i]);
	}
	free(pArr);
	system("pause");
}*/



/*int main() {
	enum Days {
		Sunday = 1,Monday,Tue,W,T,F,S
	};
	enum Days TheDay;
	int j = 0;
	printf("다음 동작을 선택해주세요 \n1.Attack 2.Move 3.Jump 4.Hide \n>>");
	scanf("%d", &j);
	TheDay = Days(j);
	if (TheDay == Sunday || TheDay == S)
		printf("주말");
	else printf("평일");
}*///열거형

/*typedef union rdbuf {
	int  ibuf[2];
	char str[8];
}rdbuf;

int main() {
	rdbuf buf = { 0 };
	buf.ibuf[0] = 1819043144;
	buf.ibuf[1] = 6184559;
	printf("%s\n", buf.str);
}*/



/*typedef union ubox {
	int mem1;
	int mem2;
	double mem3;
}ubox;

int main() {
	ubox ubx = { 0 };
	ubx.mem1 = 20;
	printf("mem1 : %d\n", ubx.mem1);
	printf("mem2 : %d\n", ubx.mem2);
	printf("mem3 : %lf\n", ubx.mem3);
	ubx.mem3 = 7.15;

	printf("mem1 : %d\n", ubx.mem1);
	printf("mem2 : %d\n", ubx.mem2);
	printf("mem3 : %lf\n", ubx.mem3);
	return 0;
}*/

/*typedef struct book {
	char name[20];
	char writername[20];
	char chulpan[20];
	char date[8];
	int price;
}book;
int main() {
	book Book;
	scanf("%s %s %s %s %d", Book.name, Book.writername, Book.chulpan, Book.date, &Book.price);
	printf("%s %s %s %s %d", Book.name, Book.writername, Book.chulpan, Book.date, Book.price);
}*/

/*typedef struct student {
	int stuno;
	char name[20];
	char grade;
}stu;
void printstudent(stu a) {
	printf("%d %s %c", a.stuno, a.name, a.grade);
}
int main() {
	stu s = { 1,"Hong Gil Dong",'A' };
	printstudent(s);
}*/


/*typedef struct aaaa {
	int stuno;
	char name[20];
	char grade;
}aaaa;
int main() {

	aaaa aaa;
	aaaa* aaap = &aaa;
	aaa = { 1,"Hong Gil Dong",'A' };
	printf("%d %s %c\n", aaa.stuno, aaa.name, aaa.grade);
	printf("%d %s %c\n", aaap-> stuno, aaap-> name, aaap->grade);
	printf("%d %s %c\n", (*aaap).stuno , (*aaap).name, (*aaap).grade);
}*/


/*typedef struct sturec {
	int stuno;
	char name[20];
	int Kor, Eng, Math, total;
	double avg;
	int rank;
}sturec;
int main() {
	sturec s[5];
	for (int i = 0; i < 5; i++) {
		printf("학생의 학번 성명 국어 영어 수학 점수를 입력하세요 : ");
		scanf("%d %s %d %d %d",&s[i].stuno,s[i].name,&s[i].Kor,&s[i].Eng,&s[i].Math);
		s[i].total = s[i].Kor + s[i].Eng + s[i].Math;
		s[i].avg = (double)s[i].total / 3;
	}
	for (int i = 0; i < 5; i++) {
		int count=1;
		for (int j = 0; j < 5; j++) {
			if (s[i].avg < s[j].avg) count++;
		}
		s[i].rank = count;
		printf("%d %s %d %d %d %d %.2lf %d\n", s[i].stuno, s[i].name, s[i].Kor, s[i].Eng, s[i].Math, s[i].total, s[i].avg, s[i].rank);
	}
	
}*/

/*typedef struct money {
	int number;
	int won;
}money;
int main() {
	money m[5];
	int max=0,index;
	for (int i = 0; i < 5; i++) {
		printf("\n%d번 저축금액은? ", i + 1);
		m[i].number = i + 1;
		scanf("%d", &m[i].won);
		max = (max > m[i].won) ? max : m[i].won;
	}
	for (int i = 0; i < 5; i++) {
		if (max == m[i].won) index = i+1;

	}
	printf("\n저축왕 %d번 %d원", index, max);

}*/

/*int main() {
	char c[100] = { 0 };
	int count = 0;
	scanf("%[^\n]s", c);
	for (int i = 0; c[i] != 0; i++) {
		count++;
	}
	printf("입력받은 문자열의 길이는 %d입니다.\n", count);
	for (int i = count; i >= 0; i--) {
		printf("%c", c[i]);
	}
}*/


/*int main() {
	char c[100] = {0};
	scanf("%[^\n]s", c);
	for (int i = 0 ; c[i]!=0; i++) {
		if (c[i] == 32) printf("\n");
		else printf("%c", c[i]);
	}
}*/




/*typedef struct student {
	char name[20];
	float tall, weight;
	int money;
}student;
void change(student *studentp) {
	if (studentp->tall < 180) studentp->tall = 180;
	if (studentp->weight > 80)studentp->weight = 80;
}
int main() {
	student stu;
	scanf("%s %f %f %d", stu.name, &stu.tall, &stu.weight, &stu.money);
	change(&stu);
	printf("%s %f %f %d", stu.name, stu.tall, stu.weight, stu.money);
}*/


/*typedef struct student {
	char name[20];
	float tall,weight;
	int money;
}student;
int main() {
	student student = { "Gildong",173,86.2,0 };
	printf("이름  = %s %p \n키   = %.1f %p \n몸무게 = %.1f %p \n장학금 = %d %p", student.name, &student.name, student.tall, &student.tall, student.weight, &student.weight, student.money, &student.money);
}*/

/*typedef struct data {
	char name[20];
	int age;
}buddy;
int main() {
	buddy me = { "양성훈",17 };
	buddy friends;
	printf("친한 친구의 이름과 나이를 입력하세요. : ");
	scanf("%s %d", friends.name, &friends.age);
	printf("당신의 이름: %s, 나이 : %d \n친구의 이름: %s, 나이 : %d", me.name, me.age, friends.name, friends.age);
}*/


/*typedef struct data {
	char name[20];
	int age;
}data;
int main() {
	data human;
	printf("당신의 이름은 무엇입니까? ");
	scanf("%s", human.name);
	printf("당신의 나이는 몇 살입니까? ");
	scanf("%d", human.age);
	printf("당신의 이름은 %s이고 나이는 %d세이군요.", human.name, human.age);
}*/


/*int gcd(int x, int y) {
	int r = x % y;
	if (r == 0) return y;
	else return gcd(x, r);
}
int main() {
	int x, y;
	printf("2개 정숫값의 최대 공약수를 구합니다.");

	scanf("%d %d", &x, &y);
	printf("최대 공약수는 %d입니다.", gcd(x, y));
}*/


/*void rev_strings(char s[][128], int n) {
	char temp;
	int end=127, i, j, start=0;
	for ( i = 0; i < n; i++) {
		start = 0;
		for (j = 0; j < 128; j++) {
			if (s[i][j + 1] == NULL) {
				end = j;
				break;
			}
		}
		for (; end>n/2; end--) {
			temp = s[i][start];
			s[i][start] = s[i][end];
			s[i][end] = temp;
			start++;
		}
	}
}
int main() {
	char s[3][128] = { "SEC","ABC","1234" };
	rev_strings(s, 3);
	for (int i = 0; i < 3; i++) {
		printf("s[%d] = ""%s""\n", i, s[i]);
	}
}*/



/*void ary_set(int v[], int n, int val) {
	for (int i = 0; i < n; i++) {
		v[i] = val;
	}
}

int main() {
	int v[5] = {1,2,3,4,5};
	ary_set(&v[2], 2, 99);
	for (int i = 0; i < 5; i++) {
		printf("v[%d] = %d\n", i, v[i]);
	}
}*/


/*int search_idx(const int v[], int index[], int key, int n) {
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == key){
			index[result] = i;
		result++;
		}
	}
	return result;
}
int main() {
	int v[7], key, find, index[7] = {-2,-2,-2,-2,-2,-2,-2};
	for (int n = 0; n < 7; n++) {
		printf("vx[%d] : ", n);
		scanf("%d", &v[n]);
	}
	printf("찾을 값 : ");
	scanf("%d", &key);
	find = search_idx(v, index, key, 7);
	if (find > 0) {
		printf("%d은(는) %d개 있습니다.\n", key, find);
		for (int i = 0; i < 7; i++) {
			if (index[i] != -2)
				printf("vx[%d] = %d\n", index[i],v[index[i]]);
		}
	}
	else printf("탐색에 실패했습니다.");

}*/

/*int searchr(const int v[], int key, int n) {
	int result=-1;
	for (int i = 0; i < n; i++) {
		if (v[i] == key)result = i+1;
	}
	return result;
}
int main() {
	int v[5],key,find;
	for (int n = 0; n < 5; n++) {
		printf("vx[%d] : ", n);
		scanf("%d", &v[n]);
	}
	printf("찾을 값 : ");
	scanf("%d", &key);
	find = searchr(v, key, 5);
	if (find >= 0) printf("%d은(는) %d번째에 있습니다.", key, find);
	else printf("탐색에 실패했습니다.");
}*/



/*void print(int grade[]) {
	printf("합격자 목록\n");
	for (int i = 0; i < 7; i++) {
		if (grade[i] >= 60) printf("%d번 : %d\n", i + 1, grade[i]);
	}
}
int main() {
	int grade[7];
	printf("7명의 점수를 입력하시오 : \n");
	for (int i = 0; i < 7; i++){
		printf("%d : ", i + 1);
		scanf("%d", &grade[i]);
	}
	print(grade);

}*/




/*int count = 0;
void put_count(int num) {
	if (num == 0) return;
	count++;
	printf("put_count : %d회\n",count);
	put_count(--num);
}


int main() {
	int n;
	printf("호출 횟수 : ");
	scanf("%d", &n);
	put_count(n);
}*/
/*int main() {
	int math[6], lang[6];
	int mathsum = 0, langsum = 0, sum = 0;
	printf("6명의 점수를 입력하세요.");
	for (int i = 0; i < 6; i++) {
		printf("\n%d번_국어: ",i+1);
		scanf("%d",&lang[i]);
		printf("    수학: ");
		scanf("%d", &math[i]);
	}
	printf("-------------------------------------------- \n번호	국어	수학	합계	평균 \n-------------------------------------------- \n");
	for (int i = 0; i < 6; i++) {
		printf("%d	%d	%d	%d	%.1lf\n", i + 1, lang[i], math[i], lang[i]+math[i], ((double)lang[i] + math[i]) / 2);
		mathsum += math[i]; langsum += lang[i]; sum += lang[i] + math[i];
	}
	printf("합계	%d	%d	%d\n", langsum, mathsum, sum);
	printf("평균	%f	%f	%f", (float)langsum / 6, (float)mathsum / 6, (float)sum / 6);

}*/

/*typedef struct point
{
	int xpos;
	int ypos;
} Point;
typedef struct rectangle {
	Point locate1;
	Point locate2;
}rectangle;

void ShowRecArea(rectangle rect) {
	int nulbi = (rect.locate2.xpos - rect.locate1.xpos) * (rect.locate2.ypos - rect.locate1.ypos);
	int serogili = rect.locate2.ypos - rect.locate1.ypos;
	printf("넓이 : %d\n",nulbi);
	printf("좌 상단 : [%d, %d]\n", rect.locate1.xpos, rect.locate1.ypos);
	printf("좌 하단 : [%d, %d]\n", rect.locate1.xpos, rect.locate1.ypos+serogili);
	printf("우 상단 : [%d, %d]\n", rect.locate2.xpos,rect.locate2.ypos-serogili);
	printf("우 하단 : [%d, %d]\n", rect.locate2.xpos, rect.locate2.ypos);
}

void ShowRecPos(rectangle rect) {
	int count=0;
	for (int y = rect.locate2.ypos; y >=0 &&count !=2; y--) {
		for (int x = 0; x <= 100&& count!=2; x++) {
			if (rect.locate1.xpos == x && rect.locate1.ypos == y) {
				printf(".");
				count++;
			}
			else if (rect.locate2.xpos == x && rect.locate2.ypos == y) {
				printf(".");
				count++;
			}
			else printf(" ");
		}printf("\n");
	}
}

int main()
{
	rectangle rec1 = { {1, 1}, {4, 4} };
	rectangle rec2 = { {0, 0}, {7, 5} };
	ShowRecArea(rec1);
	ShowRecPos(rec1);
	ShowRecArea(rec2);
	ShowRecPos(rec2);
}*/

/*typedef struct Point {
	int xpos;
	int ypos;
}Point;
void Swap(Point *po1, Point *po2) {
	Point temp;
	temp = (*po1);
	*po1 = *po2;
	*po2 = temp;

}
int main() {
	Point p1 = { 10,20 };
	Point p2 = { 100,200 };
	Swap(&p1, &p2);

	printf("p1 : [%d, %d]\n", p1.xpos, p1.ypos);
	printf("p2 : [%d, %d]\n", p2.xpos, p2.ypos);
}*/

/*typedef struct Point {
	int xpos;
	int ypos;
}Point;
typedef struct circle {
	double radius;
	Point* center;
}Circle;
int main() {
	Point cen = { 2,7 };
	double rad = 5.5;
	Circle ring = { rad,&cen };
	printf("원의 반지름 : %g \n", ring.radius);
	printf("원의 중심 [%d %d] \n", (ring.center)->xpos, (ring.center)->ypos);
}*/



/* struct Person {
	int age;
	char name[101];
	int join;
}Person;
Person arr[1000001];
int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %s", &arr[i].age, arr[i].name);
		arr[i].join = 1;
	}
	Person* ptr = arr;
	printf("\n출력\n");
	for (i = 1; i <= n; i++) {
		printf("%d %s\n", (ptr + i)->age, (ptr + i)->name);
	}
}*/



/*typedef struct Person {
	char name[20];
	char phoneNum[20];
	int age;
}Person;
int main() {
	Person arr[3];
	int i;
	for (i = 0; i < 3; i++) {
		scanf("%s %s %d", arr[i].name, arr[i].phoneNum, &arr[i].age);
	}
	for (i = 0; i < 3; i++) {
		printf("%s %s %d\n", arr[i].name, arr[i].phoneNum, arr[i].age);
	}
}*/


/*typedef struct Point {
	int xpos;
	int ypos;
}Point;
int main() {
	Point arr[3];
	int i;
	for (i = 0; i < 3; i++) {
		printf("점의 좌표 입력 : ");
		scanf("%d %d", &arr[i].xpos, &arr[i].ypos);
	}
	for (i = 0; i < 3; i++) {
		printf("[%d, %d]", arr[i].xpos, arr[i].ypos);
	}
	return 0;
}*/

/*void change(int *a,int *b) {
	int temp;
	temp = *a;
	*a =*b;
	*b = temp;
}
void sort(int* a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n-1; j++) {
			if (a[j] > a[j + 1]) {
				change(&a[j], &a[j + 1]);
			}

		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}
int main() {
	int data[10] = { 5,2,3,7,1,9,4,6,8,10 },k;
	scanf("%d", &k);
	sort(data, k);
	
}*/




/*void findmm(int a[], int n,int *max,int *min) {
	*max = a[0]; *min = (a[0] < a[1]) ? a[0] : a[1];
	for (int i = 0; i < n-1; i++) {
		*max = (*max > a[i+1]) ? *max : a[i + 1];
		*min = (*min < a[i + 1]) ? *min : a[i + 1];
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("최대 : %d  최소 : %d\n", *max, *min);
}
int main() {
	int a[10] = {5,2,3,7,1,9,4,6,8,10},min,max;
	findmm(a, 10, &max, &min);
	findmm(a, 4, &max, &min);
	findmm(a+3, 5, &max, &min);
}*///8번







/*int findmax(int a[], int n) {
	int result=a[0];
	for (int i = 0; i < n-1; i++) {
		result = (result > a[i+1]) ? result : a[i + 1];
	}
	return result;
}
int main() {
	int a[10] = {5,2,3,7,1,9,4,6,8,10},n;
	scanf("%d", &n);
	printf("최대 = %d", findmax(a, n));
}*///7번


/*int main() {
	int n, j, result = 1;
	printf("한 개의 정수를 입력하시오 : ");
	scanf("%d", &n);
	for (j = 1; j <= n; j++) {
		result *= j;
	}
	printf("%d! = %d",n, result);
}*///6-2 답

/*int factorial(int n) {
	if (n == 1) return 1;
	return n * factorial(n - 1);
}
int main() {
	int n;
	printf("한 개의 정수를 입력하시오 : ");
	scanf("%d", &n);
	printf("%d! = %d", n, factorial(n));
}//6-1 답*/


/*int count = 1;
void calculate(int a, int b, int c) {
	
	printf("%d 번째로 calculate 함수 호출\n", count++);
	printf("총점 : %d\n", a + b + c);
	printf("평균 : %.2f\n", (float)(a + b + c) / 3);
}//5-2 답
void calculate2(int a, int b, int c) {
	int count = 1;
	printf("%d 번째로 calculate 함수 호출\n",count++);
	printf("총점 : %d\n", a + b + c);
	printf("평균 : %d\n",(a+b+c)/3);
}//5-1 답
int main()
{
	int Lang=0, En, Math;
	while (1) {
		printf("국어 영어 수학 점수를 입력하시오 (중단하려면 문자 입력). : ");
		if (scanf("%d %d %d", &Lang, &En, &Math) == 0) return 0;
		calculate(Lang, En, Math);
	}

}*/


/*int main() {
	int num[5] = { 36,23,-89,98,30 };
	int* p = num;

	printf("%d %d %p %d %p", num[1], *(p + 1),p+2,*p+3,&num[4]);
}*///4 답


//int main() {
	/*int num[5] = { 98,35,23,-36,58 },sum=0;
	for (int i = 0; i < 5; i++) {
		sum += num[i];
	}
	printf("%d", sum / 5);*///3-1답

	/*int num[5] = { 98,35,23,-36,58 }, sum = 0, *p=num;
	for (int i = 0; i < 5; i++) {
		sum += *(p+i);
	}
	printf("%d", sum / 5);*///3-2답
//}

/*int main() {
	int a[3][3] = { {4,9,3}, {7,1,2},{5,8,6} }, b[3][3] = { {-9,2,6}, {8,7,3},{1,5,-4} };
	int result[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result[i][j] = a[i][j] + b[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", result[i][j]);
		}printf("\n");
	}
}*///2번 답


/*int main() {
	int n[5][5] = {0,}, i, j = 1, count = 1;
	for (i = 1; i <= 4; i++) {
		for (j=i; j <= 4; j++) {
			n[i][j] = count++;
		}
	}
	for (i = 1; i <= 4; i++) {
		for (j = 1; j <= 4; j++) {
			printf("%d ", n[i][j]);
		}printf("\n");
	}
}*///1번 답


/*void Trans(char res[], int N, int B) {
	int n = 33;
	char rest, over[36] = { 0, };
	for (int i = 10; i < 36; i++) {
		over[i] = i + 55;
	}
	for (int i = 0; i<34; i++) {
		if (N % B >= 10) {
			rest = over[N % B];
		}
		else rest = (char)(N % B+48);
		res[n] = rest;
		N = N / B;
		n--;
	}
}
int main()
{
	char res[35] = { 0,};
	int num, B;
	bool p = false;
	scanf("%d %d", &num, &B);
	Trans(res, num, B);
	for (int i = 0; i <= 33; i++) {

		if (res[i] != '0') p=true;
		if (p) printf("%c", res[i]);
	}

	return 0;
}*/
/*int GCD(int a, int b) {
	int result, i=1000000;
	while (1) {
		if (a % i == 0 && b % i == 0) {
			result = i;
			break;
		}
		i--;
	}
	return result;
}
void Input(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		scanf("%d",&arr[i]);
	}
	return;
}
long long SumGCD(int arr[], int len) {
	long long result=0;
	for (int j = 0; j < len; j++) {
		for (int i = 0; i < len; i++) {
			if (i==j) break;
			result += GCD(arr[j], arr[i]);
		}
	}
	return result;
}
int main()
{
	int TC, num;
	long long int result;
	int arr[101] = { 0 };
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d", &num);
		Input(arr, num);
		result = SumGCD(arr, num);
		printf("%lld\n", result);
	}
	return 0;
}*/ //함수응용 2

/*void Input(char* InputName) {
	scanf("%[^\n]s", InputName);
	return;
}
void Upper(char* name) {
	for (int i = 0; i < 1025; i++) {
		if ((int)*(name + i) >= 97 && (int)*(name + i) <= 122) {
			*(name + i) -= 32;
		}
	}
}
int main()
{	
	char buffer[1025] = { 0 };
	Input(buffer);
	Upper(buffer);
	printf("%s\n", buffer);
	return 0;
}*/ //함수응용 1번





/*void sosu(int a,int b) {
	int i, j, t = 0;
	for (i = a; i <= b; i++) {
		for (j = 2; j < a; j++) {
			if (i % j == 0) t = 1;

		}if (t != 1) printf("%d ", i);
		t = 0;
	}


}
int main() {
	sosu(2,30);
}*/
/*int count = 0;
int main() {
	int n, b,i,t=0;
	scanf("%d", &n);
	for (b = 2; b <= n; b++) {
		for (i = 2; i <= n; i++) {
			if (b % i == 0) {
				t++;
			}
			

		}
		if (t == 1)printf("%d\n", b);
		t = 0;
	}
}*/


/*long long int factorial(long long int n)
{
	if (n == 1)      // n이 1일 때
		return 1;    // 1을 반환하고 재귀호출을 끝냄

	return n * factorial(n - 1);    // n과 factorial 함수에 n - 1을 넣어서 반환된 값을 곱함
}

int main()
{
	long long int n;
	scanf("%lld", &n);
	printf("%lld", factorial(n));

	return 0;
}*/


/*int main() {
	double n, f=1;
	scanf("%lf", &n);
	for (int i = 2; i <= n; i++) {
		f *= i;
	}
	printf("%.0lf", f);
}*/

/*int main() {
	char a[1000] = {"우히힣힣히히히히히히히히히ㅣ히"};
	int i;

	for (i = 0; a[i] != NULL; i++);
	printf("%d", i);
}*/

/*int main() {
	const char* b[3];
	b[0] = "January";
	b[1] = "February";
	b[2] = "March";
	for (int i = 0; i < 3; i++) {
		printf("%d월은 %s입니다\n", i + 1, b[i]);
	}
}*/

/*int result, count = 5;
int sum(int* n) {
	if (count == 0) return result;
	result += *(n++);
	--count;
	sum(n);
}
int main() {
	int a[5] = { 10,20,30,40,50 };
	int* p = a;
	printf("%d", sum(p));
}*/// 답

/*int main()
{
	char c[16] = { "jungol olympiad" };
	int a[5];
	for (int i = 0; i < 5; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < 5; i++) {
		printf("%c", c[a[i]]);
	}

}*///03번 답

/*char asc(char num) {
	scanf(" %c", &num);
	printf("%c -> %d\n", num, num);
	if (num == '0') return 0;
	asc(num);
}
int main()
{
	char n=0;
	asc(n);
}*///1번 답

/*int devide=100000000,result=0;
int hap(int num,int count) {
	if (count == 0) return result;
	result = result+ (num / devide);//result에 num을 devide로 나눔

	num = num % devide;//num에 나누고 남은 값을 대입
	devide /= 10;//devide를 10으로 나누기
	return hap(num, --count);
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", hap(n, 9));
}*/

/*int num=0;
int jaegwi(int count,int num) {
	if (count == 0) return num;
	num += count;
	return jaegwi(--count,num);
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d",jaegwi(n,num));

}*/


/*void jaegwi(int count) {
	if (count == 1) return;
	jaegwi(--count);
	printf("%d ", count);
	
	
}
int main()
{
	int n;
	scanf("%d", &n);
	jaegwi(n);

}//답*/
/*int n,num=1;
int jaegwi(int count) {
	if (count == 0) return 0;
	printf("%d ", num++);
	return jaegwi(--count);
}
int main()
{
	scanf_s("%d", &n);
	jaegwi(n);

}*///02번 답

/*void mix(int x, int y) {
	int temp = x;
	x = y;
	y = temp;
	printf("\n첫 번째 함수 실행중 x = %d, y = %d\n",x,y);
}
void mix2(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
	printf("\n첫 번째 함수 실행중 x = %d, y = %d\n", *x, *y);
}
int main()
{
	int a, b;
	
	printf("두 수를 입력하세요. : ");
	scanf("%d %d", &a, &b);
	mix(a, b);
	printf("첫 번째 함수 실행후 a = %d, b = %d\n", a, b);
	mix2(&a, &b);
	printf("두 번째 함수 실행후 a = %d, b = %d", a, b);
}*///07번 답


/*int Add(int n1, int n2);
void ShowAddResult(int num);
int InputNum();
void HowToUseThisProg();

int main() {
	int result, num1, num2;
	HowToUseThisProg();
	num1 = InputNum();
	num2 = InputNum();
	result = Add(num1, num2);
	ShowAddResult(result);
}
void HowToUseThisProg() {
	printf("두 정수를 입력하면 더해서 출력합니다.\n");
}
int InputNum() {
	int a;
	scanf("%d", &a);
	return a;
}
int Add(int n1, int n2) {
	return n1 + n2;
}
void ShowAddResult(int n) {
	printf("입력한 값의 합은 %d입니다.", n);
}*/

/*int GetMax(int, int, int);
int main() {
	int nResult = 0;
	printf("Max : %d\n", GetMax(1, 2, 3));
	printf("Max : %d\n", GetMax(2, 3, 1)*2);//함수 결과에 *2
	printf("Max : %d\n", nResult = GetMax(3, 1, 2));//변수에 함수결과를 저장, 변수를 출력
	return 0;
}

int GetMax(int a, int b, int c) {
	int nMax = a;
	if (b > nMax) nMax = b;
	if (c > nMax) nMax = c;
	return nMax;
}*/

/*int Add(int, int);
int main() {
	int x, y, sum;
	printf("정수 두 개를 입력하세요~!(예 1 2) : ");
	scanf("%d %d", &x, &y);
	sum = Add(x, y);
	printf("%d + %d = %d", x, y, sum);
	return 0;
}

int Add(int n1, int n2) {
	int n3 = n1 + n2;
	return n3;
}*/

/*void line() {
	printf("----------------------------------------------\n");
}//함수 예제 1 (매개변수 X, 반환 X)

int ten() {
	return 10;
}//함수 예제 2 (매개변수 X, 반환 O)

void plus(int a, int b) {
	printf("두 수를 더하면 %d\n", a + b);
}//함수 예제 3 (매개변수 O, 반환 X)

int plus2(int a, int b) {
	int c = a + b;
	return c;
}//함수 예제 4 (매개변수 O, 반환 O)

int main()
{
	int n1, n2,sum;
	printf("함수 호출\n");
	line();
	printf("함수 호출 시 10 출력\n");
	printf("%d\n", ten());


	printf("숫자 두 개 입력 후 함수 호출\n");
	scanf_s("%d %d", &n1, &n2);
	plus(n1, n2);

	printf("숫자 두 개 입력 후 함수 호출\n");
	scanf_s("%d %d", &n1, &n2);
	sum = plus2(n1, n2);
	printf("두 수의 합은 %d\n", sum);
	printf("함수 그대로 출력 %d\n", plus2(n1, n2));
	printf("끝");
}*/



/*int a, b;
int swap(int x,int y) {
	a = y;
	b = x;
	return 0;
}
int main()
{
	scanf_s("%d %d", &a, &b);
	printf("swap()호출 전 a=%d, b=%d\n", a, b);
	swap(a, b);
	printf("swap()호출 후 a=%d, b=%d\n", a, b);
}*/
/*int get_larger(int x, int y) {
	if (x > y) return x;
	else if (y >= x) return y;
}
int main()
{
	int x, y;
	printf("두 개의 정수를 입력하시오 : ");
	scanf_s("%d %d", &x, &y);
	printf("두 수 중에서 큰 수는 %d입니다.", get_larger(x,y));
}*/

/*int name(int count) {
	if (count == 0) return 0;
	printf("양성훈\n");
	name(--count);
}
int main() {
	name(10);
}*///1번

/*int facto(int n) {
	if (n == 1) return n;
	return n*facto(--n);
}
int main()
{
	int n;
	scanf_s("%d", &n);
	printf("%d", facto(n));
}*///3번

/*int plus(int a, int b) {
	return a + b;
}
int minus(int a, int b) {
	if (a > b) return a - b;
	else if (b >= a) return b - a;
}
int main() {
	int a, b;
	scanf_s("%d %d", &a, &b);
	printf("두 수의 합 = %d \n두 수의 차 = %d", plus(a, b), minus(a, b));
}*///4번 답
/*int pibo(int n) {
	if (n < 3)return 1;
	return pibo(n - 1) + pibo(n - 2);
}
int main() {

	int n;
	scanf_s("%d", &n);
	printf("%d", pibo(n));
}//05번*/


/*int star(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
				printf("*");
		}printf("\n");
	}
	return 0;
}
int main()
{
	int n, i, j;
	scanf("%d", &n);
	star(n);
}//05번 답*/

/*int maxi(int a) {
	return a + 10;
}
int mini(int a) {
	return a - 10;
}
int main()
{
	int a;
	scanf("%d", &a);
	printf("10큰 수 : %d\n", maxi(a));
	printf("10작은 수 : %d\n", mini(a));
}*///02번 답

/*int line() {
	return printf("===================================\n");
}
int main() {
	line();
	printf("line 함수를 호출하였습니다.\n");
	printf("line 함수를 다시 호출합니다.\n");
	line();
}*///01번 답


/*int main() {
	int a[3] = { 10,20,30 };
	int* p=a;
	printf("a = %p, p = %p\n", &a, p);
	printf("%d %d %d\n", a[0], a[1], a[2]);
	printf("%d %d %d\n", p[0], p[1], p[2]);
	printf("%d %d %d\n", *a, *(a + 1), *(a + 2));
	printf("%d %d %d\n", *p, *(p + 1), *(p + 2));//4번

	/*int a=5;
	int* p=&a;
	printf("a = %d, *p = %d\n", a, *p);
	*p = 10;
	printf("a = %d, *p = %d\n", a, *p);
	a += 5;
	printf("a = %d, *p = %d\n", a, *p);
	*p *= 2;
	printf("a = %d, *p = %d\n", a, *p);
	(*p)--;
	printf("a = %d, *p = %d\n", a, *p);//2번 답*/

	/*int a=10, b;
	int* p = &a;
	printf("a = %d, &a = %p \n*p = %d, p = %p", a, &a, *p, p);//1번*/
	/*int arr[8] = { 1,3,5,7,9,11,13,15 };

	int* p = arr;
	int n = 0;
	n = *p++;
	printf("p=%p    *p=%d    n=%d\n", p, *p, n);
	n = *(p++);
	printf("p=%p    *p=%d    n=%d", p, *p, n);*/
//}
/*int main() {
	int i, j, arr[] = { 10,9,8,7,6,5,4,3,2,1 };
	int len = sizeof(arr) / sizeof(int), tmp;
	int* fptr = arr, * bptr = arr + len - 1;
	
	printf("%d %d %d\n\n\n", arr[10],len,*bptr );
	for (i = 0; i < len / 2; i++) {
		printf("*ftpr : %2d, *bptr : %2d [", *fptr, *bptr);
		tmp = *fptr;
		*fptr = *bptr;
		*bptr = tmp;
		fptr++; bptr--;
		for (j = 0; j < len; j++) {
			printf("%d ", *(arr + j));
		}
		printf("]\n");
	}
	printf("\n");
	for (i = 0; i < len; i++) {
		printf("%d", *(arr + i));
	}
}*/





/*int main()
{
	int arr[5] = { 1,2,3,4,5 }, i;
	int* ptr = arr;
	printf(" ptr : %p, arr : %p\n", ptr, arr);
	for (i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
	for (i = 0; i < 5; i++) {
		printf("%d ", *(ptr + i));
	}
	printf("\n");

	//for (i = 0; i < 5; i++) {
	//	printf("%d ", *(ptr++));
	//}
	printf("\n");
	for (i = 0; i < 5; i++) {
		printf(" ptr : %p, *ptr : %d, ", ptr, *ptr);
		ptr++;
		printf("ptr++연산 후 >> ptr : %p, *ptr : %d\n", ptr, *ptr);
	}
	printf("\n");
	printf("*ptr : %d\n", *ptr);
	printf("ptr : %p, arr : %p\n", ptr, arr);
}*/
/*int yabawi()
{

	srand(time(NULL));
	int a = 1, b = 2, c = 3, coin = 1, n1 = 0, n2 = 0, i = 0, answer, money = 10000, dobak, level = 700;
	do {
		if (money >= 15000)
			level = 50;
		else if (money >= 12500)
			level = 400;
		else if (money <= 5000)
			level = 1000;
		else if (money <= 10000)
			level = 700;

		printf("*야바위 게임* \n거실 돈을 정해주세요 \n현재 소지금 : %d \n", money);
		scanf("%d", &dobak);
		if (dobak > money) {
			printf("잘못된 접근입니다.");
			Sleep(2000);
			break;
		}
		i = rand() % 12 + 6;
		printf("처음 동전이 있는 위치는 1번입니다. (바뀌는 컵은 0번으로 바뀜)");
		coin = 1;
		Sleep(2000);
		system("cls");
		for (int k = 0; k < i; k++) {
			printf("%d %d %d", a, b, c);
			Sleep(200);
			do {
				n1 = rand() % 3 + 1;
				n2 = rand() % 3 + 1;
			} while (n1 == n2);
			if (n1 == 1 || n2 == 1)
				a = 0;
			if (n1 == 2 || n2 == 2)
				b = 0;
			if (n1 == 3 || n2 == 3)
				c = 0;
			if (coin == n1) {
				coin = n2;
			}
			else if (coin == n2) {
				coin = n1;
			}

			system("cls");
			printf("%d %d %d", a, b, c);
			Sleep(level);
			a = 1;
			b = 2;
			c = 3;

			system("cls");
		}
		printf("1 2 3\n동전이 있는 위치는? : ");
		scanf("%d", &answer);
		if (answer == coin) {
			printf("성공!\n");
			money += dobak;
		}
		else {
			printf("실패\n");
			money -= dobak;
		}
		if (money <= 0) {
			printf("이런 도박중독 땅그지(게임오버)");
			printf(" ");
			break;
		}
		else if (money >= 30000) {
			printf("축하드립니다! 승리하셨습니다!");
			printf("우아ㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏㅏ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n\n\n\n아아아아아아ㅏ아강가악아강가악ㅇ");
			break;
		}
		printf("다시 하시겠습니까? \n1. 계속 \n2. 그만 두기 \n");
		scanf("%d", &answer);
	} while (answer == 1);
	printf("종료했습니다.");
	return 0;
}
int main()
{
	yabawi();
}*/
/*int main()
{
	int count=0;
	char a[10000] = {};
	scanf("%s", a);
	for (int i = 0; i < 10000; i++) {
		if (a[i] == 0)
			break;
		count++;
	}
	printf("문자열의 길이 %d", count);
}*/
/*int main()
{
	int a[4] = {},i;
	float r = 0;
	for (i = 1; i <= 3; i++) {
		printf("게임 %d에서 선수의 득점은? ",i);
		scanf("%d", &a[i]);
		r += a[i];
	}
	printf("평균 득점은 %f입니다.", r / 3);
}*/
/*int main()
{
	int a[11] = {}, n, i;
	while (1) {
		printf("1 2 3 4 5 6 7 8 9 10\n");
		for (i = 1; i <= 10; i++) {
			printf("%d ", a[i]);
		}
		printf("\n원하시는 좌석번호를 입력하세요<종료는 -1>: ");
		scanf("%d", &n);
		if (a[n] == 1) {
			printf("이미 예약된 자리입니다.");
			break;
		}
		if (n == -1)
			break;
		a[n] = 1;
	}

}*/
/*int main()
{
	int a[101] = {}, i,j;

	for (i = 1;  i <= 100; i++) {
		a[i] = i;
		printf("%d	%d	",i, a[i]);
		for (j = 1; j <= a[i]; j++) {
			printf("*");
		}printf("\n");
	}
}*/
/*int main()
{
	int a[7] = { 0,1,2,3,4,5,6 }, b[7] = { 0,1,2,3,4,5,6 }, i, j;
	printf("주사위 합이 7이 되는 경우는\n");
	for (i = 1; i <= 6; i++) {
		for (j = 1; j <= 6; j++) {
			if (a[i] + b[j] == 7)
				printf("%d	%d\n", a[i], b[j]);
		}
	}
}*/
/*int main()
{
	int a[1000] = {}, i, n, c = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		if (n % i == 0)
			a[i] = i;
		c++;
	}
	for (i = 1; i <= n; i++) {
		if(a[i]!=0)
		printf("%d ", a[i]);
	}
}*/
/*int main()
{
	int a[100], i, n,r=0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		a[i] = i * i;
		r += a[i];
	}
	printf("계산값은 %d 입니다.", r);
}*/
/*int main()
{
	int a;
	scanf("%d", &a);
	printf("10큰 수 : %d \n10작은 수 : %d", a + 10, a - 10);
}*///02번 답
/*int line() {
	return printf("===================================\n");
}
int main() {
	line();
	printf("line 함수를 호출하였습니다.\n");
	printf("line 함수를 다시 호출합니다.\n");
	line();
}*///01번 답
/*int main()
{
	int a[4][4], b[4][4], r[4][4], i, j;
	for (i = 1; i < 4; i++) {
		for (j = 1; j < 4; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 1; i < 4; i++) {
		for (j = 1; j < 4; j++) {
			scanf("%d", &b[i][j]);
		}
	}
	for (i = 1; i < 4; i++) {
		for (j = 1; j < 4; j++) {
			r[i][j] = a[i][j] + b[i][j];
			printf("%d ", r[i][j]);
		}printf("\n");
	}
}*///05번 답
/*int main() {
	int a[4][4] = {}, i;
	for (i = 1; i <= 3; i++) {
		if (i == 1) {
			a[i][1]=3;
			a[i][2] = 5;
			a[i][3] = 4;
		}
		if (i == 2) {
			a[i][1] = 2;
			a[i][2] = 6;
			a[i][3] = 7;
		}
		if (i == 3) {
			a[i][1] = 8;
			a[i][2] = 10;
			a[i][3] = 1;
		}
	}
	for (i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			printf("%d ", a[i][j]);
		}printf("\n");
	}
}*///04번 문제
/*int main()
{
	int a[45] = {0,1,1,}, i, n;
	for (i = 2; i <= 41; i++) {
		a[i + 1] = a[i] + a[i - 1];
	}
	printf("피보나치 수열 10항: %d \n피보나치 수열 20항: %d \n피보나치 수열 30항: %d \n피보나치 수열 40항: %d \n", a[10], a[20], a[30], a[40]);
}*///03번 문제
/*int main()
{
	int a[11] = {}, n, i;
	for (i = 1; i < 1000;i++) {
		scanf("%d", &n);
		switch(n) {
		case 1:
			a[1]++;
			break;
		case 2:
			a[2]++;
			break;
		case 3:
			a[3]++;
			break;
		case 4:
			a[4]++;
			break;
		case 5:
			a[5]++;
			break;
		case 6:
			a[6]++;
			break;
		case 7:
			a[7]++;
			break;
		case 8:
			a[8]++;
			break;
		case 9:
			a[9]++;
			break;
		case 10:
			a[10]++;
			break;
		default:
			break;
		}
		if (n < 1 || n>10) break;
	}
	for (i = 1; i <= 10; i++) {
		if (a[i] != 0) {
			printf("%d : %d개\n", i, a[i]);
		}
	}
}*///01번 문제
/*int main() {

	int a[101][101] = {}, i = 1, j = 1, n, m, k,q=1;
	scanf("%d %d", &n, &m);
	int num = 0;
	for (k = 1; k <= n+m; k++) {
		for (i=m; i >= 0; i--) {
			for (j=1; j <= n; j++) {
				if (i - j == k) {
					a[j][i] = ++num;
				}
			}
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			printf("%d ", a[i][j]);
		}printf("\n");
	}
}*/
/*int main(void)
{
	int a[10][10], num = 1,n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = num++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = n; j > 0; j++) {
			if (a[i][j] < 10)
				printf(" ");
			printf("%d ", a[i][j]);
		}printf("\n");
	}
}*/
	/*int Arr[101][101] = {};


	int n, m;
	scanf("%d %d", &n, &m);
	int x = 0;
	int k = 1;
	for (int i = m; i >= 1; i--) {
		if (k % 2 == 0) {
			for (int j = 1; j <=n; j++) {
				Arr[j][i] = ++x;
			}
		}
		else {
			for (int j = n; j >= 1; j--) {
				Arr[j][i] = ++x;
			}
		}
		k++;



	}



	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", Arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}*/
	/*int a[10][10] = { 0 }, n, m, i, j, num = 1;
	scanf("%d %d", &n, &m);
	for (i = n - 1; i >= 0; i--) {
		for (j = m - 1; j >= 0; j--) {
			a[i][j] = num++;
		}
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			printf("%d ", a[j][i]);
		}printf("\n");
	}*/
	/*int a[5] = { 95,75,85,100,50 },j,k,max;
	for (j = 0; j < 5; j++){
		for (k = 0; k < 4; k++){
			if (a[k] > a[k + 1]) {
				max = a[k];
				a[k] = a[k + 1];
				a[k + 1] = max;
			}
		}
	}
	for (j = 0; j < 5; j++) {
		printf("%d ", a[j]);
	}//09번 답*/
	/*int r[10], i,s=0;
	for (i = 0; i < 10; i++) {
		scanf("%d", &r[i]);
		s += r[i];
	}
	printf("%d %.1f", s, (float)s / 10);//08번 답*/
	/*int n[10], i, max=0, min=0;
	for (i = 0; i < 10; i++) {
		scanf("%d", &n[i]);
		if (n[i] % 2 == 0 && n[i] > max)
			max = n[i];
		if (n[i] % 2 != 0 && n[i] < min)
			min = n[i];
	}
	printf("%d %d", max, min);//07번 답*/
	/*int n[10], i, max = 0;
	for (i = 0; i < 10; i++) {
		scanf("%d", &n[i]);
		if (n[i] > max)
			max = n[i];
	}
	printf("%d", max);//06번 답*/
	/*int n[100] = {}, i;
	for (i = 0; i < 100; i++) {
		scanf("%d", &n[i]);
		if (n[i] != 0 && (i + 1) % 2 == 0) {
			printf("%d ", n[i]);
		}
		if (n[i] == 0)
			break;
	}//04번 답*/
	/*int a[10], i;
	for (i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d %d %d", a[2], a[4], a[9]);//03번 답*/
	/*int a,i;
	char c[26];
	a = 'Z';
	for (i = 0; i < 26; i++) {
		c[i] = a;
		a--;
		printf("%c ", c[i]);
	}//02번 답*/
	/*int n, i, j,r=1;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i >= j) {
				printf("%d", r);
				r++;
			}
		}printf("\n");
	}//06번 답*/
	/*int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = n+1; j > 0; j--) {

			if (i >= j) {
				printf("*");
			}

			else {
				printf(" ");
			}
		}printf("\n");
	}//04번 답*/
	/*int a, b=0,i;
	scanf("%d", &a);
	for (i = 1;; i++) {
		b = b + i;
		if (b > a)
			break;
	}
	printf("%d %d", i, b);//01번 답*/


//int main()
//{
	/*int i,j,a[4][4] = { 0, },count=4,minus;

	for (i = 0; i < 4; i++) {
		if (i == 1 || i == 3)
			count += 5;
		if (i == 2)
			count += 3;
		for (j = 0; j < 4; j++) {
			a[i][j] = count;
			if (i== 0 || i==2) {
				printf("%d", a[i][j]);
				count--;
			}
			else {
				printf("%d", a[i][j]);
				count++;
			}
		}printf("\n");
	}*/
	/*int max = 0, min = 101;
	int a[10], sum=0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	for (int i = 0; i < 10; i++) {
		max = (max > a[i]) ? max : a[i];
		min = (min < a[i]) ? min : a[i];
	}
	printf("최댓값 : %d \n최솟값 : %d \n합계 : %d \n평균 : %d", max, min,sum,sum/10);*/
//}

//int main()
//{
	/*int a = 0, b = 0, i = 0;
	while (1) {
		scanf("%d", &a);
		if (a % 2 != 0) {
			b = b + a;
			i++;
		}
		if (a == 0)
			break;
	}
	printf("홀수의 합 = %d \n홀수의 평균 = %d",b,b/i);//05번 답*/
	/*int a=0, b=0 ,i=0;
	while (1) {
		scanf("%d", &a);
		if (a == 0)
			break;
		b = b + a;
		i++;
	}
	printf("입력된 자료의 개수 = %d \n입력된 자료의 합계 = %d \n입력된 자료의 평균 = %.2f", i, b, (float)b / i);//04번 답*/
	/*int i=0;
	while (i >= 0 && i <= 100) {
		printf("\n점수를 입력하세요. ");
		scanf("%d", &i);
		if (i >= 80 && i<=100)
			printf("합격입니다.");
		else if (i < 80 && i>=0)
			printf("불합격입니다.");
	}//03번 답*/
	/*int num = 1, i=0;
	while (num != 11) {
		i = i + num;
		num++;
	}
	printf("1부터 10까지의 합 = %d \nwhile문의 끝난 후의 num의 값 = %d", i, num);//02번 답*/

	/*int a[10],n=0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
		if (a[i] % 2 == 0)
			n++;
	}
	printf("입력받은 짝수는 %d개입니다.", n);//05번 답*/
	/*int a=0;
	printf("1. 입력하기 \n2. 출력하기 \n3. 삭제하기 \n4. 끝내기");
	while (a != 4) {
		printf("\n작업할 번호를 선택하세요. ");
		scanf("%d", &a);
		if (a == 1)
			printf("입력하기를 선택하였습니다.");
		else if (a == 2)
			printf("출력하기를 선택하였습니다.");
		else if (a == 3)
			printf("삭제하기를 선택하였습니다.");
		else if (a == 4)
			printf("끝내기를 선택하였습니다.");
		else
			printf("잘못 선택하였습니다.");
	}//06번 답*/
	/*int a, b, c,n=0;
	printf("세 수를 입력하세요");
	scanf("%d %d %d", &a, &b, &c);
	n = (a > b) ? a : b;
	n = (n > c) ? n : c;
	printf("%d", n);//06번 답*/
	/*int a, b;
	printf("주사위를 던진 결과를 입력하세요. ");
	scanf("%d %d", &a, &b);
	if (a >= 4 && b >= 4)
		printf("이겼습니다.");
	else if (a >= 4 || b >= 4)
		printf("비겼습니다.");
	else if (a < 4 && b < 4)
		printf("졌습니다.");//05번 답*/
	/*int a;
	printf("점수를 입력하세요. ");
	scanf("%d", &a);
	if (a >= 80)
		printf("합격");
	else
		printf("불합격");//03번 답*/
	/*int a, b;
	scanf("%d %d", &a, &b);
	if (a > b)
		printf("입력받은 수 중 큰 수는 %d이고 작은 수는 %d입니다.", a, b);
	else
		printf("입력받은 수 중 큰 수는 %d이고 작은 수는 %d입니다.", b, a);//02번 답*/
	/*int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d %d %d %d", a == b, b == c, a != b, b != c);//05번 답*/
	/*int a, b,c;
	scanf("%d %d", &a, &b);
	printf("a = %d, b = %d, c = %d", a, b, ++a + b--);//04번 답*/
	/*int h;
	float w;
	char n;
	printf("키를 입력하세요. ");
	scanf("%d", &h);
	printf("몸무게를 입력하세요. ");
	scanf("%f", &w);
	printf("이름을 입력하세요. ");
	scanf(" %c", &n);

	printf("키 = %d \n몸무게 = %.1f \n이름 = %c", h, w, n);//08번 답*/
//}
/*int main()
{
	int i, j,n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j < 10; j++) printf("%d * %d = %d ", j, i, j * i);
		printf("\n");
	}
}*/
/*int main()
{
	int n = 0, j = 0;
	scanf("%d", &n);
	int x = n * 2, y = n * 2;
	for (int i = 0; i < n; i++) {
		x = x - 2;
		y = y + 2;
		for (j = 0; j <= n * 2; j++) {
			if (j == x / 2 + 1 || j == y / 2 - 1) {
				printf("*");
			}
			else if (i == n - 1 && j > x / 2 && j < y / 2)
				printf("*");
			else
				printf(" ");
		}printf("\n");
	}
}*///13번 답


/*int main()
{
	int n = 0, j = 0;
	scanf("%d", &n);
	int x = n * 2, y = n * 2;
	for (int i = 0; i < n; i++) {
		x = x - 2;
		y = y + 2;
		for (j = 0; j <= n * 2; j++) {
			if (j == x / 2+1 || j == y / 2-1) {
				printf("*");
			}
			else
				printf(" ");
		}printf("\n");
	}
}*///12번
/*int main()
{
	int n = 0, j = 0;
	scanf("%d", &n);
	for (int i = 0; i < n-1; i++) {
		for (j = n; j >= 0; j--) {
			if (i >= j)
				printf("*");
			else
				printf(" ");
		}printf("\n");
	}
	for (int i = 0; i < n; i++) {
		for (j = 0; j <= n; j++) {
			if (i <= j-1)
				printf("*");
			else
				printf(" ");
		}printf("\n");
	}
}*///10번 답

/*int main()
{
	int n = 0, j = 0;
	scanf("%d", &n);
	for (int i = 0; i < n-1; i++) {
		for (j = 0; j <= n; j++) {
			if (i >= j)
				printf("*");
			else
				printf(" ");
		}printf("\n");
	}
	for (int i = 0; i < n-1; i++) {
		for (j = n; j >= 0; j--) {
			if (i < j)
				printf("*");
			else
				printf(" ");
		}printf("\n");
	}
	printf("*");
}*///11번 답
/*int main()
{
	int n = 0, j = 0;
	scanf("%d", &n);
	int x = 0, y = n * 4;
	for (int i = 0; i <= n-2; i++) {
		x = x + 2;
		y = y - 2;
		for (j = 0; j <= n * 2; j++) {//j의 값을 10으로, 범위를 0이상으로, j-1 하면 댐
			if (j >= x / 2 && j <= y / 2) {
				printf("*");
			}
			else
				printf(" ");
		}printf("\n");
	}
	int o = n * 2, p = n * 2;
	for (int i = 0; i < n; i++) {
		o = o - 2;
		p = p + 2;
		for (j = 0; j <= n * 2; j++) {//j의 값을 10으로, 범위를 0이상으로, j-1 하면 댐
			if (j > o / 2 && j < p / 2) {
				printf("*");
			}
			else
				printf(" ");
		}printf("\n");
	}
}*///9번 답

/*int main()
{
	int n = 0, j = 0;
	scanf("%d", &n);
	int o = 0, p = n * 4;
	for (int i = 0; i < n; i++) {
		o = o + 2;//끝부분 별 위치
		p = p - 2;//앞부분 별 위치
		for (j = 0; j <= n * 2; j++) {
			if (j < o / 2 || j > p / 2) {
				printf("☆");//앞부분 별 위치에서 끝부분 별 위치까지 별 찍기
			}
			else if (j == n);//중앙 공백 방지
			else
				printf("  ");
		}printf("\n");
	}
	int x = n * 2, y = n * 2;
	for (int i = 0; i <= n; i++) {
		x = x - 2;
		y = y + 2;
		for (j = 0; j <= n * 2; j++) {
			if (j < x / 2 || j > y / 2) {
				printf("☆");
			}
			else if (j == n);
			else
				printf("  ");
		}printf("\n");
	}
}*///8번 답
/*int main()
{
	int n = 0, j = 0;
	scanf("%d", &n);
	int x = n * 2, y = n * 2;
	for (int i = 0; i < n; i++) {
		x = x - 2;
		y = y + 2;
		for (j = 0; j <= n * 2; j++) {
			if (j > x / 2 && j < y / 2) {
				printf("*");
			}
			else
				printf(" ");
		}printf("\n");
	}
	int o = 0, p = n * 4;
	for (int i = 0; i <= n; i++) {
		o = o + 2;
		p = p - 2;
		for (j = 0; j <= n * 2; j++) {
			if (j > o / 2 && j < p / 2) {
				printf("*");
			}
			else
				printf(" ");
		}printf("\n");
	}
}*///7번 답
/*int main()
{
	int n = 0, j = 0;
	scanf("%d", &n);
	int x = n*2, y = n*2;
	for (int i = 0; i < n*2; i++) {
		if (x <= n / 2) {
			x += 2;
			y -= 2;
		}
		else {
			x -= 2;
			y += 2;
		}

		for (j = 0; j <= n * 2; j++) {
			if (x <= n / 2 && j > x / 2 && j < y / 2) {
				printf("*");
			}
			else
				printf(" ");
		}printf("\n");
	}
}*/

/*int main()
{
	int n = 0, j = 0;
	scanf("%d", &n);
	int x = n * 2, y = n * 2;
	for (int i = 0; i <= n; i++) {
		x = x - 2;
		y = y + 2;
		for (j = 0; j <= n * 2; j++) {
			if (j > x / 2 && j < y / 2) {
				printf("*");
			}
			else
				printf(" ");
		}printf("\n");
	}
}*///5번 답
/*int main()
{
	int n = 0, j = 0;
	scanf("%d", &n);
	int x = 0, y = n*4;
	for (int i = 0; i <= n; i++) {
		x = x + 2;
		y = y - 2;
		for (j = 0; j <= n*2; j++) {
			if (j > x/2 && j < y/2) {
				printf("*");
			}
			else
				printf(" ");
		}printf("\n");
	}
}*///6번 답
/*int main()
{
	int n = 0, j = 0;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		for (j = 0; j <= n; j++) {
			if (i >= j)
				printf("*");
			else
				printf(" ");
		}printf("\n");
	}
}*///1번 답
/*int main()
{
	int n = 0, j = 0;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		for (j = 0; j <= n; j++) {
			if (i <= j)
				printf("*");
			else
				printf(" ");
		}printf("\n");
	}
}*///4번 답
/*int main()
{
	int n = 0, j = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (j = n; j >= 0; j--) {//j의 값을 10으로, 범위를 0이상으로, j-1 하면 댐
			if (i >= j)
				printf("*");
			else
				printf(" ");
		}printf("\n");
	}
}*///2번
/*int main()
{
	int n = 0, j = 0;
	scanf("%d", &n);
	for (int i=0; i < n; i++) {
		for (j = n; j >=0 ; j--) {//j의 값을 10으로, 범위를 0이상으로, j-1 하면 댐
			if (i <= j)
				printf("*");
			else
				printf(" ");
		}printf("\n");
	}
	printf("*");
}*///3번


/*int main() {
	int num = 0;
	while (1) {
		if (num >= 5)
			break;
		printf("while 내부 실행 : %d \n", num);
		num++;
	}
}*/


/*int main()
{
	int a,b=0;
	while (b==0) {
		scanf("%d %d", &a,&b);
		if (a % 2 == 0)
			printf("짝수\n");
		else
			printf("홀수\n");
		if (b != 0)//b로 반복여부 판단
			break;
	}
}*/


/*int main()
{
	int a,b;
	int q=0, w = 0, e = 0;
	printf("입력 : ");
	scanf("%d", &a);
	if (a / 100 >= 1)
		q = a / 100;
	if ((a - (q * 100)) / 10 >= 1)
		w = (a - (q * 100)) / 10;
	e = a - (q * 100 + w * 10);
	b = (e * 100) + (w * 10) + q;

	if (q == 0 && e == 0)
		printf("%d", w);
	else if (q == 0)
		printf("%d%d", e, w);
	else
	printf("%d", b);
}*/