// 디폴트 복사 생성자의 한계
#include <string.h>
#include <iostream>

class Photon_Cannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;

    char* name;

public:
    Photon_Cannon(int x, int y);
    Photon_Cannon(int x, int y, const char* cannon_name);
    ~Photon_Cannon();

    void show_status();
};

Photon_Cannon::Photon_Cannon(int x, int y) {
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = NULL;
}

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
    std::cout << "복사 생성자 호출! " << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;

    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
}

Photon_Cannon::Photon_Cannon(int x, int y, const char* cannon_name) {
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = new char[strlen(cannon_name) + 1];
    strcpy(name, cannon_name);
}
Photon_Cannon::~Photon_Cannon() {
    // 0 이 아닌 값은 if 문에서 true 로 처리되므로
    // 0 인가 아닌가를 비교할 때 그냥 if(name) 하면
    // if(name != 0) 과 동일한 의미를 가질 수 있다.

    // 참고로 if 문 다음에 문장이 1 개만 온다면
    // 중괄호를 생략 가능하다.

    if (name) delete[] name;
}
void Photon_Cannon::show_status() {
    std::cout << "Photon Cannon :: " << name << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
        << std::endl;
    std::cout << " HP : " << hp << std::endl;
}
int main() {
    Photon_Cannon pc1(3, 3, "Cannon");
    
    // 디폴트 복사 생성자 호출 
    // 오류 발생
    // pc1과 pc2가 같은 cannon_name 주소값을 가르킴
    // pc1이 소멸된 경우 pc1 cannon_name 메모리 해지 -> pc2이 해제된 메모리를 가르키게 됨
    // 해결법 -> cannon_name을 단순 대입해주는 얕은 복사가 아닌 메모리를 새로 할당해 내용을 복사하는 깊은 복사를 실행
    // 깊은 복사가 필요한 경우 사용자가 직접 복사 생성자를 만들어야함 
    Photon_Cannon pc2 = pc1;

    pc1.show_status();
    pc2.show_status();
}