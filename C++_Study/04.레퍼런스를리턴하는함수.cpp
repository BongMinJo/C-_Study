// 레퍼런스를 리턴하는 함수
#include <iostream>

class A {
	int x;

public:
	A(int c) : x(c) {}

	int& access_x() { return x; }
	int get_x() { return x; }
	void show_x() { std::cout << x << std::endl; }
};

int main() {
	A a(5);
	a.show_x();

	// int &c = x;  // 여기서 x 는 a 의 x
	int& c = a.access_x();
	c = 4;
	a.show_x();

	// d가 그냥 변수이므로 값의 복사가 일어나 d에는 x의 값이 들어감
	int d = a.access_x();
	d = 3;
	a.show_x();

	// 아래는 오류
	// 레퍼런스가 아닌 타입을 리턴하는 경우 값의 복사가 이루어짐
	// 임시 객체가 생성되는데 임시 객체의 레퍼런스를 가질 수 없음
	// int& e = a.get_x();
	// e = 2;
	// a.show_x();

	int f = a.get_x();
	f = 1;
	a.show_x();

	// 레퍼런스를 리턴하는 함수는 그 함수 부분을 리턴하는 원래 변수로 치환해도 된다
	a.access_x() = 3;

	// 오류 발생
	// 임새 객체로 치환되며 임시객체에 대입을 하게 되는 모순적 상황 발생
	//a.get_x() = 3;
}