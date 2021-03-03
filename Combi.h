#pragma once
#include "Combi.h"
#define INF   0x7fffffff   // ������������� 
namespace combi
{
   
    struct  permutation    // ���������   ������������     
    {
        const static bool L = true;  // ����� ������� 
        const static bool R = false; // ������ �������   

        short  w,              // ���������� ��������� ��������� ��������� 
            * sset;           // ������ �������� ������� ������������
        bool* dart;           // ������  ������� (�����-L � ������-R) 
        permutation(short w = 1); // ����������� (���������� ��������� ��������� ���������) 

        void reset();                // �������� ���������, ������ ������� 

        __int64 getfirst();          // ������������ ������ ������ ��������    
        __int64 getnext();           // ������������ ��������� ������ ��������  

        short ntx(short i);          // �������� i-� ������� ������ �������� 
        unsigned __int64 np;         // ����� ������������ 0,... count()-1 

        unsigned __int64 count() const;  // ��������� ����� ���. ������������    
    };
}