#ifndef BIN_TREE_H
#define BIN_TREE_H

#include "../linkedList/list.h"


typedef struct Node {
	struct Node* left;
	struct Node* right;
	struct Node* last;
	int num;
	void* data;
}Node;

typedef struct BinTree {
	int size;
	struct Node* head;
}BinTree;

BinTree* newBinTree();
void binTree_add(BinTree* tree, int num, void* data);
int binTree_getMinIndex(BinTree* tree);
int binTree_getMaxIndex(BinTree* tree);
int array_getMin(int* array, int arraySize);
int array_getMax(int* array, int arraySize);
void* binTree_getItem(BinTree* tree, int index);
LinkedList* binTree_sortNums(LinkedList* list);

#endif
