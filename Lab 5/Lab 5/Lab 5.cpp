#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Array.h"
#include "IO.h"

 
void Task1();
void Task2();
void Task3();

int main()
{
srand(time(NULL));
    while (true) {
        printf_s("Enter Task (1-3)\n");
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
        case 3:
            Task3();
            break;
        }
        printf_s("\n\n");
        rewind(stdin);
    }
}

void Task1() {
    printf_s("Write long: ");
    int x = getint(0);

    int* arr = allocate(x);
    printf_s("Random? (1 - yes, 0 - no): ");
    int rand = getint(0, 1);
    if (rand == 1)
        rand_array(arr, x, 1, 100);
    else
        user_array(arr, x, 1);

    printf_s("\n");
    print_array(arr, x);

    printf_s("\n");
    search_number(arr, max(arr, x), x);
    int n = 0;

    x = rem(arr, n, x);

    printf_s("New array: \n");
    print_array(arr, x);
    free(arr);
}

void Task2() {
    printf_s("Write width: ");
    int x = getint(0);
    printf_s("Write height: ");
    int y = getint(0);
    int** arr = allocate_sec(x, y);
    printf_s("Random? (1 - yes, 0 - no): ");
    int rand = getint(0, 1);
    if (rand == 1)
        rand_array_sec(arr, x, y, 1, 100);
    else
        user_array_sec(arr, x, y, 1);

    printf_s("\n");

    printf_s("\n");

    print_array_sec(arr, x, y);

    int pos = -1, max_pos = 0;

    pos = search_pos(arr, max_pos, pos, x, y);

    if (pos != -1) {
        arr = rem_arr(arr, pos, x, y);
        print_array_sec(arr, x - 1, y);
    }

    else {
        print_array_sec(arr, x, y);
        printf_s("there is no saddle point");
    }
    free(arr);
}

void Task3() {
    printf_s("Write max value: ");
    int number = getint();
    printf_s("Write row count: ");
    int rowsCount = getint(0);
    int** arr = allocate_sec(rowsCount);
    int* size_arr = allocate(rowsCount);

    search_size(arr, size_arr, number, rowsCount);

    printf_s("\n");

    print_dinamical_arr(arr, size_arr, rowsCount);

    free(arr);
    free(size_arr);
}