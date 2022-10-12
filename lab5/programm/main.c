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
	
	/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
	int main(void) {	
	
	//1.	Запишите предложение декларации переменной x, в которой будут храниться числа в диапазоне от 10 до 60000.
	unsigned short int x;
	
	//2.	Запишите предложение декларации переменной y, в которой будут храниться числа 0 или 1 и проинициализируйте ее 0.
	short int y = 0;
	
	//3.	Запишите предложение декларации переменной n, которая будет использоваться в программе для подсчета количества и принимать максимальное значение 15000.
	int n;
	
	//4.	Запишите предложение декларации переменной x и y, в которых будут храниться числа c плавающей точкой двойной точности и проинициализируйте их 0.
	double x2 = 0, y2 = 0;
	
	//5.	Запишите предложение декларации переменной c, в которой будут храниться коды символов и проинициализируйте ее кодом символа A.
	char c = 'A';
	
	//6.	Сколько байт будут занимать следующие константы: 5, 2.5, 43L, 123UL, 12LL, 3.45L, 5.2F.
	
	printf("5 =  4 bytes, type int\n");
	printf("2.5 = 8 bytes, type double\n");
	printf("43L = min 4 bytes, type long int\n");
	printf("123UL = min 4 bytes, type unsigned long int\n");
	printf("12LL = 8 bytes, type long long int\n");
	printf("3.45L = usually 10, 12, 16 bytes, type long double\n");
	printf("5.2F = 4 bytes, type float\n");
	
	return 0;
}