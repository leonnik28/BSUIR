#include "IO.h"
#include <stdio.h>
#include <stdlib.h>

int getint(int min) {
	int number;
		while (!scanf_s("%d", &number) || number < min || getchar() != '\n') {
			printf("Invalid number ");
			rewind(stdin);
	}
		return number;
}

char* getstring() {
    char* string = (char*)calloc(1, sizeof(char));
    char ch;
    int pos = 0;
    while (1) {
        ch = getchar();
        if (ch == '\n')
        {
            string[pos] = '\0';
            return string;
        }

        string[pos] = ch;
        pos++;
        string = (char*)realloc(string, (pos + 1) * sizeof(char));
    }
}

void print_string(char* string) {
    int i = 0;
    while (string[i] != '\0') {
        printf("%c", string[i]);
        i++;
    }
    printf("\n");
}

int num(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}