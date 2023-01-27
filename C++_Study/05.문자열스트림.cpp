#include <iostream>
#include <sstream>

double to_number(std::string s) {
	std::istringstream ss(s);
	double x;

	ss >> x;
	return x;
}

std::string to_str(int x) {
	// 데이터를 출력할 수 있도록 한다.
	std::ostringstream ss;
	// 숫자에서 문자열로 변환
	ss << x;

	return ss.str();
}

int main() {
	// 문자열을 하나의 스트림이라 생각하게 해주는 가상화 장치
	// 파일에 123이라 기록해놓고 거기서 입력 받는것과 동일
	std::istringstream ss("123");
	int x;
	ss >> x;

	std::cout << "입력 받은 데이터 :: " << x << std::endl;

	std::cout << "변환:: 1 + 2 = " << to_number("1") + to_number("2") << std::endl;

	std::cout << "문자열로 변환:: 1 + 2 = " << to_str(1 + 2) << std::endl;

	return 0;
}