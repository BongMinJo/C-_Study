/* 컴파일 타임 팩토리얼 계산 */
// 타입 자체가 어떠한 값을 가지지는 않는다.
// 템플릿을 사용하면 객체를 생성하지 않더라도 타입에 값을 부여할 수 있고 그 타입들을 가지고 연산을 할 수 있다.
// 타입은 컴파일 타임에 확정되야하므로 컴파일 타임에 모든 연산이 끝난다.
// 메타 프로그래밍 - 타입을 가지고 컴파일 타임에 생성되는 코드로 프로그래밍하는 것
// 템플릿 메타 프로그래밍(TMP) - 템플릿을 가지고 메타 프로그래밍 
#include <iostream>
template <int N>
struct Factorial {
	static const int result = N * Factorial<N - 1>::result;
};

template <>
struct Factorial<1> {
	static const int result = 1;
};

int main() {
	// 실질적으로 값을 가지는 객체는 아무 것도 없다.
	// 값을 가지고 있는 변수는 메모리 상에 없다.
	std::cout << "6! = 1*2*3*4*5*6 = " << Factorial<6>::result << std::endl;
}