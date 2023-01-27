// 모든 입출력 객체들은 스트림 객체를 가지고 있다.
// streambuf - C++ 입출력 라이브러리에서 스트림 버퍼 클래스
// 스트림 - 문자들의 순차적인 나열
// streambuf클래스는 스트림의 상태를 나타내기 위해 세 개의 포인터를 정의하고 있다.
// 시작 포인터 - 버퍼의 시작 부분을 가리키는 포인터
// 스트림 위치 지정자 - 읽을 문자를 가리키고 있는 포인터
// 끝 포인터 - 버퍼의 끝 부분을 가리키고 있는 포인터
// 입력 버퍼와 출력 버퍼를 구분해서 각각 get area, put area라 부르고 이에 따라 각각을 가리키는 포인터도 g와 p를 붙여서 표현

#include <iostream>
#include <string>

int main() {
	std::string s;
	std::cin >> s;

	// cin의 rdbuf를 호출 시 cin 객체가 입력을 수행하고 있던 streambuf 객체를 가리키는 포인터를 리턴
	// cin 객체가 istream 객체이므로 오직 입력만을 수행 
	// streambuf 객체에는 오직 get area만 있음 
	// snextc 함수는 스트림 위치 지정자를 한 칸 옮기고, 그 다음 문자를 엿본다.(읽는 것과 다르다)
	// 엿보는 것과 읽는 것의 차이는 streambuf 객체에서 읽게 되면 스트림 위치 지정자를 한 칸 전진시켜서 다음 읽기 때 다음 문자를 읽을 수 있도록 준비한다.
	// 엿보는 것은 해당 문자를 읽고도 스트림 위치 지정자를 움직이지 않는다는 것이다. 따라서 다음 읽기 때 엿본 문자를 읽을 수 있게 된다.
	char peek = std::cin.rdbuf()->snextc();
	if (std::cin.fail()) std::cout << "Failed";
	std::cout << "두 번째 단어 맨 앞글자 : " << peek << std::endl;
	std::cin >> s;
	std::cout << "다시 읽으면 : " << s << std::endl;

	//hello world 두 번째 단어 맨 앞글자 : w 다시 읽으면 : world

}