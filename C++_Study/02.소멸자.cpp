#include <string.h>
#include <iostream>

class Marine {
    int hp;                // 마린 체력
    int coord_x, coord_y;  // 마린 위치
    int damage;            // 공격력
    bool is_dead;
    char* name;  // 마린 이름

public:
    Marine();                                       // 기본 생성자
    Marine(int x, int y, const char* marine_name);  // 이름까지 지정
    Marine(int x, int y);  // x, y 좌표에 마린 생성
    ~Marine();

    int attack();                       // 데미지를 리턴한다.
    void be_attacked(int damage_earn);  // 입는 데미지
    void move(int x, int y);            // 새로운 위치

    void show_status();  // 상태를 보여준다.
};
Marine::Marine() {
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
    name = NULL;
}
Marine::Marine(int x, int y, const char* marine_name) {
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);

    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}
Marine::Marine(int x, int y) {
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
    name = NULL;
}
void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine : " << name << " ***" << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
        << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

// 소멸자는 인자를 아무것도 가지지 않음
// 오버로딩도 되지 않음
Marine::~Marine() {
    std::cout << name << " 의 소멸자 호출 ! " << std::endl;
    if (name != NULL) {
        delete[] name;
    }
}
int main() {
    Marine* marines[100];

    marines[0] = new Marine(2, 3, "Marine 2");
    marines[1] = new Marine(1, 5, "Marine 1");

    marines[0]->show_status();
    marines[1]->show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;

    marines[0]->be_attacked(marines[1]->attack());

    marines[0]->show_status();
    marines[1]->show_status();
    
    // 디폴트 소멸자 -> 디폴트 소멸자 내부에선 아무런 작업도 수행하지 않음

    delete marines[0];
    delete marines[1];
}


class Test {
    char c;

public:
    Test(char _c) {
        c = _c;
        std::cout << "생성자 호출 " << c << std::endl;
    }
    ~Test() { std::cout << "소멸자 호출 " << c << std::endl; }
};
void simple_function() { Test b('b'); }
int main() {
    Test a('a');

    // 객체가 파괴될 때 호출되는 소멸자
    simple_function();
}