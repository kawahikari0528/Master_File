#pragma warning(disable: 4996)
#include<stdio.h>
#include<windows.h>
#include <stdlib.h>
#include<math.h>
#include <time.h> // time()ÇÔ¼ö Æ÷ÇÔ ¶óÀÌºê·¯¸®
#include <string.h>

typedef struct point
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
	printf("³ÐÀÌ : %d\n",nulbi);
	printf("ÁÂ »ó´Ü : [%d, %d]\n", rect.locate1.xpos, rect.locate1.ypos);
	printf("ÁÂ ÇÏ´Ü : [%d, %d]\n", rect.locate1.xpos, rect.locate1.ypos+serogili);
	printf("¿ì »ó´Ü : [%d, %d]\n", rect.locate2.xpos,rect.locate2.ypos-serogili);
	printf("¿ì ÇÏ´Ü : [%d, %d]\n", rect.locate2.xpos, rect.locate2.ypos);
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
}

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
	printf("¿øÀÇ ¹ÝÁö¸§ : %g \n", ring.radius);
	printf("¿øÀÇ Áß½É [%d %d] \n", (ring.center)->xpos, (ring.center)->ypos);
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
	printf("\nÃâ·Â\n");
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
		printf("Á¡ÀÇ ÁÂÇ¥ ÀÔ·Â : ");
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
	printf("ÃÖ´ë : %d  ÃÖ¼Ò : %d\n", *max, *min);
}
int main() {
	int a[10] = {5,2,3,7,1,9,4,6,8,10},min,max;
	findmm(a, 10, &max, &min);
	findmm(a, 4, &max, &min);
	findmm(a+3, 5, &max, &min);
}*///8¹ø







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
	printf("ÃÖ´ë = %d", findmax(a, n));
}*///7¹ø


/*int main() {
	int n, j, result = 1;
	printf("ÇÑ °³ÀÇ Á¤¼ö¸¦ ÀÔ·ÂÇÏ½Ã¿À : ");
	scanf("%d", &n);
	for (j = 1; j <= n; j++) {
		result *= j;
	}
	printf("%d! = %d",n, result);
}*///6-2 ´ä

/*int factorial(int n) {
	if (n == 1) return 1;
	return n * factorial(n - 1);
}
int main() {
	int n;
	printf("ÇÑ °³ÀÇ Á¤¼ö¸¦ ÀÔ·ÂÇÏ½Ã¿À : ");
	scanf("%d", &n);
	printf("%d! = %d", n, factorial(n));
}//6-1 ´ä*/


/*int count = 1;
void calculate(int a, int b, int c) {
	
	printf("%d ¹øÂ°·Î calculate ÇÔ¼ö È£Ãâ\n", count++);
	printf("ÃÑÁ¡ : %d\n", a + b + c);
	printf("Æò±Õ : %.2f\n", (float)(a + b + c) / 3);
}*///5-2 ´ä
/*void calculate(int a, int b, int c) {
	int count = 1;
	printf("%d ¹øÂ°·Î calculate ÇÔ¼ö È£Ãâ\n",count++);
	printf("ÃÑÁ¡ : %d\n", a + b + c);
	printf("Æò±Õ : %d\n",(a+b+c)/3);
}*///5-1 ´ä
/*int main()
{
	int Lang=0, En, Math;
	while (Lang>=0) {
		printf("±¹¾î ¿µ¾î ¼öÇÐ Á¡¼ö¸¦ ÀÔ·ÂÇÏ½Ã¿À (Áß´ÜÇÏ·Á¸é ¹®ÀÚ ÀÔ·Â). : ");
		scanf("%d %d %d", &Lang, &En, &Math);
		calculate(Lang, En, Math);
	}

}*/


/*int main() {
	int num[5] = { 36,23,-89,98,30 };
	int* p = num;

	printf("%d %d %p %d %p", num[1], *(p + 1),p+2,*p+3,&num[4]);
}*///4 ´ä


//int main() {
	/*int num[5] = { 98,35,23,-36,58 },sum=0;
	for (int i = 0; i < 5; i++) {
		sum += num[i];
	}
	printf("%d", sum / 5);*///3-1´ä

	/*int num[5] = { 98,35,23,-36,58 }, sum = 0, *p=num;
	for (int i = 0; i < 5; i++) {
		sum += *(p+i);
	}
	printf("%d", sum / 5);*///3-2´ä
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
}*///2¹ø ´ä


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
}*///1¹ø ´ä


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
}*/ //ÇÔ¼öÀÀ¿ë 2

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
}*/ //ÇÔ¼öÀÀ¿ë 1¹ø





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
	if (n == 1)      // nÀÌ 1ÀÏ ¶§
		return 1;    // 1À» ¹ÝÈ¯ÇÏ°í Àç±ÍÈ£ÃâÀ» ³¡³¿

	return n * factorial(n - 1);    // n°ú factorial ÇÔ¼ö¿¡ n - 1À» ³Ö¾î¼­ ¹ÝÈ¯µÈ °ªÀ» °öÇÔ
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
	char a[1000] = {"¿ìÈ÷ÆRÆRÈ÷È÷È÷È÷È÷È÷È÷È÷È÷¤ÓÈ÷"};
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
		printf("%d¿ùÀº %sÀÔ´Ï´Ù\n", i + 1, b[i]);
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
}*/// ´ä

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

}*///03¹ø ´ä

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
}*///1¹ø ´ä

/*int devide=100000000,result=0;
int hap(int num,int count) {
	if (count == 0) return result;
	result = result+ (num / devide);//result¿¡ numÀ» devide·Î ³ª´®

	num = num % devide;//num¿¡ ³ª´©°í ³²Àº °ªÀ» ´ëÀÔ
	devide /= 10;//devide¸¦ 10À¸·Î ³ª´©±â
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

}//´ä*/
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

}*///02¹ø ´ä

/*void mix(int x, int y) {
	int temp = x;
	x = y;
	y = temp;
	printf("\nÃ¹ ¹øÂ° ÇÔ¼ö ½ÇÇàÁß x = %d, y = %d\n",x,y);
}
void mix2(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
	printf("\nÃ¹ ¹øÂ° ÇÔ¼ö ½ÇÇàÁß x = %d, y = %d\n", *x, *y);
}
int main()
{
	int a, b;
	
	printf("µÎ ¼ö¸¦ ÀÔ·ÂÇÏ¼¼¿ä. : ");
	scanf("%d %d", &a, &b);
	mix(a, b);
	printf("Ã¹ ¹øÂ° ÇÔ¼ö ½ÇÇàÈÄ a = %d, b = %d\n", a, b);
	mix2(&a, &b);
	printf("µÎ ¹øÂ° ÇÔ¼ö ½ÇÇàÈÄ a = %d, b = %d", a, b);
}*///07¹ø ´ä


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
	printf("µÎ Á¤¼ö¸¦ ÀÔ·ÂÇÏ¸é ´õÇØ¼­ Ãâ·ÂÇÕ´Ï´Ù.\n");
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
	printf("ÀÔ·ÂÇÑ °ªÀÇ ÇÕÀº %dÀÔ´Ï´Ù.", n);
}*/

/*int GetMax(int, int, int);
int main() {
	int nResult = 0;
	printf("Max : %d\n", GetMax(1, 2, 3));
	printf("Max : %d\n", GetMax(2, 3, 1)*2);//ÇÔ¼ö °á°ú¿¡ *2
	printf("Max : %d\n", nResult = GetMax(3, 1, 2));//º¯¼ö¿¡ ÇÔ¼ö°á°ú¸¦ ÀúÀå, º¯¼ö¸¦ Ãâ·Â
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
	printf("Á¤¼ö µÎ °³¸¦ ÀÔ·ÂÇÏ¼¼¿ä~!(¿¹ 1 2) : ");
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
}//ÇÔ¼ö ¿¹Á¦ 1 (¸Å°³º¯¼ö X, ¹ÝÈ¯ X)

int ten() {
	return 10;
}//ÇÔ¼ö ¿¹Á¦ 2 (¸Å°³º¯¼ö X, ¹ÝÈ¯ O)

void plus(int a, int b) {
	printf("µÎ ¼ö¸¦ ´õÇÏ¸é %d\n", a + b);
}//ÇÔ¼ö ¿¹Á¦ 3 (¸Å°³º¯¼ö O, ¹ÝÈ¯ X)

int plus2(int a, int b) {
	int c = a + b;
	return c;
}//ÇÔ¼ö ¿¹Á¦ 4 (¸Å°³º¯¼ö O, ¹ÝÈ¯ O)

int main()
{
	int n1, n2,sum;
	printf("ÇÔ¼ö È£Ãâ\n");
	line();
	printf("ÇÔ¼ö È£Ãâ ½Ã 10 Ãâ·Â\n");
	printf("%d\n", ten());


	printf("¼ýÀÚ µÎ °³ ÀÔ·Â ÈÄ ÇÔ¼ö È£Ãâ\n");
	scanf_s("%d %d", &n1, &n2);
	plus(n1, n2);

	printf("¼ýÀÚ µÎ °³ ÀÔ·Â ÈÄ ÇÔ¼ö È£Ãâ\n");
	scanf_s("%d %d", &n1, &n2);
	sum = plus2(n1, n2);
	printf("µÎ ¼öÀÇ ÇÕÀº %d\n", sum);
	printf("ÇÔ¼ö ±×´ë·Î Ãâ·Â %d\n", plus2(n1, n2));
	printf("³¡");
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
	printf("swap()È£Ãâ Àü a=%d, b=%d\n", a, b);
	swap(a, b);
	printf("swap()È£Ãâ ÈÄ a=%d, b=%d\n", a, b);
}*/
/*int get_larger(int x, int y) {
	if (x > y) return x;
	else if (y >= x) return y;
}
int main()
{
	int x, y;
	printf("µÎ °³ÀÇ Á¤¼ö¸¦ ÀÔ·ÂÇÏ½Ã¿À : ");
	scanf_s("%d %d", &x, &y);
	printf("µÎ ¼ö Áß¿¡¼­ Å« ¼ö´Â %dÀÔ´Ï´Ù.", get_larger(x,y));
}*/

/*int name(int count) {
	if (count == 0) return 0;
	printf("¾ç¼ºÈÆ\n");
	name(--count);
}
int main() {
	name(10);
}*///1¹ø

/*int facto(int n) {
	if (n == 1) return n;
	return n*facto(--n);
}
int main()
{
	int n;
	scanf_s("%d", &n);
	printf("%d", facto(n));
}*///3¹ø

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
	printf("µÎ ¼öÀÇ ÇÕ = %d \nµÎ ¼öÀÇ Â÷ = %d", plus(a, b), minus(a, b));
}*///4¹ø ´ä
/*int pibo(int n) {
	if (n < 3)return 1;
	return pibo(n - 1) + pibo(n - 2);
}
int main() {

	int n;
	scanf_s("%d", &n);
	printf("%d", pibo(n));
}//05¹ø*/


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
}//05¹ø ´ä*/

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
	printf("10Å« ¼ö : %d\n", maxi(a));
	printf("10ÀÛÀº ¼ö : %d\n", mini(a));
}*///02¹ø ´ä

/*int line() {
	return printf("===================================\n");
}
int main() {
	line();
	printf("line ÇÔ¼ö¸¦ È£ÃâÇÏ¿´½À´Ï´Ù.\n");
	printf("line ÇÔ¼ö¸¦ ´Ù½Ã È£ÃâÇÕ´Ï´Ù.\n");
	line();
}*///01¹ø ´ä


/*int main() {
	int a[3] = { 10,20,30 };
	int* p=a;
	printf("a = %p, p = %p\n", &a, p);
	printf("%d %d %d\n", a[0], a[1], a[2]);
	printf("%d %d %d\n", p[0], p[1], p[2]);
	printf("%d %d %d\n", *a, *(a + 1), *(a + 2));
	printf("%d %d %d\n", *p, *(p + 1), *(p + 2));//4¹ø

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
	printf("a = %d, *p = %d\n", a, *p);//2¹ø ´ä*/

	/*int a=10, b;
	int* p = &a;
	printf("a = %d, &a = %p \n*p = %d, p = %p", a, &a, *p, p);//1¹ø*/
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
		printf("ptr++¿¬»ê ÈÄ >> ptr : %p, *ptr : %d\n", ptr, *ptr);
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

		printf("*¾ß¹ÙÀ§ °ÔÀÓ* \n°Å½Ç µ·À» Á¤ÇØÁÖ¼¼¿ä \nÇöÀç ¼ÒÁö±Ý : %d \n", money);
		scanf("%d", &dobak);
		if (dobak > money) {
			printf("Àß¸øµÈ Á¢±ÙÀÔ´Ï´Ù.");
			Sleep(2000);
			break;
		}
		i = rand() % 12 + 6;
		printf("Ã³À½ µ¿ÀüÀÌ ÀÖ´Â À§Ä¡´Â 1¹øÀÔ´Ï´Ù. (¹Ù²î´Â ÄÅÀº 0¹øÀ¸·Î ¹Ù²ñ)");
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
		printf("1 2 3\nµ¿ÀüÀÌ ÀÖ´Â À§Ä¡´Â? : ");
		scanf("%d", &answer);
		if (answer == coin) {
			printf("¼º°ø!\n");
			money += dobak;
		}
		else {
			printf("½ÇÆÐ\n");
			money -= dobak;
		}
		if (money <= 0) {
			printf("ÀÌ·± µµ¹ÚÁßµ¶ ¶¥±×Áö(°ÔÀÓ¿À¹ö)");
			printf(" ");
			break;
		}
		else if (money >= 30000) {
			printf("ÃàÇÏµå¸³´Ï´Ù! ½Â¸®ÇÏ¼Ì½À´Ï´Ù!");
			printf("¿ì¾Æ¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿¤¿!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n\n\n\n¾Æ¾Æ¾Æ¾Æ¾Æ¾Æ¤¿¾Æ°­°¡¾Ç¾Æ°­°¡¾Ç¤·");
			break;
		}
		printf("´Ù½Ã ÇÏ½Ã°Ú½À´Ï±î? \n1. °è¼Ó \n2. ±×¸¸ µÎ±â \n");
		scanf("%d", &answer);
	} while (answer == 1);
	printf("Á¾·áÇß½À´Ï´Ù.");
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
	printf("¹®ÀÚ¿­ÀÇ ±æÀÌ %d", count);
}*/
/*int main()
{
	int a[4] = {},i;
	float r = 0;
	for (i = 1; i <= 3; i++) {
		printf("°ÔÀÓ %d¿¡¼­ ¼±¼öÀÇ µæÁ¡Àº? ",i);
		scanf("%d", &a[i]);
		r += a[i];
	}
	printf("Æò±Õ µæÁ¡Àº %fÀÔ´Ï´Ù.", r / 3);
}*/
/*int main()
{
	int a[11] = {}, n, i;
	while (1) {
		printf("1 2 3 4 5 6 7 8 9 10\n");
		for (i = 1; i <= 10; i++) {
			printf("%d ", a[i]);
		}
		printf("\n¿øÇÏ½Ã´Â ÁÂ¼®¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä<Á¾·á´Â -1>: ");
		scanf("%d", &n);
		if (a[n] == 1) {
			printf("ÀÌ¹Ì ¿¹¾àµÈ ÀÚ¸®ÀÔ´Ï´Ù.");
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
	printf("ÁÖ»çÀ§ ÇÕÀÌ 7ÀÌ µÇ´Â °æ¿ì´Â\n");
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
	printf("°è»ê°ªÀº %d ÀÔ´Ï´Ù.", r);
}*/
/*int main()
{
	int a;
	scanf("%d", &a);
	printf("10Å« ¼ö : %d \n10ÀÛÀº ¼ö : %d", a + 10, a - 10);
}*///02¹ø ´ä
/*int line() {
	return printf("===================================\n");
}
int main() {
	line();
	printf("line ÇÔ¼ö¸¦ È£ÃâÇÏ¿´½À´Ï´Ù.\n");
	printf("line ÇÔ¼ö¸¦ ´Ù½Ã È£ÃâÇÕ´Ï´Ù.\n");
	line();
}*///01¹ø ´ä
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
}*///05¹ø ´ä
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
}*///04¹ø ¹®Á¦
/*int main()
{
	int a[45] = {0,1,1,}, i, n;
	for (i = 2; i <= 41; i++) {
		a[i + 1] = a[i] + a[i - 1];
	}
	printf("ÇÇº¸³ªÄ¡ ¼ö¿­ 10Ç×: %d \nÇÇº¸³ªÄ¡ ¼ö¿­ 20Ç×: %d \nÇÇº¸³ªÄ¡ ¼ö¿­ 30Ç×: %d \nÇÇº¸³ªÄ¡ ¼ö¿­ 40Ç×: %d \n", a[10], a[20], a[30], a[40]);
}*///03¹ø ¹®Á¦
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
			printf("%d : %d°³\n", i, a[i]);
		}
	}
}*///01¹ø ¹®Á¦
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
	}//09¹ø ´ä*/
	/*int r[10], i,s=0;
	for (i = 0; i < 10; i++) {
		scanf("%d", &r[i]);
		s += r[i];
	}
	printf("%d %.1f", s, (float)s / 10);//08¹ø ´ä*/
	/*int n[10], i, max=0, min=0;
	for (i = 0; i < 10; i++) {
		scanf("%d", &n[i]);
		if (n[i] % 2 == 0 && n[i] > max)
			max = n[i];
		if (n[i] % 2 != 0 && n[i] < min)
			min = n[i];
	}
	printf("%d %d", max, min);//07¹ø ´ä*/
	/*int n[10], i, max = 0;
	for (i = 0; i < 10; i++) {
		scanf("%d", &n[i]);
		if (n[i] > max)
			max = n[i];
	}
	printf("%d", max);//06¹ø ´ä*/
	/*int n[100] = {}, i;
	for (i = 0; i < 100; i++) {
		scanf("%d", &n[i]);
		if (n[i] != 0 && (i + 1) % 2 == 0) {
			printf("%d ", n[i]);
		}
		if (n[i] == 0)
			break;
	}//04¹ø ´ä*/
	/*int a[10], i;
	for (i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d %d %d", a[2], a[4], a[9]);//03¹ø ´ä*/
	/*int a,i;
	char c[26];
	a = 'Z';
	for (i = 0; i < 26; i++) {
		c[i] = a;
		a--;
		printf("%c ", c[i]);
	}//02¹ø ´ä*/
	/*int n, i, j,r=1;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i >= j) {
				printf("%d", r);
				r++;
			}
		}printf("\n");
	}//06¹ø ´ä*/
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
	}//04¹ø ´ä*/
	/*int a, b=0,i;
	scanf("%d", &a);
	for (i = 1;; i++) {
		b = b + i;
		if (b > a)
			break;
	}
	printf("%d %d", i, b);//01¹ø ´ä*/


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
	printf("ÃÖ´ñ°ª : %d \nÃÖ¼Ú°ª : %d \nÇÕ°è : %d \nÆò±Õ : %d", max, min,sum,sum/10);*/
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
	printf("È¦¼öÀÇ ÇÕ = %d \nÈ¦¼öÀÇ Æò±Õ = %d",b,b/i);//05¹ø ´ä*/
	/*int a=0, b=0 ,i=0;
	while (1) {
		scanf("%d", &a);
		if (a == 0)
			break;
		b = b + a;
		i++;
	}
	printf("ÀÔ·ÂµÈ ÀÚ·áÀÇ °³¼ö = %d \nÀÔ·ÂµÈ ÀÚ·áÀÇ ÇÕ°è = %d \nÀÔ·ÂµÈ ÀÚ·áÀÇ Æò±Õ = %.2f", i, b, (float)b / i);//04¹ø ´ä*/
	/*int i=0;
	while (i >= 0 && i <= 100) {
		printf("\nÁ¡¼ö¸¦ ÀÔ·ÂÇÏ¼¼¿ä. ");
		scanf("%d", &i);
		if (i >= 80 && i<=100)
			printf("ÇÕ°ÝÀÔ´Ï´Ù.");
		else if (i < 80 && i>=0)
			printf("ºÒÇÕ°ÝÀÔ´Ï´Ù.");
	}//03¹ø ´ä*/
	/*int num = 1, i=0;
	while (num != 11) {
		i = i + num;
		num++;
	}
	printf("1ºÎÅÍ 10±îÁöÀÇ ÇÕ = %d \nwhile¹®ÀÇ ³¡³­ ÈÄÀÇ numÀÇ °ª = %d", i, num);//02¹ø ´ä*/

	/*int a[10],n=0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
		if (a[i] % 2 == 0)
			n++;
	}
	printf("ÀÔ·Â¹ÞÀº Â¦¼ö´Â %d°³ÀÔ´Ï´Ù.", n);//05¹ø ´ä*/
	/*int a=0;
	printf("1. ÀÔ·ÂÇÏ±â \n2. Ãâ·ÂÇÏ±â \n3. »èÁ¦ÇÏ±â \n4. ³¡³»±â");
	while (a != 4) {
		printf("\nÀÛ¾÷ÇÒ ¹øÈ£¸¦ ¼±ÅÃÇÏ¼¼¿ä. ");
		scanf("%d", &a);
		if (a == 1)
			printf("ÀÔ·ÂÇÏ±â¸¦ ¼±ÅÃÇÏ¿´½À´Ï´Ù.");
		else if (a == 2)
			printf("Ãâ·ÂÇÏ±â¸¦ ¼±ÅÃÇÏ¿´½À´Ï´Ù.");
		else if (a == 3)
			printf("»èÁ¦ÇÏ±â¸¦ ¼±ÅÃÇÏ¿´½À´Ï´Ù.");
		else if (a == 4)
			printf("³¡³»±â¸¦ ¼±ÅÃÇÏ¿´½À´Ï´Ù.");
		else
			printf("Àß¸ø ¼±ÅÃÇÏ¿´½À´Ï´Ù.");
	}//06¹ø ´ä*/
	/*int a, b, c,n=0;
	printf("¼¼ ¼ö¸¦ ÀÔ·ÂÇÏ¼¼¿ä");
	scanf("%d %d %d", &a, &b, &c);
	n = (a > b) ? a : b;
	n = (n > c) ? n : c;
	printf("%d", n);//06¹ø ´ä*/
	/*int a, b;
	printf("ÁÖ»çÀ§¸¦ ´øÁø °á°ú¸¦ ÀÔ·ÂÇÏ¼¼¿ä. ");
	scanf("%d %d", &a, &b);
	if (a >= 4 && b >= 4)
		printf("ÀÌ°å½À´Ï´Ù.");
	else if (a >= 4 || b >= 4)
		printf("ºñ°å½À´Ï´Ù.");
	else if (a < 4 && b < 4)
		printf("Á³½À´Ï´Ù.");//05¹ø ´ä*/
	/*int a;
	printf("Á¡¼ö¸¦ ÀÔ·ÂÇÏ¼¼¿ä. ");
	scanf("%d", &a);
	if (a >= 80)
		printf("ÇÕ°Ý");
	else
		printf("ºÒÇÕ°Ý");//03¹ø ´ä*/
	/*int a, b;
	scanf("%d %d", &a, &b);
	if (a > b)
		printf("ÀÔ·Â¹ÞÀº ¼ö Áß Å« ¼ö´Â %dÀÌ°í ÀÛÀº ¼ö´Â %dÀÔ´Ï´Ù.", a, b);
	else
		printf("ÀÔ·Â¹ÞÀº ¼ö Áß Å« ¼ö´Â %dÀÌ°í ÀÛÀº ¼ö´Â %dÀÔ´Ï´Ù.", b, a);//02¹ø ´ä*/
	/*int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d %d %d %d", a == b, b == c, a != b, b != c);//05¹ø ´ä*/
	/*int a, b,c;
	scanf("%d %d", &a, &b);
	printf("a = %d, b = %d, c = %d", a, b, ++a + b--);//04¹ø ´ä*/
	/*int h;
	float w;
	char n;
	printf("Å°¸¦ ÀÔ·ÂÇÏ¼¼¿ä. ");
	scanf("%d", &h);
	printf("¸ö¹«°Ô¸¦ ÀÔ·ÂÇÏ¼¼¿ä. ");
	scanf("%f", &w);
	printf("ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä. ");
	scanf(" %c", &n);

	printf("Å° = %d \n¸ö¹«°Ô = %.1f \nÀÌ¸§ = %c", h, w, n);//08¹ø ´ä*/
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
}*///13¹ø ´ä


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
}*///12¹ø
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
}*///10¹ø ´ä

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
}*///11¹ø ´ä
/*int main()
{
	int n = 0, j = 0;
	scanf("%d", &n);
	int x = 0, y = n * 4;
	for (int i = 0; i <= n-2; i++) {
		x = x + 2;
		y = y - 2;
		for (j = 0; j <= n * 2; j++) {//jÀÇ °ªÀ» 10À¸·Î, ¹üÀ§¸¦ 0ÀÌ»óÀ¸·Î, j-1 ÇÏ¸é ´ï
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
		for (j = 0; j <= n * 2; j++) {//jÀÇ °ªÀ» 10À¸·Î, ¹üÀ§¸¦ 0ÀÌ»óÀ¸·Î, j-1 ÇÏ¸é ´ï
			if (j > o / 2 && j < p / 2) {
				printf("*");
			}
			else
				printf(" ");
		}printf("\n");
	}
}*///9¹ø ´ä

/*int main()
{
	int n = 0, j = 0;
	scanf("%d", &n);
	int o = 0, p = n * 4;
	for (int i = 0; i < n; i++) {
		o = o + 2;//³¡ºÎºÐ º° À§Ä¡
		p = p - 2;//¾ÕºÎºÐ º° À§Ä¡
		for (j = 0; j <= n * 2; j++) {
			if (j < o / 2 || j > p / 2) {
				printf("¡Ù");//¾ÕºÎºÐ º° À§Ä¡¿¡¼­ ³¡ºÎºÐ º° À§Ä¡±îÁö º° Âï±â
			}
			else if (j == n);//Áß¾Ó °ø¹é ¹æÁö
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
				printf("¡Ù");
			}
			else if (j == n);
			else
				printf("  ");
		}printf("\n");
	}
}*///8¹ø ´ä
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
}*///7¹ø ´ä
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
}*///5¹ø ´ä
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
}*///6¹ø ´ä
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
}*///1¹ø ´ä
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
}*///4¹ø ´ä
/*int main()
{
	int n = 0, j = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (j = n; j >= 0; j--) {//jÀÇ °ªÀ» 10À¸·Î, ¹üÀ§¸¦ 0ÀÌ»óÀ¸·Î, j-1 ÇÏ¸é ´ï
			if (i >= j)
				printf("*");
			else
				printf(" ");
		}printf("\n");
	}
}*///2¹ø
/*int main()
{
	int n = 0, j = 0;
	scanf("%d", &n);
	for (int i=0; i < n; i++) {
		for (j = n; j >=0 ; j--) {//jÀÇ °ªÀ» 10À¸·Î, ¹üÀ§¸¦ 0ÀÌ»óÀ¸·Î, j-1 ÇÏ¸é ´ï
			if (i <= j)
				printf("*");
			else
				printf(" ");
		}printf("\n");
	}
	printf("*");
}*///3¹ø


/*int main() {
	int num = 0;
	while (1) {
		if (num >= 5)
			break;
		printf("while ³»ºÎ ½ÇÇà : %d \n", num);
		num++;
	}
}*/


/*int main()
{
	int a,b=0;
	while (b==0) {
		scanf("%d %d", &a,&b);
		if (a % 2 == 0)
			printf("Â¦¼ö\n");
		else
			printf("È¦¼ö\n");
		if (b != 0)//b·Î ¹Ýº¹¿©ºÎ ÆÇ´Ü
			break;
	}
}*/


/*int main()
{
	int a,b;
	int q=0, w = 0, e = 0;
	printf("ÀÔ·Â : ");
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