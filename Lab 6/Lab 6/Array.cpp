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
	return (int*)(malloc(size * sizeof(int)));
}

int** allocate_sec(int x, int y) {
	int** arr = (int**)(malloc(x * sizeof(int*)));
	for (int i = 0; i < x; i++) {
		arr[i] = (int*)(malloc(y * sizeof(int)));
	}
	return arr;
}

void rand_array(int*& arr, int x, int min, int max) {
	for (int i = 0; i < x; i++) {
		arr[i] = rand(min , max);
	}
}

void user_array(int*& arr, int x) {
	for (int i = 0; i < x; i++) {
		arr[i] = getint(1);
	}
}

void print_array(int*& arr, int x) {
	for (int i = 0; i < x; i++) {
		printf("%d ", arr[i]);
	}
} 

void Quick_sort(int*& arr, int left, int right) {
        int i = left;
        int j = right;
        int tmp;
        int x = arr[(left + right) / 2];

        do {
            while (arr[i] > x)
                i++;
            while (arr[j] < x)
                j--;
            if (i <= j) {
                if (i < j) {

                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;

                }
                i++;
                j--;
            }
        } while (i <= j);

        if (i < right)
            Quick_sort(arr, i, right);
        if (left < j)
            Quick_sort(arr, left, j);
}

void Buble_sort(int*& arr, int x) {
	for (int i = 0; i < x - 1; i++) {
		for (int j = (x - 1); j > i; j--) {
			if (arr[j - 1] > arr[j]) {
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void rand_array_sec(int** arr, int x, int y, int min, int max) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			arr[i][j] = rand(min, max);
		}
	}
}

void user_array_sec(int** arr, int x, int y, int min) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf_s("\nWrite element at pos (%d, %d): ", i, j);
			scanf_s("%d ", &arr[i][j]);
		}
	}
}

void print_matrix(int** arr, int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf_s("\nElement at pos (%d, %d): %d", i, j, arr[i][j]);
		}
	}
	printf("\n");
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf_s("%d ", arr[i][j]);
		}
		printf("\n");
	}
}



void Sort_matrix(int**& arr, int width, int height) {

	printf_s("Enter number k ");
	int k = getint(0);
		
	int* numSort = allocate(width);
	int* sumArr = allocate(width);
		
	for (int i = 0; i < width; i++) {
		
		int sum = 0;
		
			for (int j = 0; j < height; j++)
			{
				if (arr[i][j] < 0) continue;
				sum += arr[i][j];	
			}	
			sumArr[i] = sum;
	}

	for (int i = 0; i < width; i++) {
		numSort[i] = i;
	}

	Buble_sort_line(sumArr, numSort, width);
	Final_sort(arr, numSort, width, height);
	free(numSort);
	
}

void Buble_sort_line(int*& arr,int *&numSort, int x) {
	for (int i = 0; i < x - 1; i++) {
		for (int j = (x - 1); j > i; j--) {
			if (arr[j - 1] > arr[j]) {
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;

				int sort = numSort[j-1];
				numSort[j-1] = numSort[j];
				numSort[j] = sort;
			}
		}
	}
}

void Final_sort(int**& arr, int* sort, int w, int h) {
	int** new_matrix = allocate_sec(w, h);
	for (int sort_pos = 0; sort_pos < w; sort_pos++) {
		for (int j = 0; j < h; j++)
		{
			new_matrix[sort_pos][j] = arr[sort[sort_pos]][j];
		}
	}
	//for (int i = 0; i < w; i++) {
		//for (int j = 0; j < h; j++) {
		free(arr);
		//} 
	//}
	
	arr = new_matrix;
}