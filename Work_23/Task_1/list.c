#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Инициализация списка - возвращает 0 при успехе, 1 при ошибке
int initlist(List *head) {
    if (!head) return 1;  // ошибка: неверный указатель
    *head = NULL;
    return 0;  // успех
}

// Вставка в начало по number - возвращает 0 при успехе, 1 при ошибке
int insertfront_by_number(List *head, int val) {
    if (!head) return 1;  // ошибка: неверный указатель
    struct listitem *newNode = (struct listitem*)malloc(sizeof(struct listitem));
    if (!newNode) return 1;  // ошибка: не удалось выделить память
    
    newNode->number = val;
    newNode->name[0] = '\0';
    newNode->next = *head;
    *head = newNode;
    return 0;  // успех
}

// Вставка в конец по number - возвращает 0 при успехе, 1 при ошибке
int insertback_by_number(List *head, int val) {
    if (!head) return 1;  // ошибка: неверный указатель
    struct listitem *newNode = (struct listitem*)malloc(sizeof(struct listitem));
    if (!newNode) return 1;  // ошибка: не удалось выделить память
    
    newNode->number = val;
    newNode->name[0] = '\0';
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return 0;  // успех
    }

    struct listitem *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return 0;  // успех
}

// Вставка в начало по name - возвращает 0 при успехе, 1 при ошибке
int insertfront_by_name(List *head, char* str) {
    if (!head || !str) return 1;  // ошибка: неверные аргументы
    struct listitem *newNode = (struct listitem*)malloc(sizeof(struct listitem));
    if (!newNode) return 1;  // ошибка: не удалось выделить память
    
    newNode->number = 0;
    
    // Копируем строку безопасно
    int i;
    for (i = 0; i < 79 && str[i] != '\0'; i++) {
        newNode->name[i] = str[i];
    }
    newNode->name[i] = '\0';
    
    newNode->next = *head;
    *head = newNode;
    return 0;  // успех
}

// Вставка в конец по name - возвращает 0 при успехе, 1 при ошибке
int insertback_by_name(List *head, char* str) {
    if (!head || !str) return 1;  // ошибка: неверные аргументы
    struct listitem *newNode = (struct listitem*)malloc(sizeof(struct listitem));
    if (!newNode) return 1;  // ошибка: не удалось выделить память
    
    newNode->number = 0;
    
    // Копируем строку безопасно
    int i;
    for (i = 0; i < 79 && str[i] != '\0'; i++) {
        newNode->name[i] = str[i];
    }
    newNode->name[i] = '\0';
    
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return 0;  // успех
    }

    struct listitem *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return 0;  // успех
}

// Проверка на пустоту - возвращает 1 если пустой, 0 если не пустой
int isempty(List *head) {
    if (!head) return 1;  // считаем NULL указатель как "пустой"
    return (*head == NULL) ? 1 : 0;
}

// Длина списка - возвращает количество элементов
int length(List head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Удаление узла - возвращает 0 при успехе, 1 при ошибке
int destroyItem(List *head, List node) {
    if (!head || !node) return 1;  // ошибка: неверные аргументы

    // Если список пуст
    if (*head == NULL) return 1;  // ошибка: список пуст

    // Если удаляем голову
    if (*head == node) {
        *head = node->next;
        free(node);
        return 0;  // успех
    }

    // Ищем предыдущий узел
    struct listitem *prev = *head;
    while (prev != NULL && prev->next != node) {
        prev = prev->next;
    }

    if (prev != NULL) {
        prev->next = node->next;
        free(node);
        return 0;  // успех
    }
    
    return 1;  // ошибка: узел не найден
}

// Поиск по number - возвращает указатель на узел или NULL
struct listitem* getitem_by_number(List head, int n) {
    while (head != NULL) {
        if (head->number == n) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Поиск по name - возвращает указатель на узел или NULL
struct listitem* getitem_by_name(List head, char* str) {
    if (!str) return NULL;
    while (head != NULL) {
        if (strcmp(head->name, str) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}