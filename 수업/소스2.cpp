/*#pragma warning(disable:4996)
// ���� #8 ��ǥ ������� ����ϱ�
// �й� :1212
// �̸� :�缺��
#include <stdio.h>
// ����ü ���� �κ�
typedef struct locate {
	int x;
	int y;
}locate;
// �Լ� ���� �κ�
void exchange(locate* a, locate* b);

void input(locate* p);

void comp(locate* p);

void print(locate* p);
// main �Լ�
int main()
{

	locate L[3];
	input(L);
	comp(L);
	print(L);
	return 0;
}
// �Լ� ���Ǻκ�
void exchange(locate* a, locate* b) {
	locate temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void input(locate* p) {
	for (int i = 0; i < 3; i++) {
		printf("��ǥ P%d", i + 1);
		scanf("%d %d", &(p + i)->x, &(p + i)->y);
	}
}

void comp(locate* p) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (p[j].x > p[j + 1].x) {
				exchange(p + j, p + j + 1);
			}
			else if ((p + j)->x == (p + j + 1)->x) {
				if ((p + j)->y > (p + j + 1)->y) {
					exchange(p + j, p + j + 1);
				}
			}
		}
	}
	if (p[0].x > p[2].x && p[0].y > p[2].y)exchange(p, p + 2);

}

void print(locate* p) {
	for (int i = 0; i < 3; i++) {
		printf("[%d %d]\n", (p + i)->x, (p + i)->y);
	}
}*/