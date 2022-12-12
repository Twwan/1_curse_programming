#include <stdio.h>
#include <stdlib.h>


void lsd_sort(char* arr, int len){
    int temp[len][len];
	int i, j, k = 0, n = 1, lsd;
    int order[len];
    for (i = 0; i < len; i++) order[i] = 0;

    while (n <= len){
        for (i = 0; i < len; i++){
            lsd = ((arr[i] / n) % 10);
            temp[lsd][order[lsd]] = arr[i];
            order[lsd]++;
        }
        for (i = 0; i < len; i++){
            if (order[i] != 0)
                for (j = 0; j < order[i]; j++){
                    arr[k] = temp[i][j];
                    k++;
                }
            order[i] = 0;
        }
        n *= 10;
        k = 0;
        printf("\n");
    }
}

void mass_print(char **mass, int len, int count) {
	int i, j;
    for (j = 0; j < count; j++){
        printf("%d) ", j);
        for (i = 0; i < len; i++)
            printf("%c", mass[j][i]);
        printf("\n");
    }
}

char *arr_gen(int len){
	int i;
    char* arr = (char*)malloc(sizeof(char)*len);
    for (i = 0; i < len; i++)
        arr[i] = (char)(rand()%(57-48+1)+48);
    return arr;
}

char **get_str_arr(int len, int count) {
	int i;
    char **mass = (char **)malloc(count*sizeof(char *));
    for (i = 0; i < count; i++){
        mass[i] = arr_gen(len);
    }
    return mass;
}

int main(){
    system("chcp 1251");

    int size,count;
    printf("¬ведите длину строки: ");
    scanf("%d", &size);

    printf("¬ведите количеcтво строк: ");
    scanf("%d", &count);

    char **mass = get_str_arr(size, count);
    mass_print(mass, size, count);

    printf ("\nќтсортированный массив: \n");
    lsd_sort(mass, size);
    mass_print(mass, size, count);
    return 0;
}
