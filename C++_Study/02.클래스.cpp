#include <iostream>

// 클래스(class) -> 객체의 '설계도'
// 인스턴스(instance) -> 클래스를 이용해서 만들어진 객체

class Animal {

// 자기 객체 안에서만 접근할 수 있고 객체 외부에서는 접근할 수 없음
// 키워드 명시를 하지 않았다면 기본적으로 private 로 설정
private:
    // 멤버 변수(member variable)
    int food;
    int weight;

// 외부에서 마음껏 이용
public:
    // 멤버 함수(member function)
    void set_animal(int _food, int _weight) {
        food = _food;
        weight = _weight;
    }
    void increase_food(int inc) {
        food += inc;
        weight += (inc / 3);
    }
    void view_stat() {
        std::cout << "이 동물의 food   : " << food << std::endl;
        std::cout << "이 동물의 weight : " << weight << std::endl;
    }
};  // 세미콜론 잊지 말자!

int main() {
    Animal animal;
    animal.set_animal(100, 50);
    animal.increase_food(30);

    animal.view_stat();
    return 0;
}