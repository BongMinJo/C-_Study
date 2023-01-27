// Wrapper 클래스 
// 기본 자료형들을 클래스로 포장해서 각각의 자료형을 객체로 사용
#include <iostream>

class Int {
    int data;
    // some other data

public:
    Int(int data) : data(data) {}
    Int(const Int& i) : data(i.data) {}

    operator int() { return data; }
};
int main() {
    Int x = 3;
    // operator+ operator- 등을 다시 만들어서 사용해줘야한다.
   // 굳이 이미 제공하는 기능을 다시 만들어야 함 
   // 컴파일러가 클래스의 객체를 int형 변수로 변환할 수 있다면 opertor+를 정의하기 않고 +를 수행할 수 있다.
    int a = x + 4;

    // 타입 변환 연산자 정의
    // 생성자 처럼 함수의 리턴 타입을 써주면 안된다.
    // operator (변환 하고자 하는 타입) ()

    x = a * 2 + x + 4;
    std::cout << x << std::endl;
}