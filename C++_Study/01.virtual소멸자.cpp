#include <iostream>

class Parent {
public:
    Parent() { std::cout << "Parent 생성자 호출" << std::endl; }
    //~Parent() { std::cout << "Parent 소멸자 호출" << std::endl; }
    // virtual 키워드를 통해 p가 소멸자를 호출할 때, Child의 소멸자를 호출 가능
    // Child 소멸자를 호출하면 Child 소멸자가 알아서 Parent 소멸자도 호출
    // Parent 소멸자를 호출하게 되면 Parent는 Child가 있는지 없는지 모르기 때문에 Child 소멸자 호출 불가
    virtual ~Parent() { std::cout << "Parent 소멸자 호출" << std::endl; }
};
class Child : public Parent {
public:
    Child() : Parent() { std::cout << "Child 생성자 호출" << std::endl; }
    ~Child() { std::cout << "Child 소멸자 호출" << std::endl; }
};
int main() {
    std::cout << "--- 평범한 Child 만들었을 때 ---" << std::endl;
    { Child c; }
    std::cout << "--- Parent 포인터로 Child 가리켰을 때 ---" << std::endl;
    {
        Parent* p = new Child();
        // Child 소멸자가 호출되지 않는다.-> 메모리 누수 발생
        delete p;
    }
}