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
#include <string.h>
#include <ctype.h>

int max(int *arr, int size) {
    int max = 0;
    
    for (int i = 0; i < size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

void sort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}


void minMax(int *arr, int size, int *min, int *max) {    
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            *min = arr[i];
            *max = arr[i];
            continue;
        }
        
        if (arr[i] < *min) {
            *min = arr[i];
        } else if (arr[i] > *max) {
            *max = arr[i];
        }
    }
} 



int rowMaxValueNymber(void *table, int rowCount, int colCount) {
    
    int rowWithMax = 0, maxNum = 0, (*pmas)[colCount] = table;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {

            if (i == 0 && j == 0) {
                maxNum = pmas[i][j];
                continue;
            }
            
            if (pmas[i][j] > maxNum) {
                maxNum = pmas[i][j];
                rowWithMax = i;
            }
        }
    }
    
    return rowWithMax;
}


int* sumColumns(void *table, int rowCount, int colCount) {
    int *arrSum = malloc(colCount * sizeof(int));
    int (*pmas)[colCount] = table;
    
    if (!arrSum) {
        return NULL;
    }
    
    for (int i = 0; i < rowCount; i++) {
        int sum = 0;
        for (int j = 0; j < colCount; j++) {
            sum += pmas[i][j];
        }
        arrSum[i] = sum;
    }
    
    return arrSum;
}


char* removeSubstring(char* str, int startIndex, int charCount) {
    if ((int)strlen(str) < (startIndex + charCount)) {
        return NULL;
    }
    
    int substringLen = strlen(str) + 1;
    char *substring = malloc(substringLen * sizeof(char));
    
    int index = 0;
    for (int i = 0; i < (int)strlen(str); i++) {
        
        if (i < startIndex) {
            substring[index] = str[i];
            index++;
        } else if (i > startIndex && i <= (startIndex + charCount)) {
            continue;
        } else {
            substring[index] = str[i];
            index++;
        }
    }
    
    substring[index] = '\0';
    
    return substring;
}


char* enCharToUpperCase(char* str) {
    char *strUpdate = malloc(strlen(str) * sizeof(char)) + 1;
    if (strUpdate) {
        for (int i = 0; i < (int)strlen(str); i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                strUpdate[i] = str[i] + ('A' - 'a');
            } else {
                strUpdate[i] = str[i];
            }
        }
    }
    
    strUpdate[(int)strlen(str)] = '\0';
    
    return strUpdate;
}


int strContainNumber(char* str) {
    
    for (size_t i = 0; str[i] && str[i] != '\n'; i++) {
        
        if (str[i] > '0' && str[i] < '9') {
            return 1;
        }
    }
    
    return 0;
}


int main(void) {
    int arr[] = {2, 5, 7, 6, 0, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    // 1 ??????????????
    int maxArr = max(arr, n);
    printf("1. ???????????????????????? ?????????? ?? ?????????????? arr: %d\n", maxArr);
    
    
    // 2 ??????????????
    sort(arr, n);
    if (arr) {
        printf("2. ?????????????????????????????? ???????????? arr: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    
    
    // 3 ??????????????
    int min, max;
    minMax(arr, n, &min, &max);
    printf("3.1. ?????????????????????? ?????????? ?? ?????????????? arr: %d\n", min);
    printf("3.2. ???????????????????????? ?????????? ?? ?????????????? arr: %d\n", max);

    
    
    // 4 ??????????????
    int table[][4] = {{1, 2, 5, 600}, {5, 8, 9, 1000}, {9000, 8, 1, 7}};
    int tableRowCount = sizeof(table)/sizeof(table[0]);
    int rowNumberWithMaxNumber = rowMaxValueNymber(table, tableRowCount, 4);
    printf("4. ???????????????????????? ?????????? ???????????????????? ?? ???????????? ???%d\n", rowNumberWithMaxNumber);
    
    
    // 5 ??????????????
    int *sumColumnsTable = sumColumns(table, tableRowCount, 4);
    if (sumColumnsTable) {
        printf("5. ?????????? ???? ????????????????: ");
        
        for (int i = 0; i < tableRowCount; i++) {
            printf("%d ?????????????? = %d ", i+1, sumColumnsTable[i]);
        }
        
        printf("\n");
        free(sumColumnsTable);
    }
    
    
    // 6 ??????????????
    char str[] = "kzhdfkjs 10";
    char *subString = removeSubstring(str, 10, 5);
    if (subString) {
        printf("6. ?????????? ????????????: %s\n", subString);
        free(subString);
    }
    
    
    // 7 ??????????????
    char strTwo[] = "???????????? ???????????? string ???????????? test";
    char *strToUpper = enCharToUpperCase(strTwo);
    if (strToUpper) {
        printf("7. ?????????? ????????????: %s\n", strToUpper);
        free(strToUpper);
    }
    
    
    // 8 ??????????????
    int strContainNum = strContainNumber(str);
    printf("8. ???????????? ???????????????? ??????????: %s\n", strContainNum ? "????" : "??????");
    
    return 0;
}