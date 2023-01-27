#include <iostream>

void func1() {

	// 어떤 타입 T 의 참조자 타입은 T& -> y 가 int& 니까 y 의 참조자 타입은 int&& 가 되야 하지 않을까 ?
	// -> C++ 문법 상 참조자의 참조자를 만드는 것은 금지
	// y 와 z 모두 x 의 참조자
	int x;
	int& y = x;
	int& z = y;

	x = 1;
	
	// x : 1 y : 1 z : 1
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;


	y = 2;

	// x : 2 y : 2 z : 2
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

	z = 3;

	// x : 3 y : 3 z : 3
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
}

void func2() {
	int user_input;

	// 레퍼런스로 전달
	std::cin >> user_input;

	// 포인터로 주소값을 전달
	scanf("%d", &user_input);


}