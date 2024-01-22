/*
    char vs string
    char
        - ũ�Ⱑ �������ְ�, �����Ҵ�
        - ���� �Լ��� ����, strcpy, strcat, strlen ���� �Լ��� ����ؾ���
    
    string
        - ũ�� ����, �����Ҵ�
        - ���� �Լ��� ����, �޸� �Ҵ�� ����, �Լ� ȣ��� ������尡 �߻��� �� ����
*/

// #include <string.h>
#include <iostream>

class string {
    private:
        char *str;
        int len;

 public:
    string(char c, int n);  // ���� c �� n �� �ִ� ���ڿ��� ����
    string(const char *s);
    string(const string &s);
    ~string();

    void add_string(const string &s);   // str �ڿ� s �� ���δ�.
    void copy_string(const string &s);  // str �� s �� �����Ѵ�.
    int strlen();                       // ���ڿ� ���� ����
    void string_status();
};


string::string(char c, int n)
{
    len = n;
    str = new char[len + 1];
    for (int i = 0; i < len; i++) {
        str[i] = c;
    }
    str[n] = '\0';

    std::cout << "�⺻ ������ 1 : " << str << std::endl;
}

string::string(const char *s)
{
    
    len = 0;
    while (s[len] !='\0')
        len ++;

    // �⺻ �����ڿ��� �����Ҵ�� name�� ���, ���� �����ڿ����� �ٽ� �����Ҵ��ؾ��Ѵ�.
    str = new char[len+1];

    for (int i=0; i < len; i++)
        str[i] = s[i];
    
    str[len]='\0';
    std::cout << "�⺻ ������ 2 : " << str << std::endl;
}

string::string(const string &s)
{
    len = s.len;
    str = new char[len+1];
    for (int i=0; i < len; i++)
        str[i] = s.str[i];
    
    str[len] = '\0';
    std::cout << "���� ������ : " << str << std::endl;
}

string::~string()
{
    if (str) delete[] str;
    std::cout << "�Ҹ� ������" << std::endl;
}

void string::add_string(const string &s)
{
    char* tmp = new char[len + s.len + 1];
    for (int i = 0; i < (len + s.len + 1); i++) 
    {
		if (i < (len)) {
			tmp[i] = str[i];
		}
		else if (i >= len) {
			tmp[i] = s.str[i-len];
		}
	}

    for (int i = 0; i < len + s.len; i++) {
		str[i] = tmp[i];
	}
    str[len + s.len] = '\0';
	delete[] tmp;
	std::cout << "���� ���ڿ��� �߰��� ��� : "<< str<< std::endl;
}

void string::copy_string(const string &s)
{
    delete str;
    str = new char[s.len+1];
    str = s.str;
    len = s.len;
    std::cout << "���� ���� : "<< str << std::endl;
}

void string::string_status()
{
    std::cout << "���� ���ڿ� : " << str << std::endl;
}

int string::strlen() 
{
    return len;
}

int main()
{
    string a('a', 10);      // �⺻ ������
    string b("ssss");       // �⺻ ������
	string c(a);            // ���� ������
    c.add_string(b);        
    c.copy_string(b);
    c.string_status();
    std::cout << "���� ���ڿ� ũ�� : " << c.strlen() << std::endl;
}