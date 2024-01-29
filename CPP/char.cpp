#include <iostream>

int main()
{
    /*
        char
        char�� 1byte �����̴�. �� ���� �ϳ��� ���ϴ°��̸�, 
        ���ư� 2byte�� �ѱ۰��� ���� ���̰� �����ʾ� ������.
        �׸��� char�� ������ �־ ASCII �ڵ�� �ؼ��Ѵ�.
    */
    char singleChar  = 65;
    std::cout << "singleChar : " << singleChar << std::endl;

    char singleChar2 = 'b';
    std::cout << "singleChar2 : " << singleChar2 << std::endl;

    /*
        char*   : ������ �����μ� ���ڿ��� �ּҰ��� ��´�
        char*�� ���ڿ��� ��Ÿ���°�
        ������ ������ ������ ���ڿ��� ��� ���� �����
        char * str ="�����ٶ󸶹ٻ�" �� �� �����Ͱ� ������ 
        ù ���� ���� ���ڿ��� ���� �ּ�(�����ٶ󸶹ٻ翡�� '��')�� ����Ŵ
    */
    const char* cStyleString  = "abcd";
    std::cout << "cStyleString  : " << cStyleString  << std::endl;

    /*
        char[]
        char[]�� ���ڿ��� ��Ÿ���µ� ���Ǵ� ���� ũ�� �迭�̴�.
    */
    char fixedSizeArray[] = "Hello, c++!!";
    std::cout << "fixedSizeArray : " << fixedSizeArray << std::endl;

    /*
        char * vs char[]
        char*�� �����ͷ�, ũ�Ⱑ �����̸� ���ڿ� ������ ���Ṯ���� \n�� ����
        char[]�� �迭��, ũ�Ⱑ ������
    */


    /*
        string
        string�� c++���� �������� ���ڿ��� �ۼ��Ҽ�����
    */
   
   
    std::string myString = "Hello, C++";

    std::cout << myString << std::endl;
    
    std::cout << "length : " << myString.length() << std::endl;

    std::string addString = " Welcomm! ";
    myString += addString;
    std::cout << myString << std::endl;


    // ���� �򰥸��� �κ� : ���ڿ��� ������ ����ϴºκ�
    char cc = 'c';
    char* pointerToChar = &cc;

    std::cout << "cc: " << cc << std::endl; 
    std::cout << "Address of Char: " << &cc << std::endl;
    
    *pointerToChar = 'd';

    std::cout << "cc: " << cc << std::endl; 
    std::cout << "Address of Char: " << &cc << std::endl;
    
    
    return 0;
}