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
#define SQUARE(num) ((num)*(num))

// 6 задание
#define SWAP(a, b) a ^= b ^= a ^= b

// 7 задание
#define ROW_COUNT 10
#if ROW_COUNT < 0
	#define TABLE_WIDTH 0
#elif ROW_COUNT < 6
	#define TABLE_WIDTH 5
#elif ROW_COUNT >= 6 && ROW_COUNT < 9
	#define TABLE_WIDTH 6
#else
	#define TABLE_WIDTH 10
#endif

// 8 задание
// Если константа TEST не определена, то определить констранту TEST


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
	printf("Ширина таблицы = %d", TABLE_WIDTH);
	
	return 0;
}