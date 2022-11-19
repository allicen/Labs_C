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

int max(int *arr, int size) {
	int max = 0;
	
	for (int i = 0; i < size; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	return max;
}

int* sort(int *arr, int size, int max) {
	int arrSortSize = max + 1;
	int arrSort[arrSortSize];
	
	for (int i = 0; i < arrSortSize; i++) {
		arrSort[i] = 0;
	}
	
	for (int i = 0; i < size; i++) {
		arrSort[arr[i]] = arrSort[arr[i]] + 1;
	}	
	
	int *returnArray = malloc(size * sizeof(int));
	
	if (!returnArray) {
		return NULL;
	}
	
    int index = 0;
	for (int i = 0; i < arrSortSize; i++) {
		for (int j = 0; j < arrSort[i]; j++) {
			returnArray[index] = i;
			index++;
		}
	}
	
	return returnArray;
}


int* minMax(int *arr, int size) {
	int *resMinMax = malloc(2 * sizeof(int));
	
	if (!resMinMax) {
		return NULL;
	}
	
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			resMinMax[0] = arr[i];
			resMinMax[1] = arr[i];
			continue;
		}
		
		if (arr[i] < resMinMax[0]) {
			resMinMax[0] = arr[i];
		} else if (arr[i] > resMinMax[1]) {
			resMinMax[1] = arr[i];
		}
	}
	
	return resMinMax;
} 



int rowMaxValueNymber(int table[][4], int rowCount, int colCount) {
	
	int rowWithMax = 0, maxNum = 0;
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {

			if (i == 0 && j == 0) {
				maxNum = table[i][j];
				continue;
			}
			
			if (table[i][j] > maxNum) {
				maxNum = table[i][j];
				rowWithMax = i;
			}
		}
	}
	
	return rowWithMax;
}


int main(void) {
	int arr[] = {2, 5, 7, 6, 0, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	// 1 задание
	int maxArr = max(arr, n);
	printf("Максимальное число в массиве arr: %d\n", maxArr);
	
	
	// 2 задание
	int *arrSort;
    arrSort = sort(arr, n, maxArr);
    if (arrSort) {
    	printf("Отсортированный массив arr: ");
    	for (int i = 0; i < n; i++) {
			printf("%d ", arrSort[i]);
		}
		printf("\n");
        free(arrSort);
    }
	
	
	// 3 задание
	int *arrMinMax = minMax(arr, n);
	if (arrMinMax) {
		printf("Минимальное число в массиве arr: %d\n", arrMinMax[0]);
		printf("Максимальное число в массиве arr: %d\n", arrMinMax[1]);
		free(arrMinMax);
	}
	
	// 4 задание
	int table[][4] = {{1, 2, 5, 600}, {5, 8, 9, 1000}, {9000, 8, 1, 7}};
	int tableRowCount = sizeof(table)/sizeof(table[0]);
	int rowNumberWithMaxNumber = rowMaxValueNymber(table, tableRowCount, 4);
	printf("Максимальное число содержится в строке №%d\n", rowNumberWithMaxNumber);
	
	
	// 5 задание
	
	// 6 задание
	
	// 7 задание
	
	// 8 задание
	
	
	
	return 0;
}