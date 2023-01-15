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
typedef struct _BOOK {
    int id;
    char writer[100];
    char name[100];
    short year;
    char publisher[100];
    struct _BOOK* next; 
} book;

// 2 задание
typedef struct _ACTOR {
    char firstName[100];
    char secondName[100];
    char country[100];
} actor;

typedef struct _FILM {
    char name[100];
    char director[50];
    struct _ACTOR actors[10];
    short year;
} Film;

// 3 задание
typedef union INT {
    struct {
        char a0;
        char a1;
        char a2;
        char a3;
    } bytes;
    int c;
} intBytes;

// 4 задание
typedef enum _MONTH {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
} month;

void push(book** headRef, int id) {
    printf("Книга %d\n", id);
    
    char name[100];
    char publisher[100];
    char writer[100];
    short year;
    
    printf("Название: ");
    scanf("%s", &name);
    
    printf("Автор: ");
    scanf("%s", &writer);
    
    printf("Издательство: ");
    scanf("%s", &publisher);
    
    printf("Год издания: ");
    scanf("%hd", &year);
    
    book* newBook = (struct book*)malloc(sizeof(book));
    scanf("%s", &newBook->writer);
    scanf("%s", &newBook->name);
    scanf("%s", &newBook->publisher);
    newBook->year = year;
    newBook->id = id;
    newBook->next = *headRef;
    *headRef = newBook;
}

book* constructList(int keys[], int n) {
    book* head = NULL;
 
    for (int i = n - 1; i >= 0; i--) {
        push(&head, keys[i]);
    }
 
    return head;
}

void printList(book* head) {
    book* ptr = head;
    while (ptr) {
        printf("%d. Книга: %s, автор: %s, год издания: %d, издательство: %s.\n", ptr->id, ptr->name, ptr->writer, ptr->year, ptr->publisher); 
        ptr = ptr->next;
    }
}

int main(void) {

    // 6 задание
    printf("Сколько хотите добавить новых книг?");
    int n;
    scanf("%d", &n);
    int keys[n];
    
    for (int i = 0; i < n; i++){
        keys[i] = i;
    }
    
    book* head = constructList(keys, n);
    printList(head);
    
    return 0;
}
