#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>
#include <math.h>


void file_read(char* file){
	int m, n;
	FILE* f = fopen(file, "r");
	if (f == NULL){
		printf("Файл не найден. \n");
		system("pause");
		return;
	}
	int i, j;
	int a;
	fscanf(f, "%d", &n);
	fscanf(f, "%d", &m);
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			fscanf(f, "%d", &a);
			printf("%5d", a);
		}
		printf("\n");
	}
	fclose(f);
	printf("\n\n");
}
void file_str(char* file){
	int m, n;
	FILE* f = fopen(file, "r");
	if (f == NULL) {
		printf("Файл не найден. \n");
		system("pause");
		return;
	}
	int i, j; float a, b;
	fread(&n, sizeof(int), 1, f);
	fread(&m, sizeof(int), 1, f);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			fread(&b, sizeof(float), 1, f);
			fread(&a, sizeof(float), 1, f);
		}
	}
}

int det(int** a, int n){
	if (n == 1)
		return a[0][0];
	else if (n == 2)
		return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	else {
		int dt = 0;
		for (int k = 0; k < n; k++) {
			int** m = new int* [n - 1];
			for (int i = 0; i < n - 1; i++){
				m[i] = new int[n - 1];
			}
			for (int i = 1; i < n; i++) {
				int c = 0;
				for (int j = 0; j < n; j++){
					if (j == k)
						continue;
					m[i - 1][c] = a[i][j];
					c++;
				}
			}
			dt += pow(-1, k + 2) * a[0][k] * det(m, n - 1);
		}

		return dt;
	}
}
void obratnaya(double** A, int N){
	double temp;
	double** E = (double**)malloc((N) * sizeof(int*));
	for (int i = 0; i < N; i++)
		E[i] = (double*)malloc(N * sizeof(int));
	

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++){
			E[i][j] = 0.0;
			if (i == j)
				E[i][j] = 1.0;
		}

	for (int k = 0; k < N; k++){
		temp = A[k][k];

		for (int j = 0; j < N; j++){
			A[k][j] /= temp;
			E[k][j] /= temp;
		}

		for (int i = k + 1; i < N; i++){
			temp = A[i][k];

			for (int j = 0; j < N; j++){
				A[i][j] -= A[k][j] * temp;
				E[i][j] -= E[k][j] * temp;
			}
		}
	}

	for (int k = N - 1; k > 0; k--){
		for (int i = k - 1; i >= 0; i--){
			temp = A[i][k];

			for (int j = 0; j < N; j++){
				A[i][j] -= A[k][j] * temp;
				E[i][j] -= E[k][j] * temp;
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			A[i][j] = E[i][j];
}



int main(){
	setlocale(LC_ALL, "Rus");

	char A[30] = "A.txt";
	char B[30] = "B.txt";

	printf("Матрицы в файлах\n");
	printf("A:\n");
	file_read(A);
	printf("B:\n");
	file_read(B);
	FILE* f = fopen("A.txt", "r");
	FILE* f1 = fopen("B.txt", "r");
	int i, j, n[2], m[2];

	fscanf(f,"%d", &n[0]);
	fscanf(f,"%d", &m[0]);
	fscanf(f1,"%d", &n[1]);
	fscanf(f1,"%d", &m[1]);

	int** A1 = (int**)malloc(3 * sizeof(int*));
	for (i = 0; i < 3; i++)
		A1[i] = (int*)malloc(3 * sizeof(int));
	int** B1 = (int**)malloc(3 * sizeof(int*));
	for (i = 0; i < 3; i++)
		B1[i] = (int*)malloc(3 * sizeof(int));
	int a, b;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			fscanf(f, "%d", &a);
			fscanf(f1, "%d", &b);
			A1[i][j] = a;
			B1[i][j] = b;
		}
	}
	int det_A = det(A1, n[0]);
	int det_B = det(B1, n[0]);
	if (det_A == 0 || det_B == 0){
		printf("det = 0!");
		system("pause");
		return 0;
	}
	printf("det A = %d\ndet B = %d", det_A, det_B);

	double** A2 = (double**)malloc(3 * sizeof(double*));
	for (i = 0; i < 3; i++)
		A2[i] = (double*)malloc(3 * sizeof(double));
	for (i = 0; i < 3; i++) 
		for (j = 0; j < 3; j++)
			A2[i][j] = A1[i][j];
	printf("\n\nОбратная матрица А:\n");
	obratnaya(A2, 3);
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			printf("%5.3lf  ", A2[i][j]);
		}
		printf("\n");
	}

	double** X = (double**)malloc(3 * sizeof(double*));
	for (i = 0; i < 3; i++)
		X[i] = (double*)malloc(3 * sizeof(double));

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++){
			X[i][j] = 0;
			for (int k = 0; k < 3; k++)
				X[i][j] += A2[i][k] * B1[k][j];
		}

	printf("\nX:\n");
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			printf("%5.3lf  ", X[i][j]);
		}
		printf("\n");
	}
	return 0;
}