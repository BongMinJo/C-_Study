#include <iostream>

int function1() {
	int a = 2;
	return a;
}

void func1() {
	// a 라는 변수의 값이 b 에 복사
	// function1 이 종료되고 나면 a 는 메모리에서 사라짐
	int b = function1();
}

// 지역변수의 레퍼런스를 리턴
// 리턴 타입은 int& 참조자를 리턴
// 리턴하는 function2 안에 정의되어 있는 a 는 함수의 리턴과 함께 사라짐
// 레퍼런스를 리턴하는 함수에서 지역 변수의 레퍼런스를 리턴하지 않도록 조심
int& function2() {
	int a = 2;
	return a;
}

void func2() {
	// 원래 참조 하던 것이 사라진 레퍼런스 -> 댕글링 레퍼런스
	int b = function2();
	b = 3;

	//같은 의미
	//int& ref = a;

	//// 근데 a 가 사라짐
	//int b = ref;  // !!!
}

// 외부 변수의 레퍼런스를 리턴
// 인자로 받은 레퍼런스를 그대로 리턴
int& function3(int& a) {
	a = 5;
	return a;
}

void func3() {
	int b = 2;
	// function3(b) 를 실행한 시점에서 a 는 b 를 참조
	// function3 이 리턴한 참조자는 아직 살아있는 변수인 b 를 계속 참조
	int c = function3(b);
}

//참조자를 리턴하는 경우의 장점
// C 언어에서 엄청나게 큰 구조체가 있을 때 해당 구조체 변수를 그냥 리턴하면 전체 복사가 발생해야 해서 시간이 오래걸리지만, 
// 해당 구조체를 가리키는 포인터를 리턴한다면 그냥 포인터 주소 한 번 복사로 매우 빠르게 끝남
// 레퍼런스를 리턴하게 된다면 레퍼런스가 참조하는 타입의 크기와 상관 없이 딱 한 번의 주소값 복사로 전달


//참조자가 아닌 값을 리턴하는 함수를 참조자로 받기
int function4() {
	int a = 5;
	return a;
}

void func4() {
	// 함수의 리턴값은 해당 문장이 끝난 후 바로 사라지는 값 -> 댕글링 레퍼런스
	//int& c = function4();
}

// 상수 레퍼런스로 리턴값을 받게 되면 해당 리턴값의 생명이 연장
// 연장 기간은 레퍼런스가 사라질 때 까지
int function5() {
	int a = 5;
	return a;
}

void func5() {
	const int& c = function5();
	std::cout << "c : " << c << std::endl;
}