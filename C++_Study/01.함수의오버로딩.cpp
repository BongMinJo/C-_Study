/* 함수의 오버로딩 */
#include <iostream>

// 함수의 이름이 같더라도 인자가 다르면 다른 함수
void print(int x) { std::cout << "int : " << x << std::endl; }
//void print(char x) { std::cout << "char : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }

int main() {
	int a = 1;
	char b = 'c';
	double c = 3.2f;

	print(a);
	// 자기와 정확히 일치하는 인자를 가진 함수가 없을 시 '자신과 최대로 근접한 함수'를 찾음
	print(b);
	print(c);

	// int : 1
	// int : 99
	// double : 3.2

	return 0;
}

// C++ 컴파일러에서 함수를 오버로딩하는 과정
// 1. 자신과 타입이 정확히 일치하는 함수를 찾는다.
// 2. 정확히 일치하는 타입이 없는 경우 형변환을 통해서일치하는 함수를 찾아본다.
// 3. 위와 같이 변환해도 일치하는 것이 없다면 좀더 포괄적인 형변환을 통해 일치하는 함수를 찾는다.
// 4. 유저 정의된 타입 변환으로 일치하는 것을 찾는다.
// 일치하는 함수를 찾을 수 없거나 같은 단계에서 두 개 이상이 일치하는 경우 모호하다라고 판단해 오류 발생