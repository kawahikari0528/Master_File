/*#pragma warning(disable:4996)
// ���� #7 ȸ�� ������ �Է¹ް� ����ϱ�
// �й� :1212
// �̸� :�缺��
#include <stdio.h>
// ����ü ���� �κ�
typedef struct people {
	int age;
	char name[30];
}people;
// �Լ� ���� �κ�
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
// main �Լ�
int main()
{
	int n;
	people human[100] = {0,0};
	scanf("%d", &n);
	input(human, n);
	print(human, n);
	return 0;
}*/
// �Լ� ���Ǻκ�