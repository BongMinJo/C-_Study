#include <iostream>

class A {
public:
	int a;

	A() { std::cout << "A 생성자 호출" << std::endl; }
};

class B {
public:
	int b;

	B() { std::cout << "B 생성자 호출" << std::endl; }
};

// 생성자 호출 순서는 상속하는 순서에 좌우된다
// 생성자 호출 순서 A->B->C
//class C : public A, public B {

// 생성자 호출 순서 B->A->C
class C : public A, public B {
public:
	int c;

	C() : A(), B() { std::cout << "C 생성자 호출" << std::endl; }
};
int main() { C c; }