#include "Array.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string>
#include "IO.h"

int rand(int min, int max) {
	return min + (rand() % (max - min + 1));
}

int* allocate(int size) {
	int* arr = (int*)(malloc(size * sizeof(int)));
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
	return arr;
}

int** allocate_sec(int x, int y) {
	int** arr = (int**)(malloc(x * sizeof(int*)));
	for (int i = 0; i < x; i++) {
		arr[i] = (int*)(malloc(y * sizeof(int)));
	}
	return arr;
}

int** allocate_sec(int x) {
	int** arr = (int**)(malloc(x * sizeof(int*)));
	return arr;
}

void rand_array(int*& arr, int x, int min, int max) {
	for (int i = 0; i < x; i++) {
			arr[i] = rand(min, max);
	}
}

void user_array(int*& arr, int x, int min) {
	for (int i = 0; i < x; i++) {
			printf_s("\nWrite element at pos (%d): ", i);
			arr[i] = getint(min);
	}
}

void rand_array_sec(int**& arr, int x, int y, int min, int max) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			arr[i][j] = rand(min, max);
		}
	}
}

void user_array_sec(int**& arr, int x, int y, int min) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf_s("\nWrite element at pos (%d, %d): ", i, j);
			arr[i][j] = getint(min);
		}
	}
}

void print_array(int* arr, int x) {

	for (int i = 0; i < x; i++) {	
			printf_s("%d\t", arr[i]);
		printf_s("\n");
	}
}

void print_array_sec(int** arr, int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf_s("\nElement at pos (%d, %d): %d", i, j, arr[i][j]);
		}
	}
	printf_s("\n");
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf_s("%d\t", arr[i][j]);
		}
		printf_s("\n");
	}
}

void rem_element(int*& arr, int pos, int size) {
	int* temp = (int*)malloc((size - 1) * sizeof(int));
	memmove(temp, arr, (pos) * sizeof(int));
	memmove(temp + pos, (arr)+(pos + 1), (size - pos) * sizeof(int));
	free(arr);
	arr = temp;
}

int**  rem_arr(int**& arr, int pos, int size, int width) {
	int** temp = (int**)(malloc((size - 1) * sizeof(int*)));
	for (int i = 0; i < size-1; i++) {
		temp[i] = (int*)(malloc(width * sizeof(int)));
	}
	for (int i = 0, k=0; i < size & k<size -1; i++) {
		if (i == pos) { continue; }
		else 
		{
			for (int j = 0; j < width; j++) {
				temp[k][j] = arr[i][j];
			}
			k++;
		}
		
	}

	return temp;
}

void rem_element_sec(int*& arr, int pos, int size) {
	int* temp = (int*)malloc((size - 1) * sizeof(int));
	memmove(temp, arr, (pos) * sizeof(int));
	memmove(temp + pos, (arr)+(pos + 1), (size - pos) * sizeof(int));
	arr = temp;
}

int* write_until_number(int number, int* size) {
	*size = 0;
	int* temp = (int*)malloc(sizeof(int));
	int i = 0;
	while (true) {
		int entered;
		printf_s("Write number: ");
		while (!scanf_s("%d", &entered) || (entered < 1 && entered != number) || getchar() != '\n') {
			printf_s("\nInvalid number!\n");
			rewind(stdin);
		}
		if (entered == number) break;
		temp[i] = entered;
		(*size)++;
		i++;
		temp = (int*)realloc(temp, (i + 1) * sizeof(int));
	}
	return temp;
}

void user_array(int*& arr, int x) {
	for (int i = 0; i < x; i++) {
		printf_s("\nWrite element at pos (%d): ", i);
		arr[i] = getint();
	}
}

void print_dinamical_arr(int** arr, int* size, int rowsCount) {
	for (int i = 0; i < rowsCount; i++) {
		for (int j = 0; j < size[i]; j++) {
			printf_s("%d\t", arr[i][j]);
		}
		printf_s("\n");
	}
}

int max(int*& arr, int x) {
	int max=arr[0]; int max_pos = 0;
	for (int i = 0; i < x; i++) {
		
		if (arr[i] > arr[max_pos]) {
			max_pos = i;
			max = arr[max_pos];
		}

	}
	return max;
}

void search_number(int*& arr, int max, int x) {
	if (max > 2) {
		for (int i = 0; i < x; i++) {
			for (int j = 2; j < max; j++) {
				if (arr[i] != 2 && arr[i] % j == 0) {
					if (arr[i] == j) continue;
					else	arr[i] = 1;
				}
			}
		}
	}
}

int search_pos(int**& arr, int max_pos, int pos, int width, int height) {
	for (int i = 0; i < width; i++) {

		max_pos = 0;

		for (int j = 0; j < height; j++) {

			if (arr[i][j] > arr[i][max_pos]) {
				max_pos = j;
			}

		}

		for (int k = 0; k < width; k++) {
			if (arr[i][max_pos] > arr[k][max_pos]) {
				pos = -1;
				break;
			}
			if (arr[i][max_pos] < arr[k][max_pos]) {
				pos = i;
			}
		}
		if (pos != -1) break;
	}
	return pos;
}

int rem(int*& arr, int n1, int x1) {
	while (n1 < x1) {
		if (arr[n1] == 1) {
			rem_element(arr, n1, x1);
			x1--;
			n1 = 0;
		}
		else n1++;
	}
	return x1;
}

void search_size(int**& arr, int*& size_arr, int number, int rowsCount) {
	for (int i = 0; i < rowsCount; i++) {
		printf_s("Row: %d\n", i);
		int size;
		arr[i] = write_until_number(0, &size);
		for (int j = 0; j < size; j++) {
			printf_s("\nElement at pos (%d, %d): %d", i, size, arr[i][j]);
		}
		printf_s("\n");
		int n = 0;
		while (n < size) {
			if (arr[i][n] > number) {
				rem_element_sec(arr[i], n, size);
				n = 0;
				size--;
			}
			else n++;
		}
		size_arr[i] = size;
	}
}
