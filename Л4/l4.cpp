#include <iostream>
#include <time.h>
#include <fstream>
#include <cmath>
#include <windows.h>

using namespace std;

int main()
{
    system("chcp 1251");
    srand(time(NULL));
    int N=100;
    int s=0, k = 0;
    int d[N];
    int i = 1;
    d[0] = 1;
    int count=0;
    while(N<=10000)
    {
        while (d[i] < N) {
            i++;
            d[i] = pow(2, i) - 1;
        }
        count = i;
        int mass[N];
        for (int z = 0; z < 5; z++) {
            for (int i = 0; i < N; i++) {
                mass[i] = rand() % 100 - 50;
            }
            for (int i = count; i > 0; i--) {
                s++;
                for (int j = 0; j < N - d[i]; j++) {
                    k = j;
                    s += 2;
                    while (k >= 0 && mass[k] > mass[k + d[i]]) {
                        int temp = mass[k];
                        mass[k] = mass[k + d[i]];
                        mass[k + d[i]] = temp;
                        k=k-d[i];
                        s += 2;
                    }
                }
            }
        }
        ofstream F;
        F.open("spreedsheet.csv",ios_base::app);
        F << N << "; " << s / 5 << "\n";
        F.close();
        s = 0;
        if (N < 1000)
        {
            N=N+100;
        }
        else
        {
            N=N+1000;
        }
    }
}
