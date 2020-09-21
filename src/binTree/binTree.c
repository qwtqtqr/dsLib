#include <stdio.h>
#include <stdbool.h>
#include "binTree.h"


BinTree* newBinTree() {
	BinTree* init = malloc(sizeof(BinTree));
	init->head = NULL;
	init->size = 0;
	return init;
}

int array_getMin(int* array, const int arraySize) {
    BinTree* tree = newBinTree();
	for (int i = 0; i < arraySize; i++)
	{
		int curNum = *(array + i);
		binTree_add(tree, curNum, NULL);
	}
	int min = binTree_getMinIndex(tree);
	return min;
}

int array_getMax(int* array, const int arraySize) {
	BinTree* tree = newBinTree();
	for (int i = 0; i < arraySize; i++)
	{
		int curNum = *(array + i);
		binTree_add(tree, curNum, NULL);
	}
	int max = binTree_getMaxIndex(tree);
	return max;
}

void* binTree_getItem(BinTree* tree, int index) {
	Node* cur = tree->head;

	while (index != cur->num)
	{
		int num = cur->num;
		if (index < num)
		{
			cur = cur->left;
		}
		if (index > num)
		{
			cur = cur->right;
		}
	}
	return cur->data;
}

void binTree_add(BinTree* tree, int num, void* data) {
	Node* node = malloc(sizeof(Node));
	node->last = NULL;
	node->left = NULL;
	node->right = NULL;
	node->num = num;
	node->data = data;

	if (tree->head == NULL)
	{
		tree->head = node;
		tree->size++;
		return;
	}

	Node* cur = tree->head;
	Node* prev = NULL;
	bool left = true;
	while (cur != NULL)
	{
		int curNum = cur->num;
		prev = cur;
		if (num < curNum)
		{
			cur = cur->left;
			left = true;
		}
		if (num >= curNum)
		{
			cur = cur->right;
			left = false;
		}
	}

	if (left)
	{
		node->last = prev;
		prev->left = node;
	}
	if (!left)
	{
		node->last = prev;
		prev->right = node;
	}
}


int binTree_getMinIndex(BinTree* tree) {
	Node* cur = tree->head;
	Node* prev = NULL;

	while (cur != NULL)
	{
		prev = cur;
		cur = cur->left;
	}
	return prev->num;
}

int binTree_getMaxIndex(BinTree* tree) {
	Node* cur = tree->head;
	Node* prev = NULL;

	while (cur != NULL)
	{
		prev = cur;
		cur = cur->right;
	}
	return prev->num;
}

void* binTree_getMinIndexItem(BinTree* tree) {
	Node* cur = tree->head;
	Node* prev = NULL;

	while (cur != NULL)
	{
		prev = cur;
		cur = cur->left;
	}
	return prev->data;
}

int binTree_getMaxIndexItem(BinTree* tree) {
	Node* cur = tree->head;
	Node* prev = NULL;

	while (cur != NULL)
	{
		prev = cur;
		cur = cur->right;
	}
	return prev->data;
}

Node* binTree_getNode(BinTree* tree, int index){
	Node* cur = tree->head;

	while (index != cur->num)
	{
		int num = cur->num;
		if (index < num)
		{
			cur = cur->left;
		}
		if (index > num)
		{
			cur = cur->right;
		}
	}
	return cur;
}

Node* binTree_getMinNode(BinTree* tree, int index) {
	Node* cur = tree->head;
	Node* prev = NULL;

	while (cur != NULL)
	{
		prev = cur;
		cur = cur->left;
	}
	return prev;
}

Node* binTree_getMaxNode(BinTree* tree, int index) {
	Node* cur = tree->head;
	Node* prev = NULL;

	while (cur != NULL)
	{
		prev = cur;
		cur = cur->right;
	}
	return prev;
} 

LinkedList* binTree_sortNums(LinkedList* list) {
	BinTree* tree = newBinTree();
	for (int i = 0; i < LinkedList_size(list); i++){
		int num = (int*)LinkedList_getItem(list, i);
		printf("%d\n", num);
		binTree_add(tree, num, NULL);
	}
	LinkedList_clear(list);
	LinkedList* returnList = newLinkedList();
	Node* cur = tree->head;
	Node* prev = NULL;
	int counter = 0;
	int listSize = LinkedList_size(list);
	while (true) {
		if (counter == listSize)
		{
			break;
		}
		while (cur != NULL)
		{
			prev = cur;
			cur = cur->left;
		}
		LinkedList_add_end(returnList, prev->num);
		counter++;
		if (counter == listSize)
		{
			break;
		}
		while (cur->right == NULL) {
			prev = cur;
			cur = cur->last;
		}
		LinkedList_add_end(returnList, cur->num);
		counter++;
		if (counter == listSize)
		{
			break;
		}
		prev = cur;
		cur = cur->right;
		LinkedList_add_end(returnList, cur->num);
		counter++;
		if (counter == listSize)
		{
			break;
		}
	}
	return returnList;
}