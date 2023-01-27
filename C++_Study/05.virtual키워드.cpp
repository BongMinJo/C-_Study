#include <iostream>

class Base {

public:
	Base() { std::cout << "기반 클래스" << std::endl; }

	// 정적 바인딩 - 컴파일 타임에 어떤 함수가 호출될 지 정해지는 것
	// 동적 바인딩 - 컴파일 시에 어떤 함수가 실행될 지 정해지지 않고 런타임 시에 정해지는 것
	virtual void what() { std::cout << "기반 클래스의 what()" << std::endl; }
};
class Derived : public Base {

public:
	Derived() : Base() { std::cout << "파생 클래스" << std::endl; }

	void what() { std::cout << "파생 클래스의 what()" << std::endl; }
};
int main() {
	Base p;
	Derived c;

	Base* p_c = &c;
	Base* p_p = &p;

	std::cout << " == 실제 객체는 Base == " << std::endl;
	p_p->what();

	std::cout << " == 실제 객체는 Derived == " << std::endl;

	// what()에 virtual 키워드가 없었다면 기반 클래스의 what()이 호출
	// virtual 키워드가 있어서 파생 클래스의 what()이 호출
	p_c->what();

	return 0;
}