#ifndef ARRAY_HEADER
#define ARRAY_HEADER
int rand(int min, int max);
int* allocate(int size);

int** allocate_sec(int x, int y);
void rand_array(int*& arr, int x, int min, int max);
void user_array(int*& arr, int x);
void print_array(int*& arr, int x);
void Quick_sort(int*& arr, int left, int right);
void Buble_sort(int*& arr, int x);
void rand_array_sec(int** arr, int x, int y, int min, int max);
void user_array_sec(int** arr, int x, int y, int min);
void print_matrix(int** arr, int x, int y);
void Sort_matrix(int**& arr, int width, int height);
void Quick_sort_matrix(int*& arr, int*& numSort, int left, int right);
void Final_sort(int**& arr, int* sort, int w, int h);
#endif
