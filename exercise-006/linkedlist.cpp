#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

// Funktion zum Erstellen eines neuen Listenelements
ListNode_t* createListNode(unsigned int data) {
    ListNode_t* newNode = (ListNode_t*)malloc(sizeof(ListNode_t));
    if (newNode == NULL) {
        printf("Speicherreservierung fehlgeschlagen!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->pNext = NULL;
    return newNode;
}

// Funktion zum Löschen eines Listenelements
void deleteListNode(ListNode_t* node) {
    if (node != NULL) {
        free(node);
    }
}

// Funktion zum Initialisieren einer leeren Liste
void initList(List_t* list) {
    list->pHead = NULL;
    list->pTail = NULL;
    list->size = 0;
}

// Funktion zum Einfügen eines Elements in die Liste an beliebiger Stelle
int insertIntoList(List_t* list, unsigned int data, unsigned int position) {
    if (list == NULL) {
        return -1; // Ungültige Liste
    }

    if (position > list->size) {
        return -2; // Ungültige Position
    }

    ListNode_t* newNode = createListNode(data);
    if (newNode == NULL) {
        return -3; // Fehler bei der Erstellung des Knotens
    }

    if (position == 0) { // Einfügen am Anfang
        newNode->pNext = list->pHead;
        list->pHead = newNode;
        if (list->size == 0) {
            list->pTail = newNode;
        }
    } else if (position == list->size) { // Einfügen am Ende
        list->pTail->pNext = newNode;
        list->pTail = newNode;
    } else { // Einfügen in der Mitte
        ListNode_t* current = list->pHead;
        for (unsigned int i = 0; i < position - 1; i++) {
            current = current->pNext;
        }
        newNode->pNext = current->pNext;
        current->pNext = newNode;
    }

    list->size++;
    return 0;
}

// Funktion zum Löschen eines Elements aus der Liste
int deleteFromList(List_t* list, unsigned int position) {
    if (list == NULL || list->size == 0 || position >= list->size) {
        return -1; // Ungültige Operation
    }

    ListNode_t* toDelete = NULL;

    if (position == 0) { // Löschen des ersten Elements
        toDelete = list->pHead;
        list->pHead = list->pHead->pNext;
        if (list->size == 1) {
            list->pTail = NULL; // Liste wird leer
        }
    } else { // Löschen eines Elements in der Mitte oder am Ende
        ListNode_t* current = list->pHead;
        for (unsigned int i = 0; i < position - 1; i++) {
            current = current->pNext;
        }
        toDelete = current->pNext;
        current->pNext = toDelete->pNext;
        if (toDelete == list->pTail) {
            list->pTail = current; // Tail aktualisieren
        }
    }

    deleteListNode(toDelete);
    list->size--;
    return 0;
}

// Funktion zum Iterieren und Ausgeben der Liste
void iterateList(const List_t* list) {
    if (list == NULL || list->size == 0) {
        printf("Die Liste ist leer.\n");
        return;
    }

    ListNode_t* current = list->pHead;
    while (current != NULL) {
        printf("%u -> ", current->data);
        current = current->pNext;
    }
    printf("NULL\n");
}