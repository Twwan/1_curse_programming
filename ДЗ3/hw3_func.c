#include <stdlib.h>
#include <stdio.h>
#include "hw3_func.h"


// ������ ����������� �������
int get_size_mas(char *name_file){
	FILE *file = fopen(name_file, "r");
	int n;
	fscanf(file, "%d", &n);
	fclose(file);
	return n;
}

// ������������� �������
void init_mas(char *name_file, int *mas){
	int n;
	FILE *file = fopen(name_file, "r");
	fscanf(file, "%d", &n);
	int i;
	for(i = 0; i < n; i++){
		fscanf(file, "%d", &mas[i]);
	}
	fclose(file);
	print_mas(mas, n);
}

// ����� �������
void print_mas(int *mas, int n){
	int i;
	printf("������: ");
	for(i = 0; i < n; i++){
		printf("%d ", *(mas+i));
	}
}

// ���������� ������ ��������
int elm_add(int *mas, int n){
	mas = realloc(mas, sizeof(int) * (n+1));
	printf("\n������� ����� �������: ");
	scanf("%d", &mas[n]);
	print_mas(mas, n + 1);
	return n + 1;
}

// �������� �������� � ������������ ���������
int max_elm_remove(int *mas, int n){
	int max_elm = max_search(mas, n);
	int i;
	for(i = max_elm + 1; i < n; i++){
		mas[i - 1] = mas[i];
	}
	mas = realloc(mas, sizeof(int) * (n - 1));
	printf("\n������� � ������������ ��������� ��� �����\n");
	print_mas(mas, n - 1);
	return n - 1;
}

// ����� ������������� ��������
int max_search(int *mas, int n){
	int max_elm = 0;
	int i;
	for(i = 0; i < n; i++){
		if(mas[i] > mas[max_elm]){
			max_elm = i;
		}
	}
	return max_elm;
}

// �������� �������� � �������� ���������
int elm_remove(int *mas, int n){
	int elm = search(mas, n);
	if(elm == '\0'){
		return n;
	}
	int i;
	for(i = elm + 1; i < n; i++){
		mas[i - 1] = mas[i];
	}
	mas = realloc(mas, sizeof(int) * (n - 1));
	printf("������� ������� ��� �����\n");
	print_mas(mas, n - 1);
	return n - 1;
}

// ����� ��������
int search(int *mas, int n){
	int elm, flag = 0;
	printf("\n������� �������� ��������, ������� ������ �������: ");
	scanf("%d", &elm);
	int i;
	for(i = 0; i < n; i++){
		if(mas[i] == elm){
			elm = i;
			flag = 1;
			break;
		}
	}
	if(flag == 0){
		return '\0';
	}
	return elm;
}

// ����� ��������
void elm_search(int *mas, int n){
	int elm;
	printf("\n������� �������� �������� ��������: ");
	scanf("%d", &elm);
	int i;
	printf("������ �������� ��������: ");
	for(i = 0; i < n; i++){
		if(mas[i] == elm){
			printf("%d ", i);
			break;
		}
	}
}

// ��������� ��������
void elm_change(int *mas, int n){
	int elm;
	printf("\n������� �������� ��������, ������� ������ ��������: ");
	scanf("%d", &elm);
	int i;
	for(i = 0; i < n; i++){
		if(mas[i] == elm){
			printf("������� ����� ��������: ");
			scanf("%d", &(mas[i]));
			break;
		}
	}
	print_mas(mas, n);
}
