#ifndef LIST_H
#define LIST_H
#include <stdbool.h>

typedef struct node_t {
	void* data;
	struct node_t* next;
	struct node_t* last;
	int id;
}node_t;

typedef struct LinkedList {
	struct node_t* head;
	struct node_t* tail;
	int size;
}LinkedList;

LinkedList* newLinkedList();
void LinkedList_add(LinkedList* list, int index, void* data);
void LinkedList_add_beg(LinkedList* list, void* data);
void LinkedList_add_end(LinkedList* list, void* data);
int LinkedList_size(LinkedList* list);
void* LinkedList_getItem(LinkedList* list, int index);
void LinkedList_clear(LinkedList* list);
node_t* LinkedList_getNode(LinkedList* list, int index);
void LinkedList_remove(LinkedList* list, int index);
int LinkedList_getItemId(LinkedList* list, int index);
void LinkedList_setItemId(LinkedList* list, int index, int id);
void* LinkedList_getLast(LinkedList* list);
void* LinkedList_getFirst(LinkedList* list);

#endif