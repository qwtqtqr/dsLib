#include<stdio.h>
#include"dsLib.h"


int main() {

#if 0	
	BinTree* tree = newBinTree();

	char* text = "hello world";

	binTree_add(tree, 3, text);
	binTree_add(tree, 5, "qwtqtqr");
	binTree_add(tree, 4, "l");
	
	int array[] = { 234, 56, 65, 54, 52, 67 };
	int arrMin = array_getMin(array, 6);

	//int num = binTree_getItem(tree, 303);
	char* txt = (char*) binTree_getItem(tree, 4);

	printf("DATA: %s\n", txt);

	int index = String_indexOf("qr", 3, "qwtqtqr", 7, 0);

	printf("%d\n", index);

	return 0;
	#endif

	LinkedList* list = newLinkedList();

	LinkedList_add_end(list, 67);
	LinkedList_add_end(list, 3453);
	LinkedList_add_end(list, 47);
	LinkedList_add_end(list, 453);
	LinkedList_add_end(list, 74);
	LinkedList_add_end(list, 64);
	LinkedList_add_end(list, 12);
	LinkedList_add_end(list, 34);
	LinkedList_add_end(list, 303);
	LinkedList_add_end(list, 6347);
	LinkedList_add_end(list, 99);

}