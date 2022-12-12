#include <iostream>
#include <time.h>
#include <cmath>
#include <fstream>
#include <windows.h>

using namespace std;

int scan() {
    int n;
    printf("Введите количество элементов: ");
    scanf("%d", &n);
    return n;
}

int main() {
    system("chcp 1251");
    srand(time(NULL));
    int n;
    n = scan();
    int s = 0, k = 0;
    int d[n];
    int i = 0, count = -1;
    d[0] = 1;
    while (i < n) {
        i++;
        d[i] = pow(2, i) - 1;
    }
    int mass[n];
    for (int i = 0; i < n; i++) //Рандом цифры в массив
    {
        mass[i] = rand() % 100 - 50;
        printf("%4d", mass[i]);
    } 
    printf("\n");
    for (int i = n; i > 0; i--) //Сортировка
    {
        s++;
        if (d[i] <= n) //Проверяем, чтобы d не превосходил N
        {
            for (int j = 0; j < n - d[i]; j++) //Сравниваем
            {
                k = j;
                s += 2;
                while (k >= 0 && mass[k] > mass[k + d[i]]) {
                    swap(mass[k], mass[k + d[i]]);
                    k--;
                    s += 2;
                }
            }
        }
    }
    printf("Итоговый массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%4d", mass[i]);
    }
    printf("\nКоличество перстановок и сравнений:%d\n", s);
    s = 0;
}
