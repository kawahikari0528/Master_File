/*#pragma warning(disable:4996)
// ���� #9 ����ü�� �Ǽ� ���� �ϱ�
// �й� :1212	
// �̸� :�缺��
#include <stdio.h>
// ����ü ���� �κ�
typedef struct floatToChar {
	char toc[30];
}ftoc;
// �Լ� ���� �κ�
void input(ftoc* p, int n);

void findInfo(ftoc* p,int n);

void print(ftoc* fc, int n, int* decpt, int* sign);
// main �Լ�
int main()
{
	int n;
	ftoc fc[10] = {0};
	printf("�Ǽ� �Է� ���� : ");
	scanf("%d", &n);
	input(fc, n);
	findInfo(fc, n);
	return 0;
}
// �Լ� ���Ǻκ�
void input(ftoc* p, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d : ", i + 1);
		scanf("%s", p[i].toc);
	}
}

void findInfo(ftoc* p, int n) {
	int sum = 0, count = 0,i,j;
	int senser=0,senser2=0;
	int decpt[10] = { 0, };
	int sign[10] = { 1, 1,1,1,1,1,1,1,1,1};
	for ( i = 0; i < n; i++) {



		for ( j = 0; j < 30; j++) {
			if (p[i].toc[j] > 48 && senser2 == 0) senser2 = 1;//�ڿ����϶� ����2 on
			if (p[i].toc[j] == 46) senser = 1;//���� ������ �� ����1 on

			if (p[i].toc[j] == 48 && senser2 == 0) {


				if (senser2 == 0 && p[i].toc[j] == 48) {
					decpt[i]--;
				}
			}//�ڿ����� ������ �ʾҰ� 0�϶� -1

			if (senser == 0 && p[i].toc[j] >= 48&& senser2==1) {
				decpt[i]++;
			}//���� ������ �ʾҰ� �ڿ����϶� +1

			if (p[i].toc[j] >= 48 && senser == 0) {
				sum += p[i].toc[j];
				count++;
			}//�����̰� ���� ������ �ʾ����� sum�� ���� ���ϰ� ī��Ʈ




			if (p[i].toc[j] == 45) sign[i] = -1;//�տ� -�� ������ ��������
			

		}
		if (sum == 0) {
			decpt[i]--;
		}

		count = 0;
		senser = 0;
		senser2 = 0;
		sum = 0;//�ʱ�ȭ
	}
	print(p, n, decpt, sign);//���
}

void print(ftoc* fc, int n,int *decpt,int *sign){
	int senser = 0, count, sum = 0;
	for (int i = 0; i < n; i++) {
		count = 0;
		printf("%d��° �Ǽ�------------------------------------------------------------------\ndigits : ",i+1);
		for (int j = 0; j < 30; j++) {

			if (fc[i].toc[j] != 46 && fc[i].toc[j] != 45 && fc[i].toc[j] != 48) {
				senser = 1;
			}

			if (fc[i].toc[j] != 46 && fc[i].toc[j] != 45 && senser == 1 && fc[i].toc[j] != NULL) {
				printf("%c", fc[i].toc[j]);
				count++;
			}

		}
		senser = 0;
		for (int i = 0; i < (30 - count); i++) printf("0");
		printf("\n");


		printf(" decpt : %d \n  sign : %d\n", decpt[i], sign[i]);
	}
}*/