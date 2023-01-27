// static 함수
#include <iostream>

class Marine {
    // 객체가 소멸될 때 소멸되는 것이 아닌 프로그램이 종료될 때 소멸되는 것
    // 클래스의 모든 객체들이 공유하는 변수
    // 모든 객체들이 하나의 static 멤버 변수를 사용
    static int total_marine_num;
    const static int i = 0;

    int hp;                // 마린 체력
    int coord_x, coord_y;  // 마린 위치
    bool is_dead;

    const int default_damage;  // 기본 공격력

public:
    Marine();              // 기본 생성자
    Marine(int x, int y);  // x, y 좌표에 마린 생성
    Marine(int x, int y, int default_damage);

    int attack();                       // 데미지를 리턴한다.
    void be_attacked(int damage_earn);  // 입는 데미지
    void move(int x, int y);            // 새로운 위치

    void show_status();  // 상태를 보여준다.
    static void show_total_marine();
    ~Marine() { total_marine_num--; }
};

// static 변수들은 정의와 동시에 값이 자동으로 0으로 초기화 -> 사용자가 굳이 초기화 할 필요X
// 클래스 static 변수들은 초기화 필요
// 클래스 내부에서 초기화 불가능
// const static 는 가능 (위에 있음)
int Marine::total_marine_num = 0;

void Marine::show_total_marine() {
    std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
    total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
    total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
    coord_y(y),
    hp(50),
    default_damage(default_damage),
    is_dead(false) {
    total_marine_num++;
}

void Marine::move(int x, int y) {
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
    std::cout << " *** Marine *** " << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
        << std::endl;
    std::cout << " HP : " << hp << std::endl;
    std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

void create_marine() {
    Marine marine3(10, 10, 4);
    Marine::show_total_marine();
}
int main() {
    Marine marine1(2, 3, 5);

    // 어떤 객체에 종속되는 것이 아니라 클래스에 종속되는 것
    // (객체).(멤버 함수) 형태가 아니고 (클래스)::(static 함수)
    // static 함수 내에서는 클래스의 static 변수만을 이용가능
    Marine::show_total_marine();

    Marine marine2(3, 5, 10);
    Marine::show_total_marine();

    // 객체를 생성후 함수 종료하면 지역 객체도 소멸함
    create_marine();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}