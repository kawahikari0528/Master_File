/*#pragma warning(disable:4996)
// 수행 #9 구조체로 실수 저장 하기
// 학번 :1212	
// 이름 :양성훈
#include <stdio.h>
// 구조체 선언 부분
typedef struct floatToChar {
	char toc[30];
}ftoc;
// 함수 선언 부분
void input(ftoc* p, int n);

void findInfo(ftoc* p,int n);

void print(ftoc* fc, int n, int* decpt, int* sign);
// main 함수
int main()
{
	int n;
	ftoc fc[10] = {0};
	printf("실수 입력 개수 : ");
	scanf("%d", &n);
	input(fc, n);
	findInfo(fc, n);
	return 0;
}
// 함수 정의부분
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
			if (p[i].toc[j] > 48 && senser2 == 0) senser2 = 1;//자연수일때 센서2 on
			if (p[i].toc[j] == 46) senser = 1;//점이 나왔을 때 센서1 on

			if (p[i].toc[j] == 48 && senser2 == 0) {


				if (senser2 == 0 && p[i].toc[j] == 48) {
					decpt[i]--;
				}
			}//자연수가 나오지 않았고 0일때 -1

			if (senser == 0 && p[i].toc[j] >= 48&& senser2==1) {
				decpt[i]++;
			}//점이 나오지 않았고 자연수일때 +1

			if (p[i].toc[j] >= 48 && senser == 0) {
				sum += p[i].toc[j];
				count++;
			}//숫자이고 점이 나오지 않았을때 sum에 값을 더하고 카운트




			if (p[i].toc[j] == 45) sign[i] = -1;//앞에 -가 있으면 음수판정
			

		}
		if (sum == 0) {
			decpt[i]--;
		}

		count = 0;
		senser = 0;
		senser2 = 0;
		sum = 0;//초기화
	}
	print(p, n, decpt, sign);//출력
}

void print(ftoc* fc, int n,int *decpt,int *sign){
	int senser = 0, count, sum = 0;
	for (int i = 0; i < n; i++) {
		count = 0;
		printf("%d번째 실수------------------------------------------------------------------\ndigits : ",i+1);
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