#include <iostream>

void func1() {
	// 상수 값 -> 리터럴
	//int& ref = 4;
	
	// 상수 참조자로 선언시 리터럴도 참조 가능
	const int& ref = 4;

	int a = ref; // a = 4; 와 동일하게 처리
	
}