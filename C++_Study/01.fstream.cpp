// 파일에서의 입출력
#include <fstream>
#include <iostream>
#include <string>

int main() {
    // 파일 읽기 준비
    // test.txt를 읽어드리는 경로는 비주얼 스튜디오 상에서 실행하였을 때 소스ㅏ일이 들어있는 위치와 동일
    // ifstream 객체의 소멸자에서 자동적으로 close
    std::ifstream in("test.txt");
    std::string s;

    if (in.is_open()) {
        in >> s;
        std::cout << "입력 받은 문자열 :: " << s << std::endl;
    }
    else {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    }

    // 새로운 파일에서 같은 객체가 입력 받기 위해 기존 파일 스트림과의 연결 종료
    in.close();
    in.open("other.txt");

    if (in.is_open()) {
        in >> s;
        std::cout << "입력 받은 문자열 :: " << s << std::endl;
    }
    else {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    }


    // 생성자에 옵션으로 binary 형태로 받겠다고 명시
    // 생성자에 옵션으로 binary 형태로 받겠다고 명시
    std::ifstream in("test.txt", std::ios::binary);
    std::string s;

    int x;
    if (in.is_open()) {
        // 4바이트의 내용을 읽으라는 의미
        // 두 번째 인자로 몇 바이트 읽을 지 전달
        in.read((char*)(&x), 4);
        std::cout << std::hex << x << std::endl;

        char x[10];
        in.read(x, 10);
    }
    else {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    }

    return 0;
}