#include <iostream>
#include "linkedlist.h"

int main() {
    List_t myList;
    initList(&myList);

    // Elemente einfügen
    insertIntoList(&myList, 10, 0); // Einfügen am Anfang
    insertIntoList(&myList, 20, 1); // Einfügen am Ende
    insertIntoList(&myList, 15, 1); // Einfügen in der Mitte
    iterateList(&myList);

    // Elemente löschen
    deleteFromList(&myList, 1); // Löschen aus der Mitte
    iterateList(&myList);

    deleteFromList(&myList, 0); // Löschen des ersten Elements
    iterateList(&myList);

    deleteFromList(&myList, 0); // Liste leeren
    iterateList(&myList);

    return 0;
}