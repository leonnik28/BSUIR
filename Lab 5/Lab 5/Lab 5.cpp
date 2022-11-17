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
        rand_array(arr, x,  1, 100);
    else
        user_array(arr, x, 1);

   
    printf_s("\n"); 
    print_array(arr, x);

    printf_s("\n");
    search_number(arr,max(arr, x), x);
    int n = 0;
        while (n < x) {
            if (arr[n] == 1) {
                rem_element(arr, n, x);
                x--;
                n = 0;
            }
            else n++;
        }
    print_array(arr, x);
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

    int pos=-1, max_pos=0;

    for (int i = 0; i < x; i++) {
       
        max_pos = 0;
        
        for (int j = 0; j < y; j++) {
   
            if(arr[i][j]>arr[i][max_pos]) {
                max_pos = j;
            }

        }
       
        for (int k = 0; k < x; k++) {
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

    if (pos != -1) {
        arr = rem_arr(arr, pos, x, y);
        print_array_sec(arr, x-1, y);
    }

    else {
        print_array_sec(arr, x, y);
        printf_s("there is no saddle point");
    }

}

void Task3() {
    printf_s("Write max value: ");
    int number = getint();
    printf_s("Write row count: ");
    int rowsCount = getint(0);
    int** arr = allocate_sec(rowsCount);
    int* size_arr = allocate(rowsCount);
    for (int i = 0; i < rowsCount; i++) {
        printf_s("Row: %d\n", i);
        int size;
        arr[i] = write_until_number(0, &size);

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

    printf_s("\n");

    print_dinamical_arr(arr, size_arr, rowsCount);

    free(arr);
    free(size_arr);
}