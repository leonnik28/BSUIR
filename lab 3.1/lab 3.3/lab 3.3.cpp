#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int arr_1[100];
	int arr_2[100];
	int n, sum_1 = 0;
	printf_s("Введите количество элементов в массивах: \n");

	while (!scanf_s("%d", &n) || n < 1) {
		printf_s("Invalid Input\n");
		printf_s("Введите количество элементов в массиве: \n");
		rewind(stdin);
	};
	printf_s("Введите элементы первого массива по убыванию: ");
	
	for (int i = 0; i < n; i++) {

			printf_s("a[%d]= ", i);

			while (!scanf_s("%d", &arr_1[i])) {
				printf_s("Invalid Input\n");
				rewind(stdin);
			};
			
			if (i == 0) continue;
			
			if (arr_1[i] > arr_1[i - 1]) {
				printf_s("число больше предыдущего\n");
				rewind(stdin);
				i--;
			}
	}
	printf_s("Введите элементы второго массива по убыванию: ");
	
	for (int i = 0; i < n; i++) {

		printf_s("a[%d]= ", i);

		while (!scanf_s("%d", &arr_2[i])) {
			printf_s("Invalid Input\n");
			rewind(stdin);
		};
		
		if (i == 0) continue;
		
		if (arr_2[i] > arr_2[i - 1]) {
			printf_s("число больше предыдущего\n");
			rewind(stdin);
			i--;
		}
	}
	
	int arr_3[100];
		int arr_4[100];
	
		for (int i = 0; i < n; i++) {
		arr_3[i] = arr_1[i];
		arr_3[n + i] = arr_2[i];
	}
	
		int replaced = 0;
	
	int min = arr_3[0];
	
	for (int i = 0; i < n * 2; i++) {
		if (min > arr_3[i]) min = arr_3[i];
	}
	
	for (int j = 0; j < 2 * n; j++) {
		
		int max = min - 1;
		
		int max_pos = -1;
		
		for (int i = 0; i < 2 * n - replaced; i++) {
			if (arr_3[i] > max) {
				max_pos = i;
				max = arr_3[i];
			}
		}
		//printf_s("Максимальное число на координате %d: %d\n", max_pos, arr_3[max_pos]);
		arr_4[j] = arr_3[max_pos];
		
		for (int s = max_pos; s < 2 * n - 1; s++) {
			//printf_s("Меняю на координате %d вместо %d на %d\n", s, C[s], C[s + 1]);
			arr_3[s] = arr_3[s + 1];
		}
		replaced++;
		/*printf_s("newarr");
		for (int d = 0; d < 2 * n - replaced; d++) {
			printf_s("%d ", arr_3[d]);
		}*/
		printf_s("\n");
	}
	for (int i = 0; i < 2 * n; i++) {
		printf_s("pos %d: %d\n", i, arr_4[i]);
	}
	
	for (int i = 0; i <n*2; i++) {
		printf_s("%d ", arr_4[i]);
	}
	
	return 0;
}