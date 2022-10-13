#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	double arr[100];
	int n,sum_1=0;
	printf_s("Введите количество элементов в массиве: \n");
	
	while (!scanf_s("%d", &n)|| n<1) {
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
		int neg_1 = -1;
		int neg_2 = -1;
	
		for (int i = 0; i < n; i++) {
		
			if (random == 1) {
		 arr[i] = 100 - (rand() % 200);
		 printf_s("%lf ", arr[i]);
		}
		
		else {
			printf_s("a[%d]= ", i);

			while (!scanf_s("%lf", &arr[i])) {
				printf_s("Invalid Input\n");
				rewind(stdin);
			};
		}
			
		if (i % 2 != 0) {
			sum_1 += arr[i];
		}
		
		if (arr[i] < 0.0 && neg_1 < 0) neg_1 = i;
		else if (arr[i] < 0.0) neg_2 = i;
	}

	printf("Сумма элементов с нечетными номерами: %d\n", sum_1);
	int sum_2 = 0;
	
	if (neg_1 >= 0 && neg_2 >= 0) {
		for (int i = neg_1 + 1; i < neg_2; i++) {
			sum_2 += arr[i];
		}
		
		printf_s("Сумма между отрицательными числами: %d", sum_2);
	}
	
	else {
		printf_s("Нету отрицательных элементов. ");
	}
	
	
	return 0;
}
