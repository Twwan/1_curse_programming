#include <stdlib.h>
#include <stdio.h>
#include "hw3_func.h"

int main(){
	system("chcp 1251");
	char Name_file[50]; // ���� �������� �������� �����
	printf("������� �������� �����: ");
	scanf("%s", &Name_file);
	int *Mas = NULL; // �������� ���������
	int N;
	N = get_size_mas(Name_file); // ������ ����������� �������
	Mas = malloc(sizeof(int) * N); // �������� ������ ��� ������
	init_mas(Name_file, Mas); // ������������� �������
	N = elm_add(Mas, N); // ���������� ������ ��������
	N = max_elm_remove(Mas, N); // �������� �������� � ������������ ���������
	N = elm_remove(Mas, N); // �������� �������� � �������� ���������
	elm_search(Mas, N); // ����� ��������
	elm_change(Mas, N); // ��������� ��������
	return 0;
}
