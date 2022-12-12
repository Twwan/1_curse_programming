#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	system("chcp 1251");
	int n, i;
	printf("Введите мощность множества: ");
	scanf("%d", &n);
	int mas[n];
	printf("\nИзначальное множество: ");
	
	for(i = 0; i < n; i++){
		mas[i] = i + 1;
		printf("%d ", mas[i]);
	}
	printf("\nПерестановки множества: ");
	int k = 0, temp, temp2, count = 0;
	while(k != 1){
		k = n;
		temp2 = mas[0];
		mas[0] = mas[k-1];
		for(i = 1; i < k; i++){
			if(i % 2 != 0){
				temp = mas[i];
				mas[i] = temp2;
				
			}
			else{
				temp2 = mas[i];
				mas[i] = temp;
			}
		}
		while(mas[k-1] == k && k > 1){
			k--;
			temp2 = mas[0];
			mas[0] = mas[k-1];
			for(i = 1; i < k; i++){
				if(i % 2 !=0){
					temp = mas[i];
					mas[i] = temp2;
					
				}
				else{
					temp2 = mas[i];
					mas[i] = temp;
				}
			}
		}
		count++;
		printf("\n%d| ", count);	
		int j;
		for(j = 0; j < n; j++)
			printf("%d ", mas[j]);
	}

	return 0;
}
