#include <iostream>


class Animal {

    private:            // private�� �ڱ� ��ü �ȿ����� ������ �� ������, ��ü �ܺο����� �����Ҽ� ����.
        int food;       // member variable
        int weight;

    public:
        void set_animal(int _food, int _weight)     // member function
        {   
            food = _food;
            weight = _weight;
        }

        void increase_food(int inc)
        {
            food += inc;
            weight += (inc / 3);
        }

        void view_stat() 
        {
            std::cout << "�� ������ food : " << food << std::endl;
            std::cout << "�� ������ weight : " << weight << std::endl;
        }      
};


int main() {

    Animal animal;          // instance ����

    animal.set_animal(100, 50);
    animal.increase_food(30);    
    animal.view_stat();
    return 0;
}