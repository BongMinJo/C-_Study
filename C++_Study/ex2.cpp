#include "header1.h"
#include "header2.h"

int func1() {
	header1::foo();  // header1 이란 이름 공간에 있는 foo 를 호출
}

using header1::foo; // header1이란 이름 공간에 들어있는 foo만 호출할때 명시
int func2() {
	foo();
}

using namespace header1; // header1 이름 공간안에 정의된 모든 것들을 header1:: 없이 사용
int func3() {
	foo();  // header1 에 있는 함수를 호출
	bar();  // header1 에 있는 함수를 호출
}

int func4() {
	header2::foo();  // header2 에 있는 함수를 호출
	foo();           // header1 에 있는 함수를 호출
}