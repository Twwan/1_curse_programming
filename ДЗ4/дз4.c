#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
//Реализовать алгоритм интерполяционного поиска, el - элемент, который должен быть найден, [begin,end] задает область поиска
int interpolation_search(int* arr, int begin, int end, int el) {
    int mid = 0;
    //Если [begin, end] не существует, возвращается значение -1
    if (begin > end) {
        return -1;
    }
    //Если в области поиска есть только один элемент, определить, является ли он искомым элементом
    if (begin == end) {
        if (el == arr[begin]) {
            return begin;
        }
        //Если элемент не является целевым элементом, поиск завершается ошибкой
        return -1;
    }
    //Найдём местоположение "промежуточного элемента"
    mid = begin + ((end - begin) / (arr[end] - arr[begin]) * (el - arr[begin]));
    //Рекурсивный выход
    if (el == arr[mid]) {
        return mid;
    }
    //Сравним значения el и arr[mid], чтобы сузить области, в которых может существовать el
    if (el < arr[mid]) {
        //Новая область поиска - [begin, mid-1]
        return interpolation_search(arr, begin, mid - 1, el);
    }
    else {
        //Новая область поиска -[mid+1,end]
        return interpolation_search(arr, mid + 1, end, el);
    }
}

int main()
{
    system("chcp 1251");
	printf("421-4 Неборский\n\n");
	
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int begin = 0;
    int end = 9;
    int element = 5.5;


    int pos = interpolation_search(arr, begin, end, element);
    if (pos != -1) {
        printf("%d", interpolation_search(arr, begin, end, element));
    }
    else {
        printf("Can't find.");
    }
    return 0;
}
