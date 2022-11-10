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

void init(struct telephone* spisok)
{
	spisok->inform1.charge = 0;
	spisok->inform1.memory = 0;
	*spisok->inform1.internet = (char*)calloc(10, sizeof(char));
	spisok->inform2.width = 0;
	spisok->inform2.height = 0;
	spisok->inform2.thickness = 0;
	spisok->inform2.weight = 0;
	*spisok->inform3.opersystem = (char*)calloc(50, sizeof(char));
	spisok->inform3.internalm = 0;
	*spisok->inform3.card = (char*)calloc(20, sizeof(char));
	spisok->inform4.diagonal = 0;
	*spisok->inform4.pixel = (char*)calloc(30, sizeof(char));
	*spisok->inform5.country = (char*)calloc(50, sizeof(char));
	*spisok->inform5.model = (char*)calloc(20, sizeof(char));
	spisok->inform5.year = 0;
}
void vvod(struct telephone* spisok)
{
	char vvod[50];
	printf("\nВведем информацию о нынешнем состоянии\n");
	printf("Заряд(в процентах): ");
	scanf("%d", &spisok->inform1.charge);
	printf("Свободная память(Гб): ");
	scanf("%d", &spisok->inform1.memory);
	while (getchar() != '\n');
	printf("Интернет: ");
	gets_s(vvod);
	strcpy(*spisok->inform1.internet, vvod);
	printf("\nВведем информацию о параметрах телефона\n");
	printf("Ширина(мм): ");
	scanf("%d", &spisok->inform2.width);
	printf("Высота(мм): ");
	scanf("%d", &spisok->inform2.height);
	printf("Толщина(мм): ");
	scanf("%d", &spisok->inform2.thickness);
	printf("Вес(в граммах): ");
	scanf("%d", &spisok->inform2.weight);
	while (getchar() != '\n');
	printf("\nВведем информацию о системе\n");
	printf("Операционная система: ");
	gets_s(vvod);
	strcpy(*spisok->inform3.opersystem, vvod);//vvod
	printf("Встроенная память(Гб): ");
	scanf("%d", &spisok->inform3.internalm);
	while (getchar() != '\n');
	printf("Карта памяти(yes/no): ");
	gets_s(vvod);
	strcpy(*spisok->inform3.card, vvod);
	printf("\nВведем информацию об экране\n");
	printf("Диагональ(дюйм): ");
	scanf("%lf", &spisok->inform4.diagonal);
	while (getchar() != '\n');
	printf("Плотность пикселей(ppi): ");
	gets_s(vvod);
	strcpy(*spisok->inform4.pixel, vvod);
	printf("\nВведем информацию об общих данных\n");
	printf("Страна-производитель: ");
	gets_s(vvod);
	strcpy(*spisok->inform5.country, vvod);
	printf("Модель: ");
	gets_s(vvod);
	strcpy(*spisok->inform5.model, vvod);
	printf("Год выпуска: ");
	scanf("%d", &spisok->inform5.year);
}
void vivod(struct telephone* spisok)
{
	printf("Информация о телефоне:\n");
	printf("Нынешнее состояние:\n");
	printf("-заряд:%d\n-память:%d\n-интернет:%s\n", spisok->inform1.charge, spisok->inform1.memory, *spisok->inform1.internet);
	printf("Параметры:\n");
	printf("-ширина:%d\n-высота:%d\n-толщина:%d\n-вес:%d\n", spisok->inform2.width, spisok->inform2.height, spisok->inform2.thickness, spisok->inform2.weight);
	printf("Система:\n");
	printf("-операционная система:%s\n-встроенная память:%d\n-карта памяти:%s\n", *spisok->inform3.opersystem, spisok->inform3.internalm, *spisok->inform3.card);
	printf("Экран:\n");
	printf("-диагональ:%lf\n-плотность пикселей:%s\n", spisok->inform4.diagonal, *spisok->inform4.pixel);
	printf("Общие данные:\n");
	printf("-страна-производитель:%s\n-модель:%s\n-год выпуска:%d\n", *spisok->inform5.country, *spisok->inform5.model, spisok->inform5.year);
}
void zaryad(struct telephone* spisok) {
	printf("Сколько стало процентов заряда на телефоне?\n");
	scanf("%d", &spisok->inform1.charge);
	while (getchar() != '\n');
}
void change(struct telephone* spisok) {
	int i, t, j, k;
	do {
		printf("Изменения с объемом памяти связаны с:\n1.Изменением состояния карты памяти\n2.Изменением объема информации\n");
		t = scanf("%d", &i); while (getchar() != '\n');
	} while (t != 1 || i < 0 || i > 2);
	if (i == 1) {
		do {
			printf("1.Карту памяти ставят в телефон\n2.Карту памяти убирают из телефона\n");
			t = scanf("%d", &j); while (getchar() != '\n');
		} while (t != 1 || j < 0 || j > 2);
		do {
			printf("Какой объем памяти у карты?\n");
			t = scanf("%d", &k); while (getchar() != '\n');
		} while (t != 1 || k < 0);
		if (j == 1) {
			if (strcmp(*spisok->inform3.card, "no") == 0) {
				spisok->inform1.memory += k;
				strcpy(*spisok->inform3.card, "yes");
			}
			else
				printf("Карта или уже находится в телефоне, или информация о ней неверна\n");
		}
		if (j == 2) {
			if (strcmp(*spisok->inform3.card, "yes") == 0) {
				spisok->inform1.memory -= k;
				strcpy(*spisok->inform3.card, "no");
			}
			else
				printf("Карты или нет в телефоне, или информация о ней неверна\n");
		}
	}
	if (i == 2) {
		do {
			printf("1.В телефон добавляют информацию\n2.Из телефона удаляют информацию\n");
			t = scanf("%d", &j); while (getchar() != '\n');
		} while (t != 1 || j < 0 || j > 2);
		do {
			printf("Какой объем памяти добавили или удалили?\n");
			t = scanf("%d", &k); while (getchar() != '\n');
		} while (t != 1 || k < 0);
		if (j == 1) {
			spisok->inform1.memory -= k;
		}
		if (j == 2) {
			spisok->inform1.memory += k;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	struct telephone spisok;
	init(&spisok);
	int d, p, t;
	vvod(&spisok);
	vivod(&spisok);
	do {
		do {
			printf("Выберите действие, которое хотите совершить:\n1.Вывод информации\n2.Зарядить телефон\n3.Изменить данные памяти\n4.Ввод новых данных\n5.Выход\n");
			t = scanf("%d", &d); while (getchar() != '\n');
		} while (d < 1 || d>5 || t != 1);
		if (d == 1)
			vivod(&spisok);
		if (d == 2)
		{
			zaryad(&spisok);
		}
		if (d == 3)
			change(&spisok);
		if (d == 4) {
			vvod(&spisok);
			vivod(&spisok);
		}
		if (d == 5) {
			do {
				printf("Вы действительно хотите выйти? (1-Да,2-Нет):");
				t = scanf("%d", &p); while (getchar() != '\n');
			} while (t != 1 || p < 1 || p>2);
			if (p == 1)
				return 0;
		}
		printf("\nХотите продолжить? Да - любая клавиша, Нет -ESC\n");
	} while (_getch() != 27);
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
