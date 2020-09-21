#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int String_indexOfChar(char character, char* string, int size, int fromIndex) {
	int index = -1;
	for (int i = fromIndex; i < size; i++)
	{
		char cur = *(string + i);
		if (cur == character)
		{
			index = i;
			break;
		}
	}
	return index;;
}

int String_indexOf(char* indexString, int indexStringSize, char* mainString, int mainStringSize, int fromIndex) {
	int index = -1;
	bool shouldBreak = false;

	for (int i = fromIndex; i < mainStringSize; i++)
	{
		char cur = *(mainString + i);

		if (cur == *(indexString))
		{
			if (indexStringSize == 1)
			{
				index = i;
				break;
			}
			int count = 1;
			for (int c = 1; c < indexStringSize; c++)
			{
				char indexStrCur = *(indexString + c);
				char mainStrCur = *(mainString + i + c);

				if (mainStrCur != indexStrCur)
				{
					break;
				}
				count++;
				if (count >= indexStringSize)
				{
					index = i;
					shouldBreak = true;
				}
			}
			if (shouldBreak)
			{
				break;
			}
		}
	}
	return index;
}
