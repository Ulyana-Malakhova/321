// 321.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

struct current_state {
	int charge;
	int memory;
	char* internet[10];
};
struct dimensions {
	int width;
	int height;
	int thickness;
	int weight;
};
struct system_t {
	char* opersystem[50];
	int internalm;
	char* card[20];
};
struct screen {
	double diagonal;
	char* pixel[30];
};
struct general_data {
	char* country[50];
	char* model[20];
	int year;
};
struct telephone {
	current_state inform1;
	dimensions inform2;
	system_t inform3;
	screen inform4;
	general_data inform5;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	struct telephone spisok;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
