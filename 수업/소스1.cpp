/*#pragma warning(disable:4996)
// 수행 #7 회원 정보를 입력받고 출력하기
// 학번 :1212
// 이름 :양성훈
#include <stdio.h>
// 구조체 선언 부분
typedef struct people {
	int age;
	char name[30];
}people;
// 함수 선언 부분
void input(people* p,int n) {
	for (int i = 0; i < n; i++) {
		scanf("%d %s", &(p+i)->age, (p+i)->name);
	}
}
void print(people* p, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d %s\n", (p+i)->age,(p + i)->name);
	}
}
// main 함수
int main()
{
	int n;
	people human[100] = {0,0};
	scanf("%d", &n);
	input(human, n);
	print(human, n);
	return 0;
}*/
// 함수 정의부분