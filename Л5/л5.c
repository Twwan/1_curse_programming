#include <stdio.h>
#include <stdlib.h>

void Merge(int *mas, int nach, int m, int kon, int *count){ 
	int i, j,k=nach;
	int x1[kon];
	for (i = m+1; i > nach; i--){
		x1[i-1] = mas[i-1];
	} 
	
	for (j = m; j < kon; j++) {
		x1[kon+m-j] = mas[j+1];	
	}
	
	while(i<=j){
		if (x1[j] < x1[i]) {
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
	Merge(mas,nach, m, kon, count);
}


int sort(int n){
	int mas[n],i,count = 0;
	for(i = 0;i<n;i++){
		mas[i] = rand()%200;
	}	
	split(&mas, 0, n-1, &count);
	return count;
}

int main() {
	srand(time(NULL));
	int n=100;
	FILE *f = fopen("tabl.csv", "wb");
	while(n<=10000){
		int k;
		unsigned long s = 0;
		for(k=0;k<5; k++){
			s+=sort(n);
		}
		fprintf(f, "%d; %d\n", n, s/5);
		printf("%lu %d\n",s/5,n);
		if(n<1000) n+= 100;
		else n+=1000;
	}
	fclose(f);
}

