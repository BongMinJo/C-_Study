#include <iostream>

// 순수 가상 함수를 최소 한개 포함하고 있는 / 반드시 상속 되어야 하는 클래스를 가리켜 추상 클래스 (abstract class)라 한다.
// 설계도 역할
class Animal {
public:
	Animal() {}
	virtual ~Animal() {}
	// =0; -> 무엇을 하는지 정의되어 있지 않는 함수 
	// 반드시 오버라이딩 되어야만 하는 함수
	// 순수 가상 함수
	virtual void speak() = 0;
};

class Dog : public Animal {
public:
	Dog() : Animal() {}
	void speak() override { std::cout << "왈왈" << std::endl; }
};

class Cat : public Animal {
public:
	Cat() : Animal() {}
	void speak() override { std::cout << "야옹야옹" << std::endl; }
};

int main() {
	// Animal 객체 생성 불가능 
	// 순수 가상 함수를 최소 한 개 이상 포함하고 있는 클래스는 객체를 생성할 수 없다.
	// 인스턴스화 시키기 위해서 이 클래스를 상속 받는 클래스를 만들어서 모든 순수 가상 함수를 오버라이딩 해주어야한다.
	/*Animal a;
	a.speak();*/

	Animal* dog = new Dog();
	Animal* cat = new Cat();

	dog->speak();
	cat->speak();
}