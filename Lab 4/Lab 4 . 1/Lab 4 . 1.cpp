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
				arr[i][j] = 5 - (rand() % 5);
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
	int null=0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j] == 0) {
				null +=1;
				break;
			}
		}
	}
	printf("Количество строк с нулевым элементом: %d \n", null);
	int numcol, maxsame = 0, same=0, next_num;
	for (int j = 0; j < col; j++) {
		same = 0;
		next_num = arr[0][j];
		for (int i = 0; i < row; i++) {
			if (arr[i][j] == next_num) {
				same++;
			}
			else {
				if (maxsame < same) {
					numcol = j;
					maxsame = same;
				}
				same = 1;
				next_num = arr[i][j];
			}
		}
		if (maxsame < same) {
			maxsame = same;
			numcol = j;
		}
		if (maxsame == 1) {
			numcol = -1;
		}
	}
		if (numcol == -1) {
			printf("Отсутствуют повторения в столбцах \n");
		}
		else {
			printf("Наибольшее количество одинаковых элементов находятся в столбце N:  %d ", numcol + 1);
		}
	

	return 0;
}
