/* dynamic memory allocation */
#include <iostream>
#include <stdlib.h>
/*
    ���� �޸� �Ҵ��̶�?
    �� �״�� �Է��� �޴� ��� �޸𸮿� ũ�⸦ �Ҵ��ϴ°�
*/

int main(int argc, char **argv)
{
    int SizeOfArray;
    int *arr;

    printf (" ����� ���� �迭�� ���� �� : " );
    scanf("%d", &SizeOfArray);
    
    // int arr[SizeOfArray] �� ������ ũ���� �迭�� ����
    arr = (int *)malloc(sizeof(int) * SizeOfArray);
    /*  
        malloc : heap ������ �޸𸮸� �Ҵ�
        (int *) : malloc�� return�� void* �̹Ƿ� (int*)�� ����ȯ �ϴ°�
        sizeof(int) : sizeof()�� ��ȣ�ȿ� �ڷ��� Ÿ���� �������� �������ֱ� ����
        sizeof(int) * SizeOfArray : �޸𸮸� int type * SizeOfArray ũ��� �Ҵ�

        sizeof(int) * SizeOfArray ũ�⸦ int ������ ����ȯ �Ͽ� arr�� �־��ش�.
    */

    // free : arr�� �پ����� �����ϴ� �Լ� 
    // free�� ���� memory leak�� ����
    free(arr);  



    return 0;
}