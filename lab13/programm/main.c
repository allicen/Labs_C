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
        free(arrSort);
    }
	
	
	// 3 задание
	
	// 4 задание
	
	// 5 задание
	
	// 6 задание
	
	// 7 задание
	
	// 8 задание
	
	
	
	return 0;
}