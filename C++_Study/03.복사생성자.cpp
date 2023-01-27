// 포토캐논
#include <string.h>
#include <iostream>

class Photon_Cannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;

public:
    Photon_Cannon(int x, int y);
    Photon_Cannon(const Photon_Cannon& pc);

    void show_status();
};

// 복사 생성자 T(const T& a);
// 다른 T의 객체 a를 상수 레퍼런스로 받음
// a가 const이기 때문에 복사 생성자 내부에서 a의 데이터를 변경할 수 없고 
// 오직 새롭게 초기화되는 인스턴스 변수들에게 복사만 할 수 있음
// C++ 컴파일러는 이미 디폴트 복사 생성자를 지원
// 디폴트 생성자는 아무 일도 하지 않지만 복사 생성자는 복사를 수행함
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
    std::cout << "복사 생성자 호출 !" << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;
}
Photon_Cannon::Photon_Cannon(int x, int y) {
    std::cout << "생성자 호출 !" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
}
void Photon_Cannon::show_status() {
    std::cout << "Photon Cannon " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
        << std::endl;
    std::cout << " HP : " << hp << std::endl;
}
int main() {
    Photon_Cannon pc1(3, 3);
    Photon_Cannon pc2(pc1);
    
    // 복사 생성자 호출 == Photon_Cannon pc3(pc2);
    Photon_Cannon pc3 = pc2;


    // 1번과 2번은 다름 
    // 1번은 복사생성자 호출
    // 2번은 대입연산자
    // 복사생성자는 생성시에만 호출
    // 1. Photon_Cannon pc3 = pc2;
    // 2.Photon_Cannon pc3;
    //   pc3 = pc2;

    pc1.show_status();
    pc2.show_status();
}