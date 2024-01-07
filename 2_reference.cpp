// 2. C++ ������(reference)�� ����
#include <iostream>

int change_val(int *p)
{
    *p = 3;
    return 0;
}

void change_val2(int &p)     // reference�� �Լ� ���� �ޱ�
{
    p = 3;
}

int function()
{
    int a4 = 2;
    return a4;
}

int& function2() {
  int a5 = 2;
  return a5;
}

int main()
{   
    // ****** ������ ���� ******
    /*
        c���� change_val �Լ� ���� p�� number�� �ּҰ��� �����Ͽ�,
        *p�� ���� number�� �����Ͽ� number�� ���� 3���� �ٲ�
    */
    int number = 5;
    std::cout << number << std::endl;
    change_val(&number);
    std::cout << number << std::endl;

    /*
        c++������ �ٸ� ������ ����� ����Ű�� ������� �ٸ� ����� ������ 
        �̰��� �ٷ� reference (������)
    */
    int a = 3;
    int& another_a = a;             // a�� reference another_a�� ������
                                    // reference�� ���ϴ� �����, ����Ű���� �ϴ� type�ڿ� &�� ���δ�.
    another_a = 5;
    std::cout << "a : " << a << std::endl;                  // 5
    std::cout << "another_a : " << another_a << std::endl;  // 5

    // reference�� �� �� ������ �Ǹ� ���� �ٸ� ���� ������ �� �� ����.
    int b = 3;
    // int& another_a = b;      // error �߻�



    // ****** �Լ� ���ڷ� ���۷��� �ޱ� ******
    int number2 = 5;
    int gg;
    /*
        change_val2(number2)�� ȣ��ɶ�, ��ǻ�
        "int& p = number" �� ����Ǵ°Ŵ�
        �� ����� �Բ�
        "p�� �ʴ� ������ number�� ���ο� �����̾�!" ��� �����ִ°Ͱ� �ٸ�����.
    */
    std::cout << number2 << std::endl;      // 5
    change_val2(number2);
    std::cout << number2 << std::endl;      // 3
    


    // ****** �������� ������ ���õ� ******
    /*
        y�� x�� reference
        z�� x�� reference
    */
    int x;
    int& y = x;
    int& z = y;

    x = 1;
    std::cout << "x :" << x << ", y : " << y << ", z : " << z << std::endl;     // x :1, y : 1, z : 1

    y = 2;
    std::cout << "x :" << x << ", y : " << y << ", z : " << z << std::endl;     // x :2, y : 2, z : 2
    
    z = 3;
    std::cout << "x :" << x << ", y : " << y << ", z : " << z << std::endl;     // x :3, y : 3, z : 3
    


    // ****** ����� ���� ������ ******
    /*
        literal (���ͷ�)�̶� ? �ҽ��ڵ� �󿡼� ������ ���� ������ ���� ���½��ϴ�.
        Ư�� C������ ""�� ���� �͵��� ���ͷ��̶�� �θ���.
    */
    // ����� 4�� ���ͷ��̶� ��ó�� reference �� ������ �� ����.
    // int &ref = 4;

    // �� ��� �����ڷ� �� ��� ������
    const int &ref = 4;
    int aa = ref;       
    std::cout << "aa : " << aa << std::endl;        // aa : 4


    // ****** ���۷����� �迭�� �迭�� ���۷��� ******
    /*
        reference�� �迭�� �Ұ�����
        �迭�� arr�� �ּҰ� arr[0]�� �ּҷ� ��ȯ�� �ɼ� �־���� ( �ּҰ� �����Ѵٴ°��� �ش� ���Ұ� �޸� �� �����Ѵ� ��� �ǹ�)
        reference�� Ư���� ��찡 �ƴ��̻� �޸� �� ������ ���� ���� �ʴ´�.
        �̷� ��� ������ reference���� �迭�� �����ϴ°��� ������
    */
    int a3;
    int b3;
    // int& arr[2] = {a3,b3};

    
    /*
        �迭���� reference�� ������
    */
    int arr[3] = {1, 2, 3};
    int(&ref2)[3] = arr;        // ref�� arr�� ������

    ref2[0] = 2;
    ref2[1] = 3;
    ref2[2] = 1;
    std::cout << arr[0] << arr[1] << arr[2] << std::endl;

    // 2���� �迭�� ���� ������
    int arr2[3][2] = {1,2,3,4,5,6};
    int(&ref3)[3][2] = arr2;


    // ****** ���۷����� �����ϴ� �Լ� ******
    /*
        function �Լ��� ���� 
        function�� ����Ǹ� �׿� ���ÿ� a4�� �����,
        �̸� �����Ͽ� �Ʒ� ���ø� ����
    */
    int b4 = function();
    std::cout << " b4 : " << b4 << std::endl;

    // �� �κ� ���� �Ȱ�,
    int b5 = function2();

    

    return 0;
}