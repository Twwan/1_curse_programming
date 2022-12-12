#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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

void MassPrint(int* x, int n){
 int i;
 srand(time(NULL) + rand());
 for(i=0;i<n;i++){
  x[i] =rand() % 8;
  printf(" %d ", x[i]);
 }
}

int main(){
    system("chcp 1251");
    FILE *f = fopen("spreedsheet.csv", "w");

    int n = 100, s, k, temp, temp1, l;
    temp = temp1;
    temp1 = (temp - 1) / 3;
    if (temp1 < 1 && temp != 1){
        temp1 = 1;
        }
    while(n <= 10000){
        s = 0;
        int *x=(int *)malloc(n*sizeof(int));
        for(k = 0; k < 5; k++){
            MassPrint(x,n);
            s=sort_v(x, n, temp1);
        }
        free(x);
        fprintf(f, "%d; %d\n", n, s/5);
        if (n < 1000)
            n += 100;
        else
            n += 1000;
    }
    fclose(f);
    printf("Выполнено!");
    return 0;
}