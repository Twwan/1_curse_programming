#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]) {
    system("chcp 1251");
    int n;
    printf("������� ����� �������: ");
    scanf("%d",&n);
    int i, list[n], a, l, count = 0;
    printf("\n����������� ������: ");
    for (i = 0; i < n; i++){
        list[i] = rand()%256;
        printf("%d ",list[i]);
    }
// 3 7 4 1
// 3 4 7 1
// 1 3 4 7
    for (i = 1; i < n; i++){
        a = list[i]; // ���������� i (4)
        l = i - 1; // ���� l (7)
        while(l >= 0 && list[l] > a){ // ���� l (7) �� ����� �� ������� ������� � �� ����� ��� ���� � (4)
            list[l+1] = list[l]; // �� l+1 (1) ���������� ��������� l (3 x 7 1)
            l = l - 1; // ���������� l � ����� �������
            count+=3;
        }
        list[l+1] = a; // 3 4 7 1 ������� ����������� �������
        count+=1;
    }
    printf("\n��������������� ������ ");
    for (i = 0; i < n; i++){
        printf("%d ",list[i]);
    }
    printf("\n����� ���������� ��������� � ������������ %d", count);
    return 0;
}