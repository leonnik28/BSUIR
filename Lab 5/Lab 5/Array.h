#ifndef ARRAY_HEADER
#define ARRAY_HEADER
int* allocate(int size);

int** allocate_sec(int x, int y);
int** allocate_sec(int x);
void rem_element(int*& arr, int pos, int size);
void rem_element_sec(int*& arr, int pos, int size);
int* write_until_number(int number, int* size);

void rand_array(int*& arr, int x, int min, int max);
void rand_array_sec(int**& arr, int x, int y, int min, int max);
void user_array(int*& arr, int x, int min);
void user_array_sec(int**& arr, int x, int y, int min);
void print_array_sec(int** arr, int x, int y);
void print_array(int* arr, int x);
void print_dinamical_arr(int** arr, int* size, int rowsCount);

int** rem_arr(int**& arr, int pos, int size, int width);
void rand_array(int*& arr, int x, int min, int max);
void user_array(int*& arr, int x);
void print_array(int* arr, int x);
int max(int*& arr, int x);
void search_number(int*& arr, int max, int x);
int search_pos(int**& arr, int max_pos, int pos, int width, int height);
int rem(int*& arr, int n1, int x1);
void search_size(int**& arr, int*& size_arr, int number, int rowsCount);
#endif