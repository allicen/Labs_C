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
#include <locale.h>
#include <string.h>

#define FILENAME "user_file.txt"
#define READ_FILE "input.txt"
#define WRITE_FILE "output.txt"


void fileCopy() {
    FILE *fp, *fw;
    fp = fopen(READ_FILE, "r");
    fw = fopen(WRITE_FILE, "w");
    char s[30];
    
    while (fgets(s, 30, fp) != NULL) {
        fputs(s, fw);
        printf("%s", s);
    }
    
    fclose(fp);
    fclose(fw);
}

void fileCopyTwo() {
    FILE *fp, *fw;
    fp = fopen(READ_FILE, "r");
    fw = fopen(WRITE_FILE, "w");
    
    char buffer[1024*1024];
    size_t bytes;

    while (0 < (bytes = fread(buffer, 1, sizeof(buffer), fp))) {
        fwrite(buffer, 1, bytes, fw);
    }
}

char* RUS(char* text) {   
    char *buf = (char*) malloc(strlen(text)+1);
    OemToCharA(text, buf);
    return buf;
}

void numFunctions(char type) {
    
    printf("Введите 10 чисел через пробел: ");
    int numCount = 10;
    int num = 0, sum = 0, min = 0, max = 0;
    float average; 
    int arr[numCount];
    
    for(int i = 0; i < numCount; i++) {
        scanf("%d", &num);
        sum += num;
        arr[i] = num;
        
        if (i == 0) {
            min = num;
            max = num;
            continue;
        } 
        
        if (i > 0 && num < min) {
            min = num;
        } 
        
        if (i > 0 && num > max) {
            max = num;
        }
    }
    
    average = (float) sum / numCount;

    FILE *fw;
    
    if (type == 'b') {
        fw = fopen(WRITE_FILE, "wb");
    } else {
        fw = fopen(WRITE_FILE, "wt");
    }
    
    if(fw != NULL) {
        printf("%s", "Введены числа: ");
        
        for (int i = 0; i < numCount; i++) {
            fprintf(fw, "%d ", arr[i]);
            printf("%d ", arr[i]);
        }
        fprintf(fw, "%s", "\n");
        printf("%s", "\n");
        
        fprintf(fw,"%s%f\n", RUS("Среднее арифметическое: "), average);
        fprintf(fw,"%s%d\n", RUS("Минимум: "), min);
        fprintf(fw,"%s%d\n", RUS("Максимум: "), max);
        fprintf(fw,"%s%d\n", RUS("Сумма: "), sum);
        
        printf("%s%f\n", "Среднее арифметическое = ", average);
        printf("%s%d\n", "Минимум = ", min);
        printf("%s%d\n", "Максимум = ", max);
        printf("%s%d\n", "Сумма = ", sum); 
        
        fclose(fw);
    }
}

int fileRead(char type, int *arr, int *sum, int *min, int *max, float *average) {
    FILE *fr;
    
    if (type == 'b') {
        fr = fopen(WRITE_FILE, "rb");
    } else {
        fr = fopen(WRITE_FILE, "rt");
    }
    
    if (!fr) {
        return 1;
    }
    
    int lineIndex = 0;
    
    char line[100]; 
    
    while(fgets(line, 100, fr) != NULL) {
        char *lineTmp;
        if (lineIndex == 0) {
            
            lineTmp = strtok(line, " ");
                
            int index = 0;
            while (lineTmp != NULL) {
                arr[index] = atoi(lineTmp);
                lineTmp = strtok (NULL, " ");
                index++;
            }
            
        } else {
            lineTmp = strtok (line, ": ");
                
            int index = 0;
            while (lineTmp != NULL) {
                if (index && lineIndex == 1) {
                    *average = atof(lineTmp);
                } else if (index && lineIndex == 2) {
                    *min = atoi(lineTmp);
                } else if (index && lineIndex == 3) {
                    *max = atoi(lineTmp);
                } else if (index && lineIndex == 4) {
                    *sum = atoi(lineTmp);
                }
                lineTmp = strtok (NULL, ": ");
                index++;
            }
        }

        lineIndex++;
    }

    fclose(fr);
    
    return 0;
}

int main(void) {
    
    int size = 10;
    int arr[size];
    int sum = 0, min = 0, max = 0;
    float average;
    int res;
    
    // 1 задание
    fileCopy();
    
    // 2 задание
    fileCopyTwo();
    
    // 3 задание
    numFunctions('t');
    
    // 4 задание
    numFunctions('b');
    
    // 5 задание
    res = fileRead('t', arr, &sum, &min, &max, &average);
    
    // 6 задание
    res = fileRead('b', arr, &sum, &min, &max, &average);

    if (res) {
        printf("При обработке файла возникла ошибка\n");
    } else {
        printf("%s", "В файле были записаны числа: ");
        
        for (int i = 0; i < 10; i++) {
            printf("%d ", arr[i]);
        }

        printf("%s", "\n");
        
        printf("%s%f\n", "Среднее арифметическое = ", average);
        printf("%s%d\n", "Минимум = ", min);
        printf("%s%d\n", "Максимум = ", max);
        printf("%s%d\n", "Сумма = ", sum); 
    }
    
    return 0;
}