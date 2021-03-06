#include <stdio.h>
#include "list.h"

LinkedList* newLinkedList() {
	LinkedList* initList = malloc(sizeof(LinkedList));
	initList->head = NULL;
	initList->tail = NULL;
	initList->size = 0;
	return initList;
}

void LinkedList_add(LinkedList* list, int index, void* data) {
	node_t* node = malloc(sizeof(node_t));
	node->data = data;
	node->next = NULL;
	node->last = NULL;
	node->id = 0;

	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
		list->size++;
		return;
	}
	int idx = 0;
	node_t* prev = NULL;
	node_t* cur = list->head;

	while (idx != index && cur != NULL)
	{
		idx++;
		prev = cur;
		cur = cur->next;
	}
	if (idx == 0)
	{
		list->head = node;
		cur->last = node;
		node->next = cur;
		list->size++;
		return;
	}
	if (cur == NULL)
	{
		node->last = prev;
		prev->next = node;
		list->tail = node;
		list->size++;
		return;
	}
}

void LinkedList_add_beg(LinkedList* list, void* data) {
	LinkedList_add(list, 0, data);
}

void LinkedList_add_end(LinkedList* list, void* data) {
	LinkedList_add(list, -1, data);
}

int LinkedList_size(LinkedList* list) {
	return list->size;
}

void LinkedList_remove(LinkedList* list, int index) {
	int size = LinkedList_size(list);
	if (index == size - 1)
	{
		list->tail = list->tail->last;;
		list->size--;
		return;
	}
	if (index == 0)
	{
		list->head = list->head->next;
		list->size--;
		return;
	}
	if (index > 1 && index > size / 2 - 1)
	{
		node_t* temp = list->tail;
		node_t* prev = NULL;
		node_t* next = NULL;
		int idx = size - 1;

		while (temp != NULL) {
			if (idx == index - 1)
			{
				prev = temp;
			}
			if (idx == index + 1)
			{
				next = temp;
			}
			temp = temp->last;
			idx--;
		}
		prev->next = next;
		next->last = prev;
		list->size--;
		return;
	}
	else
	{
		node_t* temp = list->head;
		node_t* prev = NULL;
		node_t* next = NULL;
		int idx = 0;

		while (temp != NULL)
		{
			if (idx == index - 1)
			{
				prev = temp;
			}
			if (idx == index + 1)
			{
				next = temp;
			}
			temp = temp->next;
			idx++;
		}
		prev->next = next;
		next->last = prev;
		list->size--;
		return;
	}
}

void* LinkedList_getItem(LinkedList* list, int index) {
	int size = LinkedList_size(list);
	if (size > 1 && index > size / 2 - 1) {
		node_t* temp = list->tail;
		int idx = 0;
		while (idx < size - index - 1)
		{
			temp = temp->last;
			idx++;
		}
		return temp->data;
	}

	node_t* temp = list->head;
	int idx = 0;
	while (idx < index)
	{
		idx++;
		temp = temp->next;
	}
	return temp->data;
}

int LinkedList_getItemId(LinkedList* list, int index) {
	int size = LinkedList_size(list);
	if (size > 1 && index > size / 2 - 1) {
		node_t* temp = list->tail;
		int idx = 0;
		while (idx < size - index - 1)
		{
			temp = temp->last;
			idx++;
		}
		return temp->id;
	}

	node_t* temp = list->head;
	int idx = 0;
	while (idx < index)
	{
		idx++;
		temp = temp->next;
	}
	return temp->id;
}

void LinkedList_setItemId(LinkedList* list, int index, int id) {
	int size = LinkedList_size(list);
	if (size > 1 && index > size / 2 - 1) {
		node_t* temp = list->tail;
		int idx = 0;
		while (idx < size - index - 1)
		{
			temp = temp->last;
			idx++;
		}
		temp->id = id;
		return;
	}

	node_t* temp = list->head;
	int idx = 0;
	while (idx < index)
	{
		idx++;
		temp = temp->next;
	}
	temp->id = id;
	return;
}

node_t* LinkedList_getNode(LinkedList* list, int index) {
	int size = LinkedList_size(list);
	if (size > 1 && index > size / 2 - 1) {
		node_t* temp = list->tail;
		int idx = 0;
		while (idx < size - index - 1)
		{
			temp = temp->last;
			idx++;
		}
		return temp;
	}

	node_t* temp = list->head;
	int idx = 0;
	while (idx < index)
	{
		idx++;
		temp = temp->next;
	}
	return temp;
}

void LinkedList_clear(LinkedList* list) {
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

void* LinkedList_getLast(LinkedList* list) {
	return list->tail->data;
}

void* LinkedList_getFirst(LinkedList* list) {
	return list->head->data;
}