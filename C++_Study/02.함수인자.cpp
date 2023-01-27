#include <iostream>

// int& p는 안되지 않나? -> p 가 정의되는 순간은 change_val(number) 로 호출할 때 이므로 사실상 int& p = number 가 실행
// p는 number 의 새로운 별명
int change_val(int& p) {
	p = 3;

	return 0;
}

void func1() {
	int number = 5;

	std::cout << number << std::endl;
	change_val(number);
	std::cout << number << std::endl;
}