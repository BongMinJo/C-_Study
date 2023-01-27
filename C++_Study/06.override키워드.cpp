#include <iostream>
#include <string>

class Base {
	std::string s;

public:
	Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

	virtual void what() { std::cout << s << std::endl; }

	virtual void incorrect() { std::cout << "기반 클래스 " << std::endl; }
};
class Derived : public Base {
	std::string s;

public:
	Derived() : s("파생"), Base() { std::cout << "파생 클래스" << std::endl; }

	// 파생 클래스에서 기반 클래스의 가상 함수를 오버라이드 하는 경우 override 키워드 사용
	void what() override { std::cout << s << std::endl; }

	// 함수가 제대로 오버라이드 되지 않았다.
	// Derived 의 incorrect는 상수 함수이고 Base의 incorrect는 아니기 때문에 다른 함수로 간주된다.
	// override 키워드를 쓸 시 컴파일 오류가 발생한다.
	// void incorrect() const override { std::cout << "파생 클래스 " << std::endl; }

	// const 키워드를 지우면 제대로 실행
	void incorrect() override { std::cout << "파생 클래스 " << std::endl; }
};

int main() {
	Base p;
	Derived c;

	Base* p_c = &c;
	Base* p_p = &p;

	std::cout << " == 실제 객체는 Base == " << std::endl;
	p_p->incorrect();

	std::cout << " == 실제 객체는 Derived == " << std::endl;
	p_c->incorrect();
	return 0;
}