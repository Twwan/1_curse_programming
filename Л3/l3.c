#include <stdio.h>
#include <stdlib.h>

int sort_v(int n){
    int i, j, list[n], temp, count = 0, min = 0;;
    for (i = 0; i < n; i++)
        list[i] = rand()%256;

    for(i = 1; i<n; i++){
        count++;
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
        count++;
        while(list[j-1] >= temp){
            list[j] = list[j-1];
            count++;
            j--;
        }
        list[j] = temp;
        count++;
    }
    return count;
}

int main(){
    FILE *f = fopen("spreedsheet.csv", "wb");
    system("chcp 1251");
    int n = 100, s, k;
    while(n <= 10000){
        s = 0;
        for(k = 0; k < 5; k++)
            s += sort_v(n);

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