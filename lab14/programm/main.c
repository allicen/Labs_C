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
        unsigned a0 : 8;
        unsigned a1 : 8;
        unsigned a2 : 8;
        unsigned a3 : 8;
    } bytes;
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

void push(struct _BOOK** headRef, int id) {
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
    scanf("%d", &year);
    
    struct _BOOK* newBook = (struct book*)malloc(sizeof(struct _BOOK));
    strcpy(newBook->writer, writer);
    strcpy(newBook->name, name);
    strcpy(newBook->publisher, publisher);
    newBook->year = year;
    newBook->id = id;
    newBook->next = *headRef;
    *headRef = newBook;
}

struct _BOOK* constructList(int keys[], int n) {
    struct _BOOK* head = NULL;
 
    for (int i = n - 1; i >= 0; i--) {
        push(&head, keys[i]);
    }
 
    return head;
}

void printList(struct _BOOK* head) {
    struct _BOOK* ptr = head;
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
    
    struct _BOOK* head = constructList(keys, n);
    printList(head);
    
    return 0;
}
