#include <stdio.h>
#include <stdlib.h>


void lsd_sort(char **mas, int leng, int count){ 
    int i,j,p,k,g;
    char tempmas[count][leng];
    for(i=0; i<leng; i++){
        k = 0;
        int temp[256];
        for(j=0; j<256; j++) temp[j] = 0;
        for(j=0; j<count; j++) temp[((int)mas[j][leng-i-1])]++;
        for(j=0; j<256; j++) if(temp[j] != 0){
            for(p=0; p<count; p++) if((int)mas[p][leng-i-1] == j){
                for(g=0; g<leng; g++) tempmas[k][g] = mas[p][g];
                k++;
            }
        }
        for(g=0; g<count; g++){
            for(j=0; j<leng; j++){
                mas[g][j] = tempmas[g][j];
            }
        }
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
    lsd_sort(mass, size, count);
    mass_print(mass, size, count);
    return 0;
}
