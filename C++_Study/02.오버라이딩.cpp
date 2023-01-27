#include <iostream>
#include <string>

class Base {
	std::string s;

public:
	Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }

	void what() { std::cout << s << std::endl; }
};
class Derived : public Base {
	std::string s;

public:
	Derived() : s("파생"), Base() { std::cout << "파생 클래스" << std::endl; }

	// Base what() 오버라이딩
	void what() { std::cout << s << std::endl; }
};
int main() {
	/*
	std::cout << " === 기반 클래스 생성 ===" << std::endl;
	Base p;

	p.what();

	std::cout << " === 파생 클래스 생성 ===" << std::endl;
	Derived c;

	c.what();

	//////////실행 결과/////////////
	=== 기반 클래스 생성 ===
	기반 클래스
	기반
	=== 파생 클래스 생성 ===
	기반 클래스
	파생 클래스
	파생
	*/

	// 업캐스팅
	/*
	Base p;
	Derived c;

	std::cout << "=== 포인터 버전 ===" << std::endl;
	// p_c는 Base를 가리키는 포인터이므로 Derived 객체의 Base에 해당하는 부분에 대한 정보 밖에 없다.
	// 이러한 형태의 캐스팅(파생 클래스에서 기반 클래스로 캐스팅하는 것)을 업 캐스팅이라고 부른다.
	Base* p_c = &c;
	p_c->what();

	//////////실행 결과/////////////
	기반 클래스
	기반 클래스
	파생 클래스
	== = 포인터 버전 == =
	기반
	*/


	// 다운캐스팅 (오류발생)
	/*
	Base p;
	Derived c;

	std::cout << "=== 포인터 버전 ===" << std::endl;

	// p_p는 Derived 객체를 가리키는 포인터이므로 Derived라고 생각하지만 
	// Derived의 what() 함수를 실행하려고 하면 정의돼있지 않기 때문에 오류 발생
	Derived* p_p = &p;
	p_p->what();
	*/

	// 강제적 다운캐스팅
	/*
	Base p;
	Derived c;

	std::cout << "=== 포인터 버전 ===" << std::endl;
	Base* p_p = &c;

	// Derived에 Base를 대입하면 안되기 때문에 오류 발생
	// 하지만 p_p가 가리키는 것이 Derived객체 이므로 강제적 타입 변환을 통해 가리키면 된다.
	//Derived* p_c = p_p;
	Derived* p_c = static_cast<Derived*>(p_p);

	p_c->what();
	*/

	// 강제적 다운 캐스팅 (위험성)
	/*
	Base p;
	Derived c;

	std::cout << "=== 포인터 버전 ===" << std::endl;
	Base* p_p = &p;

	// 성공적으로 컴파일 되지만 런타임 오류 발생
	Derived* p_c = static_cast<Derived*>(p_p);
	p_c->what();
	*/

	return 0;
}