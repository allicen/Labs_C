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

int minValue(int a, int b) {
	if (a <= b) {
		return a;
	}
	
	return b;
}

char compareValue(int a, int b) {
	if (a < b) {
		return '<';
	} else if (a == b) {
		return '=';
	}
	
	return '>';
}

int numberPow(int num, int pow) {
	if (pow > 0)  {
		return num * numberPow(num, pow - 1);
	}
	return 1;
}


int main(void) {
	
	// 1 задание 
	printf("Минимальное значение из minValue: %d\n", minValue(50, 5));
	
	// 2 задание
	printf("Результат сравнения в compareValue: %c\n", compareValue(2, 5));
	
	// 3 задание
	printf("Результат возведения в степень в numberPow: %d\n", numberPow(2, 4));
	
	
	return 0;
}