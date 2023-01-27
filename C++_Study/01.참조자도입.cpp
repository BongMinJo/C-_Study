#include <iostream>

//change_val 함수의 인자 p 에 number 의 주소값을 전달하여, *p 를 통해 number 를 참조하여 number 의 값을 3으로 변경
int change_val(int* p) {
	*p = 3;

	return 0;
}
void func1() {
	int number = 5;

	std::cout << number << std::endl;
	
	change_val(&number);
	std::cout << number << std::endl;
}

// C++ 에서는 다른 변수나 상수를 가리키는 방법으로 또 다른 방식을 제공하는데, 이를 바로 참조자(레퍼런스 - reference) 
// 포인터 타입의 참조자를 만드려면 int*&
void func2() {
	int a = 3;

	// another_a 는 a 의 또다른 이름 이라고 컴파일러에게 알려주는 것
	// another_a 에 어떠한 작업을 수행하든 이는 사실상 a 에 그 작업을 하는 것
	int& another_a = a;

	another_a = 5;
	std::cout << "a : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;

}

// 레퍼런스와 포인터의 다른 점
void func3() {
	// 레퍼런스는 반드시 처음에 누구의 별명이 될 것인지 지정 필요
	//int& another_a;

	// 포인터는 상관 없음
	int* p;

	///////////////
	//레퍼런스가 한 번 별명이 되면 절대로 다른 이의 별명이 될 수 없다.
	int a = 10;
	int& another_a = a; // another_a 는 이제 a 의 참조자!

	int b = 3;
	another_a = b; // ?? -> a = b 동치

	// &a = b;가 되어서 말이 안되는 문장
	//&another_a = b;

	// 포인터는 가리키는 변수를 자유롭게 변경 가능 
	int a = 10;
	int* p = &a; // p 는 a 를 가리킨다.

	int b = 3;
	p = &b; // 이제 p 는 a 를 버리고 b 를 가리킨다

	/////////////////
	// 레퍼런스는 메모리 상에 존재하지 않을 수도 있다.(항상은 아님)
	int a = 10;
	int& another_a = a; 

	// 포인터의 경우 p 는 메모리 상에서 8 바이트를 차지(32 비트 시스템에서는 4바이트)
	int a = 10;
	int* p = &a;  // p 는 메모리 상에서 당당히 8 바이트를 차지하게 됩니다.

}