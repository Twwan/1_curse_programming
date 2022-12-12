#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]) {
    system("chcp 1251");
    int n;
    printf("Введите длину массива: ");
    scanf("%d",&n);
    int i, j, list[n], temp, srav = 0, count = 0;
    int min = 0;
    printf("\nИзначальный список: ");
    for (i = 0; i < n; i++){
        list[i] = rand()%256;
        printf("%d ",list[i]);
    }
    for(i = 1; i<n; i++){
        srav++;
        if(list[i]<list[min])
            min = i;
    }
    temp = list[min];
    list[min] = list[0];
    list[0] = temp;
    count += 3;
    for (i = 2; i < n; i++){
        temp = list[i];
        j = i;
        while(list[j-1] >= temp){
            list[j] = list[j-1];
            count++;
            srav ++;
            j--;
        }
        list[j] = temp;
        count++;
    }
    printf("\nОтсортированный список ");
    for (i = 0; i < n; i++){
        printf("%d ",list[i]);
    }
    printf("\nОбщее количество сравнений и перестановок %d", count);
    return 0;
}
