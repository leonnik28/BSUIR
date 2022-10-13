#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	double arr[100];
	int n;
	printf_s("Введите количество элементов в массиве: \n");

	while (!scanf_s("%d", &n) || n < 1) {
		printf_s("Invalid Input\n");
		printf_s("Введите количество элементов в массиве: \n");
		rewind(stdin);
	};
	printf_s("Random generation? (1- yes, 0- no)\n");
	int random;

	while (!scanf_s("%d", &random) || random > 1 || random < 0) {
		printf_s("Invalid Input\n");
		printf_s("Random generation? (1- yes, 0- no)\n");
		rewind(stdin);

	}
	
	for (int i = 0; i < n; i++) {

		if (random == 1) {
			arr[i] = 100 - (rand() % 200);
			printf_s("%0.1lf ", arr[i]);
		}

		else {
			printf_s("a[%d]= ", i);

			while (!scanf_s("%lf", &arr[i])) {
				printf_s("Invalid Input\n");
				rewind(stdin);
			};
		}
	}
	int max=arr[0], min = arr[0];
	int min_pos=0, max_pos=0;
	
	for (int i = 0; i < n; i++) {
		
		if (arr[i] < min) {
			min = arr[i];
			min_pos = i;
		}
	}
	for (int i = 0; i < min_pos; i++) {
		
		if (arr[i] > max) {
			max = arr[i];
			max_pos = i;
			break;
		}
	}
	if (min_pos != 0) {
		
		printf_s("Новый массив: \n");
		
		for (int i = 0; i < max_pos+1; i++) {// заполнение нового массива
			printf_s("%0.1lf ", arr[i]);
		}
		
		for (int i = min_pos; i < n; i++) {
			printf_s("%0.1lf ", arr[i]);
		}
		
	}
	else {
		printf_s("Невозможно создать новый массив. ");
	}
	
	return 0;
}