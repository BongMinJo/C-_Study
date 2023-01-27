#include <iostream>
#include <string>

class Base {
    std::string s;

public:
    Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

    void what() { std::cout << s << std::endl; }
};
// C++은 여러 클래스로부터 상속받을 수 있다.
class Derived : public Base {
    std::string s;

public:
    // Derived의 s에 파생을 넣게 되고, Derived 생성자의 내부를 실행하기 전에 Base의 생성자를 먼저 호출하게 된다.
    // 파생 클래스 생성 바로 아래에 파생 클래스가 출력하기 이전에 Base의 생성자를 먼저 호출하게 되서 기발 클래스가 먼저 출력하게 된다.
    Derived() : Base(), s("파생") {
        std::cout << "파생 클래스" << std::endl;

        // Base 에서 what() 을 물려 받았으므로
        // Derived 에서 당연히 호출 가능하다

        // what() 함수 호출 시 Derived에 정의되지 않았다면
        // what() 함수를 호출시 파생이 아니라 기반이라고 출력되는데 what 함수를 보면 s의 값이 출력
        // what() 함수는 Base에 정의돼있기 때문에 Derived의 s가 아니라 Base의 s가 출력

        // what() 함수 호출 시 Derived에 정의돼있다면
        // 이름이 가지만 다른 클래스에 정의되어 있는 것이기 때문에 다른 함수로 취급
        // 오버라이딩
        what();
    }

    void what() { std::cout << s << std::endl; }
};
int main() {
    std::cout << " === 기반 클래스 생성 ===" << std::endl;
    Base p;

    std::cout << " === 파생 클래스 생성 ===" << std::endl;
    Derived c;

    return 0;
}