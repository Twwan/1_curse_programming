#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
//����������� �������� ����������������� ������, el - �������, ������� ������ ���� ������, [begin,end] ������ ������� ������
int interpolation_search(int* arr, int begin, int end, int el) {
    int mid = 0;
    //���� [begin, end] �� ����������, ������������ �������� -1
    if (begin > end) {
        return -1;
    }
    //���� � ������� ������ ���� ������ ���� �������, ����������, �������� �� �� ������� ���������
    if (begin == end) {
        if (el == arr[begin]) {
            return begin;
        }
        //���� ������� �� �������� ������� ���������, ����� ����������� �������
        return -1;
    }
    //����� �������������� "�������������� ��������"
    mid = begin + ((end - begin) / (arr[end] - arr[begin]) * (el - arr[begin]));
    //����������� �����
    if (el == arr[mid]) {
        return mid;
    }
    //������� �������� el � arr[mid], ����� ������ �������, � ������� ����� ������������ el
    if (el < arr[mid]) {
        //����� ������� ������ - [begin, mid-1]
        return interpolation_search(arr, begin, mid - 1, el);
    }
    else {
        //����� ������� ������ -[mid+1,end]
        return interpolation_search(arr, mid + 1, end, el);
    }
}

int main()
{
    system("chcp 1251");
	printf("421-4 ���������\n\n");
	
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int begin = 0;
    int end = 9;
    int element = 5.5;


    int pos = interpolation_search(arr, begin, end, element);
    if (pos != -1) {
        printf("%d", interpolation_search(arr, begin, end, element));
    }
    else {
        printf("Can't find.");
    }
    return 0;
}
