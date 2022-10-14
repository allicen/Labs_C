/*
-D __USE_MINGW_ANSI_STDIO 
-fexec-charset=CP866
-O2
-Wall
-Wextra
-pedantic
-s
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void task10() {
	float price;
	int n, m;
	printf("Сколько стоит грамм докторской колбасы на черном рынке? (ответ введите в виде десятичной дроби, максимум 2 знака после запятой, разделитель - точка): ");
	scanf("%f", &price);
	
	n = (int) price;
	m = (int) (price * 100) % 100;
 
	printf("Колбаса стоит %d руб. %d коп.", n, m);
}

void task11() {
	srand(time(NULL));
	int num, mark = 2, n = 2 + rand() % 8, m = 2 + rand() % 8;
	printf("Сколько будет %d X %d = ", n, m);
	scanf("%d", &num);
	
	if (n * m == num) {
		mark = 5;
	}
	
	printf("Ваша оценка: %d", mark);
}

void task12() {
	int num;
	printf("Через сколько минут минимум вы достигните поверхности Седны, если отправитесь в полет в 2029 году?");
	scanf("%d", &num);
	
	printf("Ваш ответ: %d ч. %d м. Вы точно хотите отправиться на Седну?", num / 60, num % 60);
}


int main(void) {
	
	//  1 task
	//  10 / 3 = 3 	
	//  2.5 / 5 = 0.5
	//  11 % 7 = 4
	//  5 % 15 = 5
	//  6 > 10 = 0 (false)
	//  8 >= 8 = 1 (true)
	//  5 != 5 = 0 (false)
	//  3 & 1 = 1 (true)
	//  4 | 1 = 5
	//  2 << 2 = 8
	//  60 >> 1 = 30
	
	// 2 task
	// n - любое число
	// n % 8 == 0

	// 3 task
	// ++m - 3 = 1
	
	// 4 task
	// если x = 4, y = 4, то ++x + y-- = 9
	
	// 5 task
	// m - любое число
	// узнать 5й разряд: m % 100000 / 10000
	
	// 6 task
	// m - любое число
	// занести 0 в 3й разряд: m / 1000 * 1000 + m % 100
	
	// 7 task
	// m - любое число
	// занести 1 в 4й разряд: m / 10000 * 10000 + 1000 + m % 1000;
	
	// 8 task
	// 1+8/2*2 = 9
	
	// 9 task
	// 10 >> 2 + 4/2 - 3 << 2 = 20

	task10();
	task11();
	task12();
	
	return 0;
}