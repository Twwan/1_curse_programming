#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

int get_size_mas(char *name_file);
/* ��������: �� ���� ��������� �������� �����, ����� ���� ��������� ��� � ��������� ������ �����. ������ ����� - ����� �������.
���������: name_file - ��������� �� ������ ���� char, �������� � ���� �������� �����.
������������ ��������: ���������� ����� ������� (int n), ����� n = 0.
*/

void init_mas(char *name_file, int *mas);
/* ��������: ��������� �� ���� �������� ����� � ������ ������, ������� ����������� ������� �� �����. �������� � ���� print_mas().
���������: name_file - ��������� �� ������ ���� char, �������� � ���� �������� �����. mas - ��������� �� ������ ���� int (������).
������������ ��������: ������� ����� ��� void � ��� �������� ���������� ������.
*/

void print_mas(int *mas, int n);
/* ��������: ������� �������� �������.
���������: mas - ��������� �� ������ ���� int (������). n - �������� ���� int (����� �������).
������������ ��������: ������� ����� ��� void � ��� �������� ���������� ������.
*/

int elm_add(int *mas, int n);
/* ��������: ���������� ������ �������� � ����� �������. �������� � ���� print_mas().
���������: mas - ��������� �� ������ ���� int (������). n - �������� ���� int (����� �������).
������������ ��������: ���������� ����� ����� ������� (int n+1).
*/

int max_elm_remove(int *mas, int n);
/* ��������: �������� �������� � ������������ ���������. ��������� ������ ��������� ������� � ������������ ���������. �������� � ���� print_mas().
���������: mas - ��������� �� ������ ���� int (������). n - �������� ���� int (����� �������).
������������ ��������: ���������� ����� ����� ������� (int n-1).
*/

int max_search(int *mas, int n);
/* ��������: ������� ������������ �������.
���������: mas - ��������� �� ������ ���� int (������). n - �������� ���� int (����� �������).
������������ ��������: ���������� ������ ��������� ������� � ������������ ���������.
*/

int elm_remove(int *mas, int n);
/* ��������: ��������� �������� � �������� ���������. �������� � ���� print_mas().
���������: mas - ��������� �� ������ ���� int (������). n - �������� ���� int (����� �������).
������������ ��������: ���������� ����� ����� ������� (int n-1).
*/

int search(int *mas, int n);
/* ��������: ����� ������� �������� � �������� ���������. ��� ������ � elm_remove().
���������: mas - ��������� �� ������ ���� int (������). n - �������� ���� int (����� �������).
������������ ��������: ���������� ������ ��������� ������� � �������� ���������, ����� ��������� NULL.
*/

void elm_search(int *mas, int n);
/* ��������: ����� ������� �������� � �������� ���������. ������� ������ ������������� ��������, � ��������� ������ ������ �� ����� �������.
���������: mas - ��������� �� ������ ���� int (������). n - �������� ���� int (����� �������).
������������ ��������: ������� ����� ��� void � ��� �������� ���������� ������.
*/

void elm_change(int *mas, int n);
/* ��������: ������ �������� �������� ��������. ���� ������� �� ������, �� ������ �������� �������. �������� � ���� print_mas().
���������: mas - ��������� �� ������ ���� int (������). n - �������� ���� int (����� �������).
������������ ��������: ������� ����� ��� void � ��� �������� ���������� ������.
*/

#endif // CORE_H_INCLUDED
