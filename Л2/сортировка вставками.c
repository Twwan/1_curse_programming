#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]) {
    system("chcp 1251");
    int n;
    printf("Введите длину массива: ");
    scanf("%d",&n);
    int i, list[n], a, l, count = 0;
    printf("\nИзначальный список: ");
    for (i = 0; i < n; i++){
        list[i] = rand()%256;
        printf("%d ",list[i]);
    }
// 3 7 4 1
// 3 4 7 1
// 1 3 4 7
    for (i = 1; i < n; i++){
        a = list[i]; // запоминаем i (4)
        l = i - 1; // берём l (7)
        while(l >= 0 && list[l] > a){ // пока l (7) не дойдёт до нулевой позиции и не будет при этом а (4)
            list[l+1] = list[l]; // эл l+1 (1) становится элементом l (3 x 7 1)
            l = l - 1; // приближаем l к левой границе
            count+=3;
        }
        list[l+1] = a; // 3 4 7 1 вернули запомненный элемент
        count+=1;
    }
    printf("\nОтсортированный список ");
    for (i = 0; i < n; i++){
        printf("%d ",list[i]);
    }
    printf("\nОбщее количество сравнений и перестановок %d", count);
    return 0;
}