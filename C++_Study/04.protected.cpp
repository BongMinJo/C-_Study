#include <iostream>
#include <string>

class Base {
 
    // C++ 클래스 내에서 멤버에 대한 접근 제한자를 두지 않으면 기본적으로 private
    // C/C++ 구조체 멤버에 대한 기본적인 접근 제한자는 public
public:
    std::string parent_string;

    Base() : parent_string("기반") { std::cout << "기반 클래스" << std::endl; }

    void what() { std::cout << parent_string << std::endl; }
};

// 클래스 상속받을 시 
// public 형태로 상속 - 기반 클래스의 접근 지시자들에 영향 없이 그대로 작동 
// protected 형태로 상속 - 파생 클래스 입장에서 public 은 protected로 변경하고 나머지는 그대로 유지
// private 형태로 상속 - 파생 클래스 입장에서 모든 접근 지시자들이 private로 변경 
class Derived : private Base {
    std::string child_string;

public:
    Derived() : child_string("파생"), Base() {
        std::cout << "파생 클래스" << std::endl;

        // parent_string이 private이면 접근할 수 없다.
        // parent_string이 protected / public 일 시 접근할 수 있다.
        // protected - 상속받는 클래스에서는 접근 가능하고 그 외의 기타 정보는 접근 불가능 
        // parent_string = "바꾸기";
    }

    void what() { std::cout << child_string << std::endl; }
};
int main() {
    Base p;
    // Base 에서는 parent_string 이 public 이므로
    // 외부에서 당연히 접근 가능하다.
    std::cout << p.parent_string << std::endl;

    Derived c;
    // 반면에 Derived 에서는 parent_string 이
    // (private 상속을 받았기 때문에) private 이
    // 되어서 외부에서 접근이 불가능하다.
    //std::cout << c.parent_string << std::endl;

    return 0;
}