#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
int main()
{
  int a[SIZE][SIZE]; // ������� ������
  int d[SIZE]; // ����������� ����������
  int v[SIZE]; // ���������� �������
  int temp, minindex, min;
  int begin_index = 0;
  system("chcp 1251");

  //������������� ������ � ����������
  for (int i = 0; i<SIZE; i++)
  {
    d[i] = 10000;
    v[i] = 1;
  }
  d[begin_index] = 0;
  // ��� ���������
  do {
    minindex = 10000;
    min = 10000;
    for (int i = 0; i<SIZE; i++)
    { // ���� ������� ��� �� ������ � ��� ������ min
      if ((v[i] == 1) && (d[i]<min))
      { // ��������������� ��������
        min = d[i];
        minindex = i;
      }
    }
    // ��������� ��������� ����������� ���
    // � �������� ���� �������
    // � ���������� � ������� ����������� ����� �������
    if (minindex != 10000)
    {
      for (int i = 0; i<SIZE; i++)
      {
        if (a[minindex][i] > 0)
        {
          temp = min + a[minindex][i];
          if (temp < d[i])
          {
            d[i] = temp;
          }
        }
      }
      v[minindex] = 0;
    }
  } while (minindex < 10000);
  // ����� ���������� ���������� �� ������
  printf("\n���������� ���������� �� ������: \n");
  for (int i = 0; i<SIZE; i++)
    printf("%5d ", d[i]);
  return 0;
}

