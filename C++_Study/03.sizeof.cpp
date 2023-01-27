#include <iostream>

// 재귀 호출 종료를 위한 베이스 케이스
int sum_all() { return 0; }

template <typename... Ints>
int sum_all(int num, Ints... nums) {
	return num + sum_all(nums...);
}

template <typename... Ints>
double average(Ints... nums) {
	// sizeof 연산자 - 인자의 크기를 리턴
	// 파라미터 팩 sizeof... - 전체 인자의 개수를 리턴
	return static_cast<double>(sum_all(nums...)) / sizeof...(nums);
}

int main() {
	// (1 + 4 + 2 + 3 + 10) / 5
	std::cout << average(1, 4, 2, 3, 10) << std::endl;
}