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

void task1() {
    int num, arrSize = 5, nonZeroCount = 0;
    int arr[arrSize];
    
    for (int i = 0; i < arrSize; i++) {
        scanf("%d", &num);
        arr[i] = num;
        if (num != 0) nonZeroCount++;
    }
    
    printf("Количество ненулевых элементов в массиве: %d", nonZeroCount);
}


void task2() {
    int num, arrSize = 5, sum = 0, count = 0;
    float average;
    
    for (int i = 0; i < arrSize; i++) {
        scanf("%d", &num);
        
        if (num != 0) {
            count++;
            sum += num;
        }        
    }
    
    average = (float) sum / count;
    
    printf("Среднее арифметическое: %f", average);
}


void task3() {
    int arr[10] = {1, 9, 2, 8, 3, 7, 4, 6, 5, 0};
    int num;
    printf("Введите число от 0 до 9 и узнайте его положение в массиве: ");
    scanf("%d", &num);
    
    for (int i = 0; i < 10; i++) {
        if (num == arr[i]) {
            printf("Номер позиции: %d", i+1);
            break;
        }
        
        if (i == 9) {
            printf("Введено некорректное число.");
        }
    }
}


int task4() {
    int arr[3] = {1, 50, 10};
    
    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            continue;
        }
        
        if (arr[i-1] > arr[i]) {
            return 1;
        }
    }
    return 0;
}


void task5() {
    int arr[10] = {1, 1, 1, 5, 7, 5, 7, 6, 20, 8};
    int numCount = 0, numMax = 0;
    
    for (int i = 0; i < 10; i++) {
        if (numMax < arr[i]) {
            numMax = arr[i];
        }
    }
    
    int arrNumCountSize = numMax + 1;
    int arrNumCount[arrNumCountSize];
    
    for (int i=  0; i < arrNumCountSize; i++) {
        arrNumCount[i] = 0;
    }
    
    for (int i = 0; i < 10; i++) {
        int count = arrNumCount[arr[i]];
        arrNumCount[arr[i]] = count + 1;
    }
    
    for (int i=  0; i < arrNumCountSize; i++) {
        if (arrNumCount[i] != 0) {
            numCount++;
        }
    }
    
    printf("Количество различных чисел в массиве: %d", numCount);
}


void task6() {
    int arr[5][4] = {
        {1, 5, 0, 4},
        {2, 50, 4, 4},
        {10, 5, 7, 4},
        {1, 5, 0, 40},
        {1, 45, 0, 4},
    };
    int sumCol[4] = {0};
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++){
            sumCol[j] += arr[i][j];
        }
    }
    
    for (int i = 0; i < 4; i++) {
        printf("Сумма столбца %d: %d\n", i, sumCol[i]);
    }
}


void task7() {
    int arr[5][5] = {
        {1, 5, 0, 4, 7},
        {2, 5, 4, 4, 1},
        {10, 5, 7, 4, 6},
        {1, 5, 0, 40, 4},
        {1, 45, 0, 4, 7},
    };
    
    int numRow = 0, maxSum;
    
    for (int i = 0; i < 5; i++) {
        
        int sum = 0;
        
        for (int j = 0; j < 4; j++){
            sum += arr[i][j];
        }
        
        if (i == 0) {
            maxSum = sum;
        } else if (maxSum < sum) {
            numRow = i;
            maxSum = sum;
        }
    }
    
    printf("Максимальная сумма в строке: %d", numRow+1);
}


void task8() {
    char str[100];
    printf("Введите строку: ");
    
    fgets(str, 100, stdin);
    fflush(stdin);
    
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {     
        if (str[i] == '\n') {
            break;
        }
        
        count++;
    }

    printf("В строке %llu символов.", count);
}


void task9() {
    printf("Введите строку английскими буквами: ");
    
    int ch;
    while ((ch = getchar())) {
        if ('a' <= ch && ch <= 'z') {
            ch += 'A' - 'a';
        }
        putchar (ch);
    }
}


void task10() {
    char str[100] = "";
    int startStr = 0, finishStr = 0;
    printf("Введите строку: ");
    
    fgets(str, 100, stdin);
    fflush(stdin);
    str[strcspn(str, "\n")] = '\0';  
    
    int len = (int)strlen(str), indexStart = 0, indexFinish = len;
    
    for (int i = 0; i < len; i++) {
        if (!startStr && str[i] == ' ') {
            indexStart++;
            continue;
        } 
        
        if (!startStr) {
            startStr = 1;
        }
        
        if (!finishStr && str[i] == ' ') {
            finishStr = 1;
            indexFinish = i;
        } else if (str[i] != ' ') {
            finishStr = 0;
            indexFinish = len;
        }
    }
    
    int lenRes = indexFinish - indexStart;
    char res[lenRes + 1];
    
    int indexRes = 0;
    for (int i = indexStart; i < indexFinish; i++) {
        res[indexRes] = str[i];
        indexRes++;
    }
    
    res[lenRes] = '\0';

    printf("Получившаяся строка: %s, длина = %d", res, lenRes);
}


void task11() {
    char str[100];
    int num;
    printf("Введите строку: ");
    
    scanf("%s", str);
    
    if (atoi(str)) {
        num = atoi(str);
        printf("%d - целое десятичное число.", num);
    } else {
        printf("%s - не целое десятичное число.", str);
    }
}


void task12() {
    char str[100];
    printf("Введите строку: ");
    
    scanf("%s", str);
    
    if (atoi(str)) {
        int byteType = 1;
        
        for (int i = 0; i < (int)strlen(str); i++) {
            if (!(str[i] == '0' || str[i] == '1')) {
                byteType = 0;
                break;    
            }
        }
        
        if (byteType) {
            printf("%s - двоичное число.", str);
        } else {
            printf("%s - не является двоичным числом.", str);
        }

    } else {
        printf("%s - не является двоичным числом.", str);
    }
}


void task13() {
    char str[100];
    printf("Введите строку: ");
    
    scanf("%s", str);
    
    int byteType = 1;
    for (int i = 0; i < (int)strlen(str); i++) {
        if (!((str[i] >= '0' && str[i] <= '9') || 
              (str[i] >= 'a' && str[i] <= 'f') ||
              (str[i] >= 'A' && str[i] <= 'F'))) {
            byteType = 0;
            break;    
        }
    }
    
    if (byteType) {
        printf("%s - шестнадцатеричное число.", str);
    } else {
        printf("%s - не является шестнадцатеричным  числом.", str);
    }
}


int main(void) {
    
    // 1 задание
    task1();
    
    // 2 задание
    task2();
    
    // 3 задание
    task3();
    
    // 4 задание
    int res = task4();
    if (res) {
      printf("Массив не упорядочен по возрастанию.");
  } else {
      printf("Массив упорядочен по возрастанию.");
  }
    
    
    // 5 задание
    task5();
    
    // 6 задание
    task6();
    
    // 7 задание
    task7();
    
    // 8 задание
    task8();
    
    // 9 задание
    task9();
    
    // 10 задание
    task10();
    
    // 11 задание
    task11();
    
    // 12 задание
    task12();
    
    // 13 задание
    task13();
    
    
    return 0;
}