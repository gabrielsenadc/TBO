#ifndef crivochar_h
#define crivochar_h

typedef struct list listType;

listType * createList(int size);

void execute(listType * list);

void printList(listType * list);

void freeList(listType * list);


#endif