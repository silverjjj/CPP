/*
    ���� ������
    : �Ѱ��� �����ڸ� �����, �� �Ѱ��� ������ ���� ������ �ϴ°�

    ����) 
    Photon_Cannon(const Photon_Cannon& pc)          << ���� ������ ��� ���
    Photon_Cannon Ŭ������ �ִٸ�,
    �ٸ� Photon_Cannon�� ��ü pc�� ��� ���۷����� �޴´�.
    const�̱� ������ ���� ������ ���ο��� pc�� �����͸� ������ �� ����, �ν��Ͻ� �����鸸 �����ϴ°�,,,
    �ٽ� ���ؼ� �̹� �����Ǿ��� ������ pc�� ���� �������� ���ϰ� �״�� �����°���,, 
*/

#include <string.h>
#include <iostream>
class Photon_Cannon
{
    private:
        int hp, shield;
        int coord_x, coord_y;
        int damage;
        char *name;

    public:
        Photon_Cannon(int x, int y);
        Photon_Cannon(int x, int y, const char *cannon_name);

        // ���縦 ���ִ� �κ��� ��� ����Ʈ ���� �����ڰ� ������,, ������ �Ѱ谡 ����
        Photon_Cannon(const Photon_Cannon& pc);     // const : �����Ǿ� �־���� ���� ���� ������ �� �����

        ~Photon_Cannon();
        
        void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y) 
{
    std::cout << "������ ȣ�� !" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
}

Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name) 
{
    std::cout << "������ ȣ�� !" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = new char[strlen(cannon_name) + 1];       // name �����Ҵ�
    strcpy(name, cannon_name);
}

Photon_Cannon::~Photon_Cannon()
{
    std::cout << "�Ҹ��� ȣ�� !" << std::endl;
    if (name) delete[] name;
}

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc)       // pc�� ������
{
    std::cout << "���� ������ ȣ�� !" << std::endl;
    hp = pc.hp;                     // ��������
    shield = pc.shield;             // ��������
    coord_x = pc.coord_x;           // ��������
    coord_y = pc.coord_y;           // ��������
    damage = pc.damage;             // ��������
    
    // name = pc.name;                 // �������� : ���� �߻���Ŵ
    name = new char[strlen(pc.name) + 1];    // name�� ��� ���� �޸𸮸� �Ҵ��ؼ� �� ���븸 ���縦 �ϴ� ���� ���縦 ����
    strcpy(name, pc.name);
}

void Photon_Cannon::show_status() {
  std::cout << "Photon Cannon " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main()
{
    // 1. ���� �����ڿ� ����
    // Photon_Cannon pc1(3, 3);
    // Photon_Cannon pc2(pc1);         // ���� ������ pc2
    // Photon_Cannon pc3 = pc2;        // ���� ������ pc3
    
    // pc1.show_status();
    // pc2.show_status();

    // 2. Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) ���� name �����Ҵ��ؼ� �� ���븸 �ٽ� ���� �������ش�
    //      �����Ҵ� ������ ������, �⺻ �����ڰ� �Ҹ�ʰ� ���ÿ� name�� �Ҵ�� �޸𸮱��� delete�ϰ� �ȴ�.
    //      �׷��� ���� �������� name���� ���� ���� �Ҵ� ���־�, �⺻ �����ڰ� �Ҹ�ǵ� ������ ���� �Ѵ� ==> ��������
    Photon_Cannon pc1(3, 3, "Cannon");
    Photon_Cannon pc2 = pc1;

    pc1.show_status();
    pc2.show_status();
}