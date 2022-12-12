#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char Name[30];
	int Cost;
	struct Second{
		char Available[5];
		char Anothers[30];
	} Second;
} Medicines;

Medicines *Add(Medicines *x){
	FILE *f = fopen("123.txt", "r");
	int i, n;
	fscanf(f, "%d", &n);
	Medicines a;
	for(i=0;i<n;i++){
		fscanf(f, "%s", a.Name);
		fscanf(f, "%s", a.Cost);
		fscanf(f, "%s", a.Second.Available);
		fscanf(f, "%s", a.Second.Anothers);
		x[i] = a;
	}
	fclose(f);
	return x;
}

void Find(Medicines *x,int n){
	char name[10];
	char nal[5] = "Есть";
	int i;
	printf("Введите наименование лекарства: ");
	scanf("%s", &name);
	printf("Подходящие лекарства:\n\n");
	for(i=0;i<n;i++){
		if(strcmp(x[i].Name, name)==0){
			if(strcmp(x[i].Second.Available, nal)==0){
				printf("%s | %sр | %s\n",x[i].Name, x[i].Cost, x[i].Second.Available);
				continue;
			}
			else{
				printf("'%s' нет в наличии", name);
				printf("\nЗаменители в наличии:\n %s", x[i].Second.Anothers);
			}
		}
	}
}

int main(int argc, char *argv[]) {
	system("chcp 1251");
	int n;
	Medicines *x = NULL;
	FILE *f = fopen("123.txt", "r");
	fscanf(f, "%d", &n);
	fclose(f);
	x = (Medicines*)realloc(x,sizeof(Medicines)*(n+1));
	x = Add(x);
	Find(x,n);
	return 0;
}
