#include <iostream>
/*
    std�� c++ ǥ�� ���̺귯���� ��� �Լ� ��ü ���� ���ǵȰ�
    namespace�� � ���ǵ� ��ü�� ���� ��� �Ҽ����� �������ִ°Ͱ� ������
*/

namespace A {
    void printAll() {
        std::cout << "A��?printAll?�Լ�" << std::endl;
    }
}

namespace B {
    void printAll() {
        std::cout << "B�� printAll?�Լ�" << std::endl;
    }
}


int main(void)
{
    A::printAll();
    B::printAll();
    return 0;
}
