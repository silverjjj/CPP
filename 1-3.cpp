#include <iostream>

int main()
{
    int lucky_number = 3;
    std::cout << "�� ����� ���� �������" << std::endl;
    
    int user_input;

    while (1)
    {
        std::cout << "�Է� : ";
        std::cin >> user_input;

        if (user_input == lucky_number)
        {
            std::cout << "�����Դϴ� !" << std::endl;    
            break;
        } 
        else
        {
            std::cout << "�ٽ� ���纸���� " << std::endl;
        }
    }


    

    return 0;
}