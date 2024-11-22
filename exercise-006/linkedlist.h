#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Definition der Listenknotenstruktur
typedef struct ListNode {
    unsigned int data;
    struct ListNode* pNext;
} ListNode_t;

// Definition der Listenstruktur
typedef struct List {
    struct ListNode* pHead;
    struct ListNode* pTail;
    unsigned int size;
} List_t;

// Funktionsdeklarationen
void initList(List_t* list);
int insertIntoList(List_t* list, unsigned int data, unsigned int position);
int deleteFromList(List_t* list, unsigned int position);
void iterateList(const List_t* list);
ListNode_t* createListNode(unsigned int data);
void deleteListNode(ListNode_t* node);

#endif // LINKEDLIST_H