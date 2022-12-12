#include <stdlib.h>
#include <stdio.h>
#include "hw3_func.h"

int main(){
	system("chcp 1251");
	char Name_file[50]; // Сюда сохраним название файла
	printf("Введите название файла: ");
	scanf("%s", &Name_file);
	int *Mas = NULL; // Создадим указатель
	int N;
	N = get_size_mas(Name_file); // Взятие размерности массива
	Mas = malloc(sizeof(int) * N); // Выделяем память под массив
	init_mas(Name_file, Mas); // Инициализация массива
	N = elm_add(Mas, N); // Добавление нового элемента
	N = max_elm_remove(Mas, N); // Удаление элемента с максимальным значением
	N = elm_remove(Mas, N); // Удаление элемента с заданным значением
	elm_search(Mas, N); // Поиск элемента
	elm_change(Mas, N); // Изменение элемента
	return 0;
}
