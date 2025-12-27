#ifndef _LIST_H
#define _LIST_H

struct listitem {
    int number;
    char name[80];
    struct listitem *next;
};

typedef struct listitem *List;

int initlist(List *); /* инициализация списка пустым содержимым */
int insertfront_by_number(List *, int val); /* вставка в начало списка */
int insertback_by_number(List *, int val); /* вставка в конец списка */
int insertfront_by_name(List *, char* str); /* вставка в начало списка */
int insertback_by_name(List *, char* str); /* вставка в конец списка */
int isempty(List *); /* проверяет, является ли список пустым */
int length(List); /* определение длины списка */
int destroyItem(List *, List); /* удаление заданного узла node из списка */
struct listitem* getitem_by_number(List, int n); /* нахождение узла по number */
struct listitem* getitem_by_name(List, char* str); /* нахождение узла по name */

#endif /* _LIST_H */