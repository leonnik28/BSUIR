#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Array.h"
#include "IO.h"
//#include "Sort.h"
#include "String.h"
void Task1(int argc, char** argv);
void Task2(int argc, char** argv);
void Task3(int argc, char** argv);


int main(int argc, char** argv)
{
    srand(time(NULL));
    while (true) {
        printf_s("Enter Task (1-3)\n");
        int task;
        while (!scanf_s("%d", &task) || task > 3 || task < 1 || getchar() != '\n') {
            printf_s("Invalid task number!\n");
            rewind(stdin);
        }
        void (*task_run[3]) (int, char**) = { Task1, Task2, Task3 };
        ((*task_run[task - 1])(argc, argv));
        printf_s("\n\n");
        rewind(stdin);
    }
}
void Task1(int argc, char** argv) {
    
    char* a = getstring();
    print_string(a);
    int b = find_amount_word(a);
    printf("%d \n", b);
    int* arr = allocate(b);
    search_word(a,arr,b);

    free(a);
    free(arr);
}
void Task2 (int argc, char** argv) {
    char* S = getstring();
    
    char* S0 = getstring();
   // print_string(S0);
    char* a = search_word_one(S0, S);

    print_string(a);

    
    free(S0);
    free(a);   
}
void Task3 (int argc, char** argv) {
    if (argc == 1) {
         printf_s("Invalid Imput");           
         return;
    }

    char** str = (char**)calloc(argc - 1, sizeof(char*));
    int* min_arr = (int*)calloc((argc - 1), sizeof(int));
    for (int i = 1; i < argc; i++) {
       str_copy(argv[i], str[i - 1]);
    }
    for (int i = 0; i < argc - 1; i++) {
         int min = search_min(str[i]);
         min_arr[i] = min;       
    }
   quick_sort(min_arr, str, 0, argc - 1);
    
    for (int i = 0; i < argc - 1; i++) {
        printf_s("\n %s\n", str[i]);
    }
}