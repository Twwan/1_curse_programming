#include <stdio.h>
#include <stdlib.h>

void create_file(char *name, int n, int m){
	int i;
	FILE *f = fopen(name,"wb");
	if (f==NULL) {
	printf("Ошибка создания файла. \n");
	system("pause");
	return ; 
	}

	for( i=0;i<n*m;i++){
		float z = rand()%200-100;
		fwrite(&z,sizeof(float),1,f);
	}
	fclose(f);
}

void read_file(char *name, int m){
	FILE *f = fopen(name,"rb");
	if (f==NULL) {
	printf("Файл не найден. \n");
	system("pause");
	return ;
	}

	int i = 0;
	float z;
	
	while(!feof(f)){
		if (i>=m&&i%m==0)
			printf("\n");
			if(fread(&z,sizeof(float),1,f)!=1) break;
			printf("%8.3f",z);
			i++;
	}
	fclose(f);
}

void perestan(char *name, int n,int m){
	FILE *f = fopen(name,"rb");
 	FILE *f1 = fopen("temp","wb");
 	int i, j;
 	float z;
 	if (f==NULL) {
		printf("Файл не найден. \n");
		system("pause");
		return ;
	}
	for(j=0;j<n/2;j++){
		for(i=0;i<n/2;i++){
			fseek(f,sizeof(float)*m*(j+1) - sizeof(float)*(n/2-i), SEEK_SET);
			fread(&z,sizeof(float),1,f);
			fwrite(&z,sizeof(int),1,f1);
		}
	}
	fclose(f); 
	fclose(f1); 
	remove(name); 
	rename("temp",name); 
}

int main(int argc, char *argv[]) {
	system("chcp 1251");
	char Fname[30];
	int n,m;
	printf("Введите имя создаваемого файла: ");
	scanf("%s",Fname);
	printf("Введите количество строк: ");
	scanf("%d",&n);
	if(n%2 != 0){
		printf("Количество строк должно быть чётным\n");
		system("pause");
		return ;
	}
	printf("Введите количество столбцов: ");
	scanf("%d",&m);
	if(n>=m){
		printf("Количество строк должно быть меньше количества столбцов \n");
		system("pause");
		return ;
	}
	if((n/m)%2 != 0){
		printf("Итоговое количество строк должно быть четным \n");
		system("pause");
		return ;
	}
	create_file(Fname,n,m);
	read_file(Fname,m);
	perestan(Fname,n,m);
	printf("\n");
	read_file(Fname,n/2);
	return 0;
}
