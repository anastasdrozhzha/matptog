#include <iostream>
#include<TCHAR.H>
#include "Combi.h"
#include "Sale.h"
#include "Auxil.h"
#include <algorithm>
#include <iomanip>
#include <iomanip> 
#include <time.h>


#define M 3

int _tmain(int argc, _TCHAR* argv[])
{
#define N5 12
#define INF   0x7fffffff
    setlocale(LC_ALL, "rus");
    int d[N5][N5] = {
                  {  10,  45, INF,  25,   50,  10,  45, 56,  25,   40, 45, 76},    //  1
                  { 45,   10,  55,  20,  100,  45,   10,  55,  20,  50, 87, 90},    //  2
                  { 70,  20,   10,  10,   30,  85,   10,  35,  20,  200, 250, 12},    //  3
                  { 80,  INF,  40,   10,   10,  55,   10,  55,  20,  100, 20, 36},    //  4
                  { 30,  50,  20,  INF,    10,  65,   10,  25,  20,  290, 29, 26} ,   //  5  
                  { 10, 50, 20, 78, 70,  45,   10,  55,  20,  100, 90, 290} ,   //  6  
                  { 30, 10, 2, 32, 120, 85,   90,  55,  20,  70, 90, 50} ,   //  7 
                  { 40, 50, 2, 67, 30, 45,   20,  55,  90,  200, 50, 60} ,   //  8 
                  { 30, 60, 20, 45, 20, 45,   10,  55,  20,  100, 50, 290} ,   //  9 
                  { 70, 50, 20, 59, 10,  45,   10,  55,  20,  100, 300, 100} ,  //  10
                  { 30, 60, 20, 45, 20, 45, 10, 55, 20, 100, 250, 100 },   //  11 
                  { 70, 50, 20, 59, 10,  45,   10,  55,  20 ,96, 25, 20} //12
                 }; 


    int r[N5];                     // ��������� 
    int s2 = salesman(
        N5,          // [in]  ���������� ������� 
        (int*)d,         // [in]  ������ [n*n] ���������� 
        (int*)r        // [out] ������ [n] ������� 0 x x x x  

    );
#define N 12
    std::cout << std::endl << "-- ������ ������������ -- ";
    std::cout << std::endl << "-- ����������  �������: " << N;
    std::cout << std::endl << "-- ������� ���������� : ";
  
    for (int i = 0; i < N; i++)
    {
        std::cout << std::endl;
        for (int j = 0; j < N; j++)

            if (d[i][j] != INF) std::cout << std::setw(3) << d[i][j] << " ";

            else std::cout << std::setw(3) << "INF" << " ";
    }
    std::cout << std::endl << "-- ����������� �������: ";
    for (int i = 0; i < N; i++) std::cout << r[i] << "-->"; std::cout << 0;
    std::cout << std::endl << "-- ����� ��������     : " << s2;
    std::cout << std::endl;
    system("pause");
   
    
    setlocale(LC_ALL, "rus");
    int D[N * N + 1], R[N];
    auxil::start();
    for (int i = 0; i <= N * N; i++) 
        D[i] = auxil::iget(10, 100);
    std::cout << std::endl << "-- ������ ������������ -- ";
    std::cout << std::endl << "-- ���������� ------ ����������������� -- ";
    std::cout << std::endl << "      �������           ����������  ";
    clock_t t1, t2; 
    for (int i = 5; i <= N; i++)
    {
        t1 = clock();
        salesman(i, (int*)d, r);
        t2 = clock();
        std::cout << std::endl << "       " << std::setw(2) << i
            << "               " << std::setw(5) << (double)(t2 - t1)/ ((double)CLOCKS_PER_SEC);
    }
    std::cout << std::endl;
    system("pause");

    return 0;
}

void auxil::start() // ����� ���������� ��. ����� 
{
    srand((unsigned)time(NULL));
};
double auxil::dget(double rmin, double rmax) // �������� ��������� ����� 
{
    return ((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin;
};
int auxil::iget(int rmin, int rmax) // �������� ��������� ����� 
{
    return (int)auxil::dget((double)rmin, (double)rmax);
};