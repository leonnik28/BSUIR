#include <stdio.h>
#include <stdlib.h>

int* allocate(int size) {
	return (int*)(malloc(size * sizeof(int)));
}

char* allocate_char(int size) {	
	return (char*)(malloc(size * sizeof(char)));
}

void quick_sort(int*& arr, char**& sort, int start, int end) {
	int i = start;
	int j = end;
	int tmp;
	char* sort_tmp;
	int x = arr[(start + end) / 2];

	do
	{
		while (arr[i] < x)
			i++;
		while (arr[j] > x)
			j--;
		if (i <= j) {
			if (i < j) {

				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;

				sort_tmp = sort[i];
				sort[i] = sort[j];
				sort[j] = sort_tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < end)
		quick_sort(arr, sort, i, end);
	if (start < j)
		quick_sort(arr, sort, start, j);
}