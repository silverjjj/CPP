/*
    �Ҹ��� ȣ�� Ȯ���ϱ�
*/
#include <string.h>
#include <iostream>

class Test {
    private:
        char c;
    
    public:
        Test(char _c);
        ~Test();
};

Test::Test(char _c) 
{
    c = _c;
    std::cout << "������ ȣ�� " << c << std::endl;
}

Test::~Test()
{
    std::cout << "�Ҹ��� ȣ�� " << c << std::endl;
}

void simple_function() 
{ 
    Test b('b'); 
}


int main() {
  Test a('a');
  simple_function();
}

/*
    ������ ȣ�� a
    ������ ȣ�� b
    �Ҹ��� ȣ�� b
    �Ҹ��� ȣ�� a
*/