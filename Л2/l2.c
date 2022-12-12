#include <stdio.h>
#include <stdlib.h>

int sort_v(int n){
    int i, list[n], a, l, count = 0;
    for (i = 0; i < n; i++)
        list[i] = rand()%256;

    for (i = 1; i < n; i++){
        a = list[i];
        l = i - 1;
        while(l >= 0 && list[l] > a){
            list[l + 1] = list[l];
            l = l - 1;
            count += 3;
        }
        list[l + 1] = a;
        count += 1;
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