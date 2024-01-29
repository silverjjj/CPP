#include <iostream>

typedef struct Animal {
    char name[30];  // �̸�
    int age;        // ����
    int health;  // ü��
    int food;    // ��θ� ����
    int clean;   // ������ ����
} Animal;

void create_animal(Animal *animal) {
    std::cout << "������ �̸�? ";
    std::cin >> animal->name;

    std::cout << "������ ����? ";
    std::cin >> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}

void play(Animal *animal) {
    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}
void one_day_pass(Animal *animal) {
    // �Ϸ簡 ������
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -= 20;
}
void show_stat(Animal *animal) {
    std::cout << animal->name << "�� ����" << std::endl;
    std::cout << "ü��    : " << animal->health << std::endl;
    std::cout << "��θ� : " << animal->food << std::endl;
    std::cout << "û��    : " << animal->clean << std::endl;
}
int main() {
    // ����ü�� 10�� ���� �迭�� �����Ҵ�
    Animal *list[10];
    int animal_num = 0;

    for (;;) {
        std::cout << "1. ���� �߰��ϱ�" << std::endl;
        std::cout << "2. ��� " << std::endl;
        std::cout << "3. ��� ���� ����Ʈ �� ���� " << std::endl;

        int input;
        std::cin >> input;

        switch (input) {
            int play_with;

            case 1:
                list[animal_num] = new Animal;
                create_animal(list[animal_num]);
                animal_num++;
                break;
            case 2:
                std::cout << "������ ���? : ";
                std::cin >> play_with;
                if (play_with < animal_num) play(list[play_with]);

                break;

            case 3:
                for (int i=0; i < animal_num; i++)
                {   
                    std::cout << i << "�� ����" << std::endl;
                    show_stat(list[i]);
                }
                break;
        }

        for (int i = 0; i != animal_num; i++) {
            one_day_pass(list[i]);
        }
    }
    for (int i = 0; i != animal_num; i++) {
        delete list[i];
    }
}