#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sort_v(int x[], int n, int temp)
{
    int newElement, i, sum;
    int d = 0;
    int count = 0;
    for (i = 1; i < n; i++)
    {
        newElement = x[i];
        int j = i - temp;
        
        while(j > 0 && x[j] > newElement)
        {
            x[j+temp] = x[j];
            j = j - temp;
            count += 1;
            d += pow(2, i)-1;
        }
        x[j+temp] = newElement;
        count += 1;
    }
  sum = count + d;
  return sum;
}

int main(int argc, char *argv[]) {
    system("chcp 1251");
    unsigned int n;
    int i, temp, temp1;
    
    printf("Количество элементов массива n: ");
    scanf("%u", &n);
    
    temp = n;
    temp1 = (temp - 1) / 3;
    int x[n];
    
    printf("\nЭлементы массива: ");
    for(i = 0; i < n; i++){
        x[i] = rand() % 100;
        printf("%d ", x[i]);
    }
   
    if (temp1 < 1){
        temp1 = 1;
    }
    
    while (temp1 >= 1){
        
    sort_v(x, n, temp1);
    

    temp = temp1;
    temp1 = (temp - 1) / 3;
    if (temp1 < 1 && temp != 1){
        temp1 = 1;
        }
    }
    printf("\nСортированный массив: ");
    for (i = 1; i < n; i++)
        printf("%d ", x[i]);
    printf("\n");
    
    return 0;
}
