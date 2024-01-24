/*
    �������� �ʱ�ȭ ����Ʈ(initalizer list)

*/
#include <iostream>

class Marine {
    int hp;                // ���� ü��
    int coord_x, coord_y;  // ���� ��ġ
    // int damage;            // ���ݷ�
    const int default_damage;  // �⺻ ���ݷ�
    bool is_dead;

    public:
        Marine();              // �⺻ ������
        Marine(int x, int y);  // x, y ��ǥ�� ���� ����
        Marine(int x, int y, int default_damage);    // default_damage ���� �߰�

        int attack();                       // �������� �����Ѵ�.
        void be_attacked(int damage_earn);  // �Դ� ������
        void move(int x, int y);            // ���ο� ��ġ

        void show_status();  // ���¸� �����ش�.
};

/*
    �ʱ�ȭ ����Ʈ ����
    (������ �̸�) : var1(arg1), var2(arg2) {}
    �ʱ�ȭ ����Ʈ�� ������ �ʱ�ȭ�� ���ÿ� �Ѵ�.
    
    �ʱ�ȭ ����Ʈ�� ������� �ʴ´ٸ�, ������ �����ϰ� �� ������ ������ �����ϴ°�
*/
// �ʱ�ȭ ����Ʈ ��� �����
// Marine �̸��� ���� �޼ҵ尡 3����, ���ڿ� ���� �����ε��� �ȴ�.
Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y, int default_damage) 
    : coord_x(x), coord_y(y), hp(50), default_damage(default_damage), is_dead(false) {}

void Marine::move(int x, int y) 
{
    coord_x = x;
    coord_y = y;
}

int Marine::attack() { return default_damage; }

void Marine::be_attacked(int damage_earn) 
{
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status() 
{
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Marine marine1(2, 3, 10);       // marine1�� Marine(int x, int y, int default_damage) �� ���� initializer list
    Marine marine2(3, 5);           // marine2�� Marine(int x, int y) �� ���� initializer list

    marine1.show_status();
    marine2.show_status();

    std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;
    marine2.be_attacked(marine1.attack());

    std::cout << std::endl << "���� 2 �� ���� 1 �� ����! " << std::endl;
    marine1.be_attacked(marine2.attack());

    marine1.show_status();
    marine2.show_status();
}