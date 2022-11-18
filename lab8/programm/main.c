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
#include <math.h>


void task1() {
    int x;
    float y;
    printf("Введите число x: ");
    scanf("%d", &x);
    if (x != 0) {
        y = (float) 1/x;
        printf("у = %f", y);
    } else {
        printf("x не может быть равен 0");
    }
}


void task2() {
    char str[] = "kdjfksdjh", ch;
    unsigned char i = 0;
    printf("%s\n", str);
    while((ch = str[i++])) {
        if (ch != '\n') {
            putchar(ch);
        }
    }    
}

void task3() {
    for(int i = 0; i < 10; i++) {
        printf("Hello World\n");
    }
}


void task4() {
    int a, b, c, d;
    float x1, x2;
    printf("Введите коэффициент a: ");
    scanf("%d", &a);
    
    printf("Введите коэффициент b: ");
    scanf("%d", &b);
    
    printf("Введите коэффициент c: ");
    scanf("%d", &c);
    
    d = pow(b, 2) - 4 * a * c;
    
    if (a == 0 || d < 0) {
        printf("Ошибка! A не может быть равно 0, D не может быть меньше 0.");
        
    } else if (d == 0){
        x1 = -b / 2 * a;
        printf("Корень квадратного уравнения: x = %f", x1);
    } else {
        x1 = (-b - pow(d, 0.5)) / 2 * a;
        x2 = (-b + pow(d, 0.5)) / 2 * a;
        
        printf("Корни квадратного уравнения: x1 = %f, x2 = %f", x1, x2);
    }
}


void task5() {
    int n;
    scanf("%d", &n);
    
    if (n % 2 == 0) {
        printf("Число четное");
    } else {
        printf("Число нечетное");
    }
}


void task6() {
    int count = 0, n = 0, sum = 0;
    float average = 0.0;
    
    printf("Вводите целые числа, в конце последовательности поставьте 0.\n");
    
    while(1) {
        scanf("%d", &n);
        
        if (n != 0) {
            sum += n;
            count++;
        } else {
            if (count > 0) {
                average = (float) sum / count;
            }
            break;
        }
    }
    
    printf("Сумма: %d, среднее арифметическое: %f", sum, average);
}


void task7() {
    int day;
    printf("Введите номер дня недели: ");
    scanf("%d", &day);
    
    if (day > 0 && day < 6) {
        printf("Рабочий день");
    } else if (day == 6) {
        printf("Суббота");    
    } else if (day == 7) {
        printf("Воскресение");
    } else {
        printf("Введено некорректное значение.");
    }    
}


void task8() {
    int day;
    printf("Введите номер дня недели: ");
    scanf("%d", &day);
    
    switch(day) {
        case (1):
            printf("Понедельник");
            break;
        case (2):
            printf("Вторник");
            break;
        case (3):
            printf("Среда");
            break;
        case (4):
            printf("Четверг");
            break;
        case (5):
            printf("Пятница");
            break;
        case (6):
            printf("Суббота");
            break;    
        case (7):
            printf("Воскресение");
            break;
        default:
            printf("Введено некорректное значение.");                            
    }
}


void task9() {
    char str[20];
    printf("Введите время в формате ЧЧ:ММ:СС: ");
    scanf("%s", str);
    
    int secCount = 0, error = 0;
    int start = 3600, step = 60;
    
    char sep[10]=":";
    char *substr;
    substr = strtok(str, sep);
    
    while (substr != NULL) {
        
        int num = atoi(substr);
        
        if (num >= 60 || num < 0) {
            error = 1;
            break;
        }
        
        secCount += num * start;
        start /= step;
    
        substr = strtok(NULL, sep);
    }
    
    if (error || start > 0) {
        printf("Введены некорректные данные.");
    } else {
        printf("Общее количество секунд: %d", secCount);
    }
}


void task10() {
    int num = 2;
    printf("2 в 0 степени = 1\n");
    for (int i = 1; i <= 10; i++) {
        printf("2 в %d степени = %d\n", i, num);
        num *= 2;
    }
}


void task11() {
    int sum = 0, count = 10;
    for(int i = 0; i < count; i++){
        int num = (rand() % count) + 1;
        printf("Число №%d = %d\n", i+1, num);
        sum += num;
    }
    
    float average = (float)sum / count;
    printf("Среднее арифметическое: %f", average);
}


void task12() {
    int a, b;
    long long res;
    printf("Введите число: ");
    scanf("%d", &a);
    printf("Введите степень: ");
    scanf("%d", &b);
    
    res = pow(a, b);
    printf("a ^ b = %llu", res);
}


int main(void) {
    
    
    // 1 задание
    task1();
    
    // 2 задание
    task2();
    
    // 3 задание
    task3();
    
    // 4 задание
    task4();
    
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
    
    return 0;
}
