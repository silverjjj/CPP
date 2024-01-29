// ���۷����� �����ϴ� �Լ�
#include <iostream>

class A {
    int x;

 public:
    A(int c) : x(c) {}

    int& access_x() { return x; }
    int get_x() { return x; }
    void show_x() { std::cout << this->x << std::endl; }
};

int main() {
    A a(5);
    a.show_x();

    int& c = a.access_x();  // c�� a�� ������,, ���ÿ� ���� �ּҸ� ����Ų��.
                            // c�� a�� �����̶�� �����ϸ��,, ���� ���� �������ε� �̸��� �޶���
    c = 4;
    a.show_x();

    int d = a.access_x();  // a�� ���� 4�� d�� �׳� ���°�,,
    d = 3;
    a.show_x();

    // �Ʒ��� ����
    // int& e = a.get_x();
    // e = 2;
    // a.show_x();

    int f = a.get_x();
    f = 1;
    a.show_x();
}