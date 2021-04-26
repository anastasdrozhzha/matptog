// мат прог 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<cmath>
#include<memory.h>
#include<iostream>
#include"MultyMatrix.h"
#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Levenshtein.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	printf("GENERATE 300 SYMBOLS\n\n");
	int i;
	srand(time(NULL));
	unsigned char c;
	for (i = 0; i <= 300; ++i)
	{
		c = (rand() % ('z' - 'a' + 1)) + 'a';
		printf("%c", c);
	}
	printf("\n\nGENERATE 250 SYMBOLS\n\n");
	srand(time(NULL));
	unsigned char cC;
	for (i = 0; i <= 300; ++i)
	{
		cC = (rand() % ('z' - 'a' + 1)) + 'a';
		printf("%c", cC);
	}
	///////2 zadanie

	setlocale(LC_ALL, "rus");
	clock_t t1 = 0, t2 = 0, t3, t4;
	char x[] = "abcdefghklmnoxm", y[] = "xyabcdefghomnkm";
	int  lx = sizeof(x) - 1, ly = sizeof(y) - 1;
	std::cout << std::endl;
	std::cout << std::endl << "-- расстояние Левенштейна -----" << std::endl;
	//std::cout << std::endl << x << "->" << y << " = " << levenshtein_r(sizeof(x)-1, x, sizeof(y)-1, y) << std::endl;
	std::cout << std::endl << "--длина --- рекурсия -- дин.програм. ---" << std::endl;
	for (int i = 8; i < std::min(lx, ly); i++)
	{
		t1 = clock();
		levenshtein_r(i, x, i - 2, y);
		t2 = clock();
		t3 = clock();
		levenshtein(i, x, i - 2, y);
		t4 = clock();
		std::cout << std::right << std::setw(2) << i - 2 << "/" << std::setw(2) << i
			<< "        " << std::left << std::setw(10) << (t2 - t1)
			<< "   " << std::setw(10) << (t4 - t3) << std::endl;
	}
	system("pause");


	///3 zadanie
	
	// --- main  
//    расстановка скобок  

// умножение матриц 

#define N 6

		int Mc[N + 1] = { 10, 15, 80, 23, 50, 40, 71}, Ms[N][N], r = 0, rd = 0;

		memset(Ms, 0, sizeof(int) * N * N);
		r = OptimalM(1, N, N, Mc, OPTIMALM_PARM(Ms));
		setlocale(LC_ALL, "rus");
		std::cout << std::endl;
		std::cout << std::endl << "-- расстановка скобок (рекурсивное решение) " << std::endl;
		std::cout << std::endl << "размерности матриц: ";
		for (int i = 1; i <= N; i++) std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
		std::cout << std::endl << "минимальное количество операций умножения: " << r;
		std::cout << std::endl << std::endl << "матрица S" << std::endl;
		for (int i = 0; i < N; i++)
		{
			std::cout << std::endl;
			for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
		}
		std::cout << std::endl;

		memset(Ms, 0, sizeof(int) * N * N);
		rd = OptimalMD(N, Mc, OPTIMALM_PARM(Ms));
		std::cout << std::endl
			<< "-- расстановка скобок (динамичеое программирование) " << std::endl;
		std::cout << std::endl << "размерности матриц: ";
		for (int i = 1; i <= N; i++)
			std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
		std::cout << std::endl << "минимальное количество операций умножения: " << rd;
		std::cout << std::endl << std::endl << "матрица S" << std::endl;
		for (int i = 0; i < N; i++)
		{
			std::cout << std::endl;
			for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
		}
		std::cout << std::endl << std::endl;
		system("pause");

		return 0;
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
