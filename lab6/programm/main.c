#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void task_1() {
	float x = 2.45f;
	printf("1 task: \nx = %f\n\n", x);
}

void task_2() {
	int y = 20;
	y -= 10;
	
	printf("2 task: \ny = %d\n\n", y);
}

void task_3(int a1, int a2) {
	double res = (a1 + a2) / 2;
	
	printf("3 task: \nres = %f\n\n", res);
}

void task_4(int x) {
	double y;
	y = -3.67 * x*x*x - 0.45 * x*x + 12.8;
	
	printf("4 task: \nres = %f\n\n", y);
}

void task_5() {
	printf("5 task: \nRubleva \nElena \nAlekseevna\n\n");
}

void task_6() {
	printf("6 task: \nC://NC/README.TXT \n\n");
}

void task_7(unsigned int count) {
	printf("7 task: \ncount = %d\n\n", count);
}

void task_8(char ch) {
	printf("8 task: \nch = %c\n\n", ch);
}

void task_9(float L, float H) {
	printf("9 task: \n");
	printf("L = %.2f\n", L); // Длина
	printf("H = %.2f", H);   // Высота
	printf("\n\n");
}

void task_10() {
	char ch;
	printf("10 task: \nInput one symbol: ");
	scanf("%c", &ch);
	printf("Symbol = %c \n\n", ch);
}

void task_11() {
	int a, b;
	printf("11 task: \nInput a: ");
	scanf("%d", &a);
	printf("Input b: ");
	scanf("%d", &b);
	printf("a = %d\nb = %d\n\n", a, b);
}

void task_12(double r) {
	double l = 2 * M_PI * r;
	double s = M_PI * pow(r, 2);
	
	printf("12 task: \nl = %f\n s = %f\n\n", l, s);
}

void task_13(int a, int b) {
	int p = 2 * (a + b);
	int s = a * b;
	
	printf("13 task: \np = %d\ns = %d\n\n", p, s);
}

void task_14(int r, int h) {
	double v = M_PI * pow(r, 2) * h;
	printf("14 task: \nv = %f\n\n", v);
}

int main(void) {
	task_1();
	task_2();
	task_3(10, 20);
	task_4(1);
	task_5();
	task_6();
	task_7(123);
	task_8('a');
	task_9(10.235454, 12.5441);
	task_10();
	task_11();
	task_12(1);
	task_13(1, 2);
	task_14(1, 25);

	return 0;
}