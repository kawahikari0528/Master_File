#pragma warning(disable: 4996)
#include<stdio.h>
#include<windows.h>
#include <stdlib.h>
#include<math.h>
#include <time.h> // time()함수 포함 라이브러리
#include <string.h>




void Trans(char res[], int N, int B) {
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
}
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





//int count=0;
/*void sosu(int n) {
	int i,t = 0;
	if (n == 1) return;
	for (i = 2; i <= n; i++) {
		if (n % i == 0) t++;
	}if (t == 1) count++;
	t = 0;
	sosu(--n);
	
}*/

/*int main() {
	int n, b,i,t=0;
	scanf("%d", &n);
	printf("%d", count);
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