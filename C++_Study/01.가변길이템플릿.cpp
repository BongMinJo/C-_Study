#include <iostream>

// 파라미터 팩이 없는 함수의 우선순위가 높다.
template <typename T>
void print(T arg) {
	std::cout << arg << std::endl;
}

// 템플릿을 이용시 임의의 개수의 인자를 받는 함수 구현 가능
// 템플릿 파라미터 팩 - typename 뒤에 ... / 0개 이상의 템플릿 인자
template <typename T, typename... Types>
// 함수 파라미터 팩 - 함수에 인자로 ... / 0개 이상의 함수 인자
// 템플릿과 함수 파라미터 팩 차이 - 템플릿은 타입 앞에 ... 이 오고 함수는 타입 뒤에 ...이 온다

// 파라미터 팩은 추론된 인자를 제외한 나머지 인자들을 나타낸다.
void print(T arg, Types... args) {
	std::cout << arg << ", ";
	print(args...);
}

// 함수 정의 순서를 바꿀시 컴파일 오류 발생 
// C++ 컴파일러는 함수를 컴파일 시 자신의 앞에 정의된 함수들 밖에 보지 못하기 때문
// print("abc") 오버로딩을 찾을때 파라미터 팩이 있는 함수를 택하는데 그 함수 안에서 print()가 호출된다.
// print()를 정의하지 않았기에 컴파일 오류가 발생한다.
//template <typename T, typename... Types>
//void print(T arg, Types... args) {
//	std::cout << arg << ", ";
//	print(args...);
//}
//
//template <typename T>
//void print(T arg) {
//	std::cout << arg << std::endl;
//}

int main() {
	// print의 첫번째 인자는 1이므로 T는 int로 추론되고 arg에는 1이 오게 된다.
	// args에 나머지 3.1, "abc"가 오게 된다.
	print(1, 3.1, "abc");
	

	print(1, 2, 3, 4, 5, 6, 7);
}