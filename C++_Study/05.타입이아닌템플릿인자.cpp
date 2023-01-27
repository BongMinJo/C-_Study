#include <iostream>
#include <array>

// 템플릿 인자로 타입만 받을 수 있는 것이 아니다.

// 템플릿 인자로 전달할 수 있는 타입
// 정수 타입들(bool, char, int, long 등) float, double 제외
// 포인터 타입
// enum 타입
// std::nullptr_t(널포인터)

// 타입이 아닌 템플릿 인자는 컴파일 타임에 값들이 정해져야 하는 것들이다.
template <typename T, int num>
T add_num(T t) {
	return t + num;
}

void print_array(const std::array<int, 5>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void print_array(const T& arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int x = 3;
	std::cout << "x : " << add_num<int, 5>(x) << std::endl;

	// 마치 C 에서의 배열 처럼 {} 을 통해 배열을 정의할 수 있다.
	// arr은 런타임에서 동적으로 크기가 할당되는 것이 아니다.
	// 배열처럼 컴파일 시에 int 5개를 가지는 메모리를 가지고 스택에 할당된다.
	std::array<int, 5> arr = { 1, 2, 3, 4, 5 };
	// int arr[5] = {1, 2, 3, 4, 5}; 와 동일

	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	print_array(arr);

	std::array<int, 5> arr = { 1, 2, 3, 4, 5 };
	std::array<int, 7> arr2 = { 1, 2, 3, 4, 5, 6, 7 };
	std::array<int, 3> arr3 = { 1, 2, 3 };

	print_array(arr);
	print_array(arr2);
	print_array(arr3);
}