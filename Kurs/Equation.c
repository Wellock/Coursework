#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define SIZE 30

void menu();
double function(double x);
void build_tabl(float st, float step, int qua);
void mono(double start, double finale, int step);
double X_on_Y(double znachY, double error, double start, double fin);
double derivative(double x);


void main()

{

	system("chcp 1251");

	menu();

	

}

void menu()
{
	int rep = 1;
	do
	{
		int choice;

		puts("\nЧто вы хотите?\n1. Значение функции в точке\n2. Таблица значений\n3. Поиск максимума/минимума\n4. Поиск Х по Y\n5. Производная в точке\n0. Выход\n");
		scanf("%i", &choice);
		switch (choice)
		{
		case 1:

			puts("Введите значение х");
			double x;
			scanf("%lf", &x);
			printf("В данной точке значение функции равно >>> %lf", function(x));
			break;
		case 2:
			puts("Введие начало отсчета");
			float start;
			scanf("%f", &start);
			puts("Введие шаг");
			float step;
			scanf("%f", &step);
			puts("Введие количиство отсчетов");
			int qua;
			scanf("%i", &qua);
			build_tabl(start, step, qua);
			break;
		case 3:
			puts("Нахождение максимума и минимума");
			puts("Введите начало интервала");
			double st_extreme;
			scanf("%lf", &st_extreme);
			puts("Введите конец интервала");
			double fi_extreme;
			scanf("%lf", &fi_extreme);
			puts("Введите количество проверочных точек");
			int quantity;
			scanf("%i", &quantity);
			mono(st_extreme, fi_extreme, quantity);
			break;
		case 4:

			puts("Введите значение функции");
			double y;
			scanf("%lf", &y);
			puts("Насколько точным должно быть значение");
			double error_rate;
			scanf("%lf", &error_rate);
			puts("Введите начало интервала");
			double start_p4;
			double finale_p4;
			scanf("%lf", &start_p4);
			puts("Введите конец интервала");
			scanf("%lf", &finale_p4);

			X_on_Y(y, error_rate, start_p4, finale_p4);
			break;


		case 5:
			puts("Введите значение х");
			double p;
			scanf("%lf", &p);
			printf("Значение производной равно %lf\n", derivative(p));
			break;


		case 0:
			rep = 0;
			break;
		}
		

	} while (rep == 1);

}

double function(double x)
{
	double y;
	if (x < 2) y = (pow(tan(x), -1) - sin(x)) / pow(x, 3);
	if (x >= 2 && x < 9) y = (exp(cos(x)) * sqrt(pow(x, 2) + 1)) / log(3 + x);
	if (x >= 9) y = sin(2 * x - 5) / (1 + pow(x, 6));
	return y;
}

void build_tabl(float st, float step, int qua)
{
	puts("| Значение х | Значение f(x) |");
	for (int i = 0; i < qua; i++, st = st + step)
	{
		printf("| %10.4g | %13.4g |\n", st, function(st));
	}
}



void mono(double start, double finale, int step)
{
	double g = (finale - start) / (step - 1);
	double first_y = function(start);
	_Bool up = 0;
	_Bool down = 0;
	_Bool constant = 1;
	for (int i = 1; i < step; i++)
	{
		double x = start + i * g;
		double second_y = function(x);
		if (second_y > first_y)
		{
			up = 1;
			constant = 0;
		}
		if (second_y < first_y)
		{
			down = 1;
			constant = 0;
		}
		first_y = second_y;
	}
	printf("Анализ монотонности на [%lf, %lf]: \n", start, finale);
	if (constant)
	{
		printf("Функция постоянно на данном отрезке\n");
	}
	else if (up && !down)
	{
		printf("Функция монотонно возрастает\n");
	}
	else if (!up && down)
	{
		printf("Функция монотонно убывает\n");
	}
	else if (up && down)
	{
		printf("Функция не является монотонной\n");
	}
	else
	{
		printf("Не удалось определить характер функции\n");
	}
}

double X_on_Y( double znachY, double error, double start, double fin)
{
	double step = 0.00001;
	double x = start;
	_Bool pr = 0;
	while (x <= fin)
	{
		double fx = function(x);
		double diff = fabs(fx - znachY);
		if (diff < error && pr == 0)
		{

			printf("x = %lf", x);
			pr = 1;

		}
		x += step;
	}
	if (pr == 0)
	{
		printf("На данном промежутке таких значений нет");
	}
	return 0;
}




double derivative(double x)
{
	double h = 0.0001;
	double y = function(x+h)-function(x);
	return y;
}