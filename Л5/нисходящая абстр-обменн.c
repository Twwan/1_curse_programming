#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS


void Merge(int *mas, int nach, int m, int kon, int *count){ 
    int i, j, k=nach;
    int x1[kon];
    for (i = m+1; i > nach; i--){
        x1[i-1] = mas[i-1];
    } 
    
    for (j = m; j < kon; j++) {
        x1[kon+m-j] = mas[j+1]; 
    }
    
    while(i<=j){
        if (x1[j] < x1[i]) { //
            mas[k] = x1[j];
            j--;
        }
        else {
            mas[k] = x1[i];
            i++;
        }
        k++;
        (*count)+=2;
    }
}

void split(int*mas, int nach, int kon, int *count){
    int i;
    (*count)++;
    if(kon<=nach) return;
    int m = (nach+kon)/2;
    split(mas, nach, m, count);
    split(mas, m+1, kon, count);
    Merge(mas, nach, m, kon, &count);
}


int main(int argc, char *argv[]) {
    system("chcp 1251");
    srand(time(NULL));
    int n,count=0;
    printf("Введите длину массива: ");
    scanf("%d",&n);
    printf("Стартовый массив: \n");
    int mas[n],i;
    for(i = 0;i<n;i++){
        mas[i] = rand()%150;
        printf("%d ",mas[i]);
    }
    split(&mas, 0, n-1, &count);
    
    printf("\nКонечный массив: \n");
    for(i = 0;i<n;i++)  printf("%d ",mas[i]);
    printf("\nКоличество перестановок и сравнений: %d", count);
    return 0;
}
