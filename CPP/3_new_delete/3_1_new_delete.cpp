/* new �� delete �� ��� 
    c++������ malloc�� free �Լ��� ����Ͽ� �޸� �Ҵ��� �Ҽ� ������,,
    c++ �������� �����Ҵ��� ���� �����ϴ°��� new�� delete�̴�.
*/

#include <iostream>

int main() {
    /*
        �⺻ ��� ����
        int ũ���� ������ new�� �Ҵ��Ͽ� �� �ּҰ��� p�� ����
        ���� : type* pointer = new type
    */
    int* p = new int;
    *p = 10;
    std::cout << *p << std::endl;
    delete p;

    /* new�� �迭 �Ҵ��ϱ�*/
    int arr_size;
    std::cout << "array size : ";
    std::cin >> arr_size;

    int *list = new int[arr_size];

    for (int i=0; i < arr_size; i++)
    {
        std::cin >> list[i];
    }

    for (int i=0; i < arr_size; i++)
    {
        std::cout << i << "th element of list : " << list[i] << std::endl;
    } 

    // new []�� �̿��Ͽ� �Ҵ�������,, delete[]�� ������ �ؾ���..
    delete[] list;

    return 0;
}