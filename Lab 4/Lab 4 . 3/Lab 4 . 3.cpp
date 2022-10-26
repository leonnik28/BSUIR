#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	int arr[100][100];
	int col, row;
	printf_s("Введите количество строк: \n");

	while (!scanf_s("%d", &row) || row < 1 || row>100 || getchar() != '\n') {
		printf_s("Invalid Input\n");
		printf_s("Введите количество строк: \n");
		rewind(stdin);
	};

	printf_s("Введите количество столбцов: \n");

	while (!scanf_s("%d", &col) || col < 1 || col>100 || getchar() != '\n') {
		printf_s("Invalid Input\n");
		printf_s("Введите количество столбцов: \n");
		rewind(stdin);
	};
	printf_s("Random generation? (1- yes, 0- no)\n");
	int random;

	while (!scanf_s("%d", &random) || random > 1 || random < 0 || getchar() != '\n') {
		printf_s("Invalid Input\n");
		printf_s("Random generation? (1- yes, 0- no)\n");
		rewind(stdin);
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (random == 1) {
				arr[i][j] = 5 - (rand() % 10);
				printf_s("%d ", arr[i][j]);
			}

			else {
				printf_s("a[%d][%d]= ", i, j);

				while (!scanf_s("%d", &arr[i][j]) || getchar() != '\n') {
					printf_s("Invalid Input\n");
					rewind(stdin);
				};
			}

		}
		printf_s("\n");

	}

	printf_s("\n");
	
	int max = arr[0][0];
	for (int i = 0; i < row/2; i++) {
		for (int j = 0; j < col/2; j++) {
			printf("%d ", arr[i][j]);
			if (max < arr[i][j]) max = arr[i][j];
		}
		printf("\n");
	}

	printf("Максимальный элемент в 1-ой области: %d", max);

	return 0;
}