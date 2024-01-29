/* ���� �Ҵ��� Ȱ�� */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int student;
    int i, input;
    int *score;
    int sum = 0;

    printf("�л��� ���� ? : ");
    scanf("%d", &student);

    /*
        malloc : memory allocation�� ����
        void* malloc(size_t size)
        1. (sizeof(int) * student) byte��ŭ heap ������ �޸� �Ҵ�
        2. void* -> int*�� ĳ���� (����ȯ)
        3. �ش� �޸� ������ int *score�� ����

        free : �޸��� ����
        void free(void *ptr);
        ptr : �����ϰ��� �ϴ� �޸��� ������
    */
    score = (int *)malloc(sizeof(int) * student);
    
    for (i = 0; i < student; i++)
    {
        printf("�л� %d�� ���� : ", i );
        scanf("%d", &input);
        score[i] = input;
        sum += input;
    }
    
    printf("��ü �л� ��� ���� : %d \n", sum / student);

    free(score);
    return 0;
}