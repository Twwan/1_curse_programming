#include <stdlib.h>
#include <stdio.h>
#include "hw3_func.h"


// Взятие размерности массива
int get_size_mas(char *name_file){
	FILE *file = fopen(name_file, "r");
	int n;
	fscanf(file, "%d", &n);
	fclose(file);
	return n;
}

// Инициализация массива
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

// Вывод массива
void print_mas(int *mas, int n){
	int i;
	printf("Массив: ");
	for(i = 0; i < n; i++){
		printf("%d ", *(mas+i));
	}
}

// Добавление нового элемента
int elm_add(int *mas, int n){
	mas = realloc(mas, sizeof(int) * (n+1));
	printf("\nВведите новый элемент: ");
	scanf("%d", &mas[n]);
	print_mas(mas, n + 1);
	return n + 1;
}

// Удаление элемента с максимальным значением
int max_elm_remove(int *mas, int n){
	int max_elm = max_search(mas, n);
	int i;
	for(i = max_elm + 1; i < n; i++){
		mas[i - 1] = mas[i];
	}
	mas = realloc(mas, sizeof(int) * (n - 1));
	printf("\nЭлемент с максимальным значением был удалён\n");
	print_mas(mas, n - 1);
	return n - 1;
}

// Поиск максимального элемента
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

// Удаление элемента с заданным значением
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
	printf("Искомый элемент был удалён\n");
	print_mas(mas, n - 1);
	return n - 1;
}

// Поиск элемента
int search(int *mas, int n){
	int elm, flag = 0;
	printf("\nВведите значение элемента, который хотите удалить: ");
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

// Поиск элемента
void elm_search(int *mas, int n){
	int elm;
	printf("\nВведите значение искомого элемента: ");
	scanf("%d", &elm);
	int i;
	printf("Индекс искомого элемента: ");
	for(i = 0; i < n; i++){
		if(mas[i] == elm){
			printf("%d ", i);
			break;
		}
	}
}

// Изменение элемента
void elm_change(int *mas, int n){
	int elm;
	printf("\nВведите значение элемента, который хотите изменить: ");
	scanf("%d", &elm);
	int i;
	for(i = 0; i < n; i++){
		if(mas[i] == elm){
			printf("Введите новое значение: ");
			scanf("%d", &(mas[i]));
			break;
		}
	}
	print_mas(mas, n);
}
