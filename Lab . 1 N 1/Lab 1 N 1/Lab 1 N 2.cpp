#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");// установка русского языка 
	int a, b, c;// Декларация переменных a,b,c для ввода информации от пользователя
	printf("Введите a :"); //вывод текста 
	scanf_s("%d", &a);// считывание информации введенной пользователем и добавление ее в переменную 
	printf("Введите b :");//вывод текста 
	scanf_s("%d", &b);// считывание информации введенной пользователем и добавление ее в переменную
	printf("Введите c :");//вывод текста 
	scanf_s("%d", &c);// считывание информации введенной пользователем и добавление ее в переменную
	if (a == -b || a == -c || b == -c) {
		printf("Есть хоть одна пара взаимнообратных чисел");
	}// Проверка на пару взаимнообратных чисел
	else { printf("Нету пары взаимнообратных чисел"); }// если нету взаимнообратных чисел
	return 0;
}