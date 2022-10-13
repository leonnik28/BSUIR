#include <stdio.h>
#include <locale.h>
#include<math.h>
int main()
{
	setlocale(LC_ALL, "Rus");// установка русского языка 
	int K;// Декларация переменной К для ввода информации от пользователя
	printf("Введите K :"); //вывод текста 
	scanf_s("%d", &K);// считывание информации введенной пользователем и добавление ее в переменную 
	switch (K) {// открытие блока 'switch' для сравнения перменной К с 'case'
	case 1: {printf("I"); break; }// если К == 1
	case 2: {printf("II"); break; }// если К == 2
	case 3: {printf("III"); break; }// если К == 3
	case 4: {printf("IV"); break; }// если К == 4
	case 5: {printf("V"); break; }// если К == 5
	case 6: {printf("VI"); break; }// если К == 6
	case 7: {printf("VII"); break; }// если К == 7
	case 8: {printf("VIII"); break; }// если К == 8
	case 9: {printf("IX"); break; }// если К == 9
	case 10: {printf("X"); break; }// если К == 10
	default: printf("число не входит в диапазон от 1 до 10");// если К не входит в диапазон от 1 до 10
	}
	return 0;
}