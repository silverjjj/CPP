#include <iostream>

/*
    ����(char) �� ������ ���ڿ� ����, C ���ڿ� (char *) �� ������ ����
    ���ڿ� ���̸� ���ϴ� �Լ�
    ���ڿ� �ڿ� �ٸ� ���ڿ� ���̱�
    ���ڿ� ���� ���ԵǾ� �ִ� ���ڿ� ���ϱ�
    ���ڿ��� ������ ��
    ���ڿ� ũ�� �� (���� ��)
*/

class MyString {
    char* string_content;       // ���ڿ� �����͸� ����Ű�� ������
    int string_lenght;

    public:
        // �����ε�
        // 1. ���� �ϳ��� ���� ����
        MyString(char c);
        // 2. ���ڿ��κ��� ����
        MyString(const char* str);
        // 3. ���� ������
        MyString(const MyString& str);

};

MyString::MyString(char c)
{
    string_content = new char[1];
    string_content[0] = c;
    string_lenght = 1;
}

MyString::MyString(const char* str)
{
    string_lenght = strlen(str);
    string_content = new char[string_lenght];
    for (int i=0; i<string_lenght; i++)
    {
        string_content[i]=str[i];
    }
}

int main()
{
    
    return 0;
}