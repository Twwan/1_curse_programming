#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void firstpoint(double *x0, double *x1, double h, double (*function)(double)){ // первый шаг численного метода
	while (function(*x1) < function(*x0)){
		*x0 = *x1;
		*x1 += h;
	}
}

void secondpoint(double *x0, double *x1, double h, double (*function)(double)){ // второй шаг численного метода
	while (function(*x1) > function(*x0)){
		*x0 = *x1;
		*x1 += h;
	}
}

double first_function(double x){
	return 3 * pow(x, 4) - 4 * pow(x, 3) - 12 * x + 2;
}

double second_function(double x){
	return -4 * pow(x, 3) + 7 * x - 5 * pow(x, 2) + 2;
}

double third_function(double x){
	return x - pow(x, 3) / 6 + pow(x, 5) / 120;
}

double find_min(double start, double eps, double(*function)(double)){
    double h = 0.01;
    double x0 = start;
    double x1 = x0 + h;

    firstpoint(&x0, &x1, h, function);

    if(fabs(x0 - x1) < eps){
        return x0;
    }

    else{
        h = -h / (double) 4;
        firstpoint(&x0, &x1, h, function);
    }

    if(fabs(fabs((x0-x1)))<eps){
        return x0;
    }

    else{
        h = -h / (double) 3;
        secondpoint(&x0, &x1, h, function);
    }

}

double find_max(double start, double eps, double (*function)(double)){
	double h = 0.01;
	double x0 = start;
	double x1 = x0 + h;

	secondpoint(&x0, &x1, h, function);

	if (fabs(x0 - x1) < eps){
		return x0;
	}
	else{
		h = -h / (double) 4;
		firstpoint(&x0, &x1, h, function);
	}
	if (fabs(fabs(x0-x1) < eps)){
		return x0;
	}
	else{
		h = -h / (double) 3;
		secondpoint(&x0, &x1, h, function);
	}
}

int main(){
	system("chcp 1251");
	double eps;
	printf("eps = ");
	scanf("%lf", &eps);

	printf("\nточка минимума первой функции: %lf | результат: %lf | +eps: %lf | -eps: %lf", find_min(-4.0, eps, first_function),
		first_function(find_min(-4.0, eps, first_function)), first_function(find_min(-4.0, eps, first_function) + eps),
		first_function(find_min(-4.0, eps, first_function) - eps));
	printf("\n\nточка минимума второй функции: %lf | результат: %lf | +eps: %lf | -eps: %lf", find_min(-2.0, eps, second_function),
		second_function(find_min(-2.0, eps, second_function)), second_function(find_min(-2.0, eps, second_function) + eps),
		second_function(find_min(-2.0, eps, second_function) - eps));
	printf("\nточка максимума второй функции: %lf | результат: %lf | +eps: %lf | -eps: %lf", find_max(-0.5, eps, second_function),
		second_function(find_max(-0.5, eps, second_function)), second_function(find_max(-0.5, eps, second_function) + eps),
		second_function(find_max(-0.5, eps, second_function) - eps));
	printf("\n\n(1) точка минимума третьей функции: %lf | результат: %lf | +eps: %lf | -eps: %lf", find_min(2.0, eps, third_function),
		third_function(find_min(2.0, eps, third_function)), third_function(find_min(2.0, eps, third_function) + eps),
		third_function(find_min(2.0, eps, third_function) - eps));
	printf("\n(2) точка минимума третьей функции: %lf | результат: %lf | +eps: %lf | -eps: %lf", find_min(-2.0, eps, third_function),
		third_function(find_min(-2.0, eps, third_function)), third_function(find_min(-2.0, eps, third_function) + eps),
		third_function(find_min(-2.0, eps, third_function) - eps));
	printf("\n(1) точка максимума третьей функции: %lf | результат: %lf | +eps: %lf | -eps: %lf", find_max(-4.0, eps, third_function),
		third_function(find_max(-4.0, eps, third_function)), third_function(find_max(-4.0, eps, third_function) + eps),
		third_function(find_max(-4.0, eps, third_function) - eps));
	printf("\n(2) точка максимума третьей функции: %lf | результат: %lf | +eps: %lf | -eps: %lf", find_max(1.0, eps, third_function),
		third_function(find_max(1.0, eps, third_function)), third_function(find_max( 1.0, eps, third_function) + eps),
		third_function(find_max(1.0, eps, third_function) - eps));
}