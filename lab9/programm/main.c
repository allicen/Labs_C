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
// 1 задание
#include "my.h"

// 2 задание
#define NUM 3.1415

// 3 задание
#define TRUE 1
#define FALSE 0

// 4 задание
#define ROW 10
#define COL 20

// 5 задание
#define SQUARE(num) NUM*NUM

// 6 задание
#define SWAP(a, b) a ^= b ^= a ^= b

// 7 задание
#define TABLE_WIDTH(n) n >=0 && n <=5 ? 5 : n > 5 && n <=8 ? 6 : 10

// 8 задание
// Если TEST не определен, то определить констранту TEST


int main(void) {
	
	// 5
	int num, squareRes;
	printf("Введите число для возведения в квадрат: ");
	scanf("%d", &num);
	squareRes = SQUARE(num);
	printf("Результат: %d", squareRes);
	
	// 6
	int a, b;
	printf("Введите 2 числа для обмена: ");
	scanf("%d", &a);
	scanf("%d", &b);
	SWAP(a, b);
	printf("a = %d, b = %d", a, b);

	// 7
	int countRow;
	printf("Введите количество строк в таблице: ");
	scanf("%d", &countRow);
	printf("Ширина таблицы = %d", TABLE_WIDTH(countRow));
	
	return 0;
}