#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Array.h"
#include "IO.h"

void Task1();
void Task2();

int main()
{
    srand(time(NULL));
    while (true) {
        printf_s("Enter Task (1-2)\n");
        int task;
        while (!scanf_s("%d", &task) || task > 3 || task < 1 || getchar() != '\n') {
            printf_s("Invalid task number!\n");
            rewind(stdin);
        }
        switch (task) {
        case 1:
            Task1();
            break;
        case 2:
            Task2();
            break;
        }
        printf_s("\n\n");
        rewind(stdin);
    }
}

void Task1() {
    printf("Write long ");
    int x = getint(0);
    
    int* arr = allocate(x);
    printf("Random? (1 - yes, 0 - no): ");
    int rand = getint(0, 1);
    if (rand == 1)
        rand_array(arr, x, 1, 100);
    else
        user_array(arr, x);

    printf_s("\n");
    print_array(arr, x);

    int* arr_1 = allocate(x);
    arr_1 = arr_copy(arr, x);
    int* arr_2 = allocate(x);
    arr_2 = arr_copy(arr, x);

    printf_s("\n");
    clock_t time_start = clock();
    quick_sort(arr,0, x);
    clock_t time_end = clock();
    print_array(arr, x);

    

    clock_t time_start_1 = clock();
    buble_sort(arr_1, x);
    clock_t time_end_1 = clock();

    printf_s("\n");

    print_array(arr_1, x);
    
    printf_s("\nQuick Sort - Ellapsed seconds: %f seconds", (float)(time_end - time_start) / CLOCKS_PER_SEC);
    printf_s("\nBuble Sort - Ellapsed seconds: %f seconds", (float)(time_end_1 - time_start_1) / CLOCKS_PER_SEC);
    
    free(arr);
}

void Task2() {
    printf_s("Write height: ");
    int x = getint(0);
    printf_s("Write width: ");
    int y = getint(0);
    int** arr = allocate_sec(x, y);
    printf_s("Random? (1 - yes, 0 - no): ");
    int rand = getint(0, 1);
    if (rand == 1)
        rand_array_sec(arr, x, y, 1, 10);
    else
       user_array_sec(arr, x, y, 1);
  
    printf_s("\n");
    print_matrix(arr, x, y);

    sort_matrix(arr, x, y);
    printf_s("\n");

    print_matrix(arr, x, y);
}