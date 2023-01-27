// C++ 컴파일러는 전위/후의 증감을 구분해서 오버로딩 시켜주는지
// 전위 증감 연산자
// operator++();
// operator--();
// 후위 증감 연산자
// operator++(int x); / operator++(int);
// operator--(int x); / operator--(int);


#include <iostream>

class Test {
    int x;

public:
    Test(int x) : x(x) {}
    Test(const Test& t) : x(t.x) {}

    Test& operator++() {
        x++;
        std::cout << "전위 증감 연산자" << std::endl;
        return *this;
    }

    // 전위 증감과 후위 증감에 차이를 두기 위해 후위 증감의 경우 인자로 int 를
    // 받지만 실제로는 아무것도 전달되지 않는다.
    Test operator++(int) {
        //복사 생성자를 호출하기 때문에 전위 증감 연산보다 더 느리다.
        Test temp(*this);
        x++;
        std::cout << "후위 증감 연산자" << std::endl;
        return temp;
    }

    int get_x() const {
        return x;
    }
};

void func(const Test& t) {
    std::cout << "x : " << t.get_x() << std::endl;
}

int main() {
    Test t(3);

    func(++t); // 4
    func(t++); // 4 가 출력됨
    std::cout << "x : " << t.get_x() << std::endl;
}