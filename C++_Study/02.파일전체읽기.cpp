#include <fstream>
#include <iostream>
#include <string>

int main() {

    // 파일 전체를 한번에 읽기
    // 파일 읽기 준비
    std::ifstream in("test.txt");
    std::string s;

    if (in.is_open()) {
        // 위치 지정자를 파일 끝으로 옮긴다.
        // 두 번째 인자는 파일 내 위치를 의미, 첫 번째 인자는 그 위치로부터 얼마나 만큼 떨어져 있느냐를 의미
        in.seekg(0, std::ios::end);

        // 그리고 그 위치를 읽는다. (파일의 크기)
        // tellg 함수는 위치 지정자의 위치 (시작 지점으로부터) 반환
        int size = in.tellg();

        // 그 크기의 문자열을 할당한다.
        s.resize(size);

        // 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
        in.seekg(0, std::ios::beg);

        // 파일 전체 내용을 읽어서 문자열에 저장한다.
        in.read(&s[0], size);
        std::cout << s << std::endl;
    }
    else {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
    }


    // 파일 전체를 한 줄씩 읽기
    std::ifstream in("test.txt");
    char buf[100];

    if (!in.is_open()) {
        std::cout << "파일을 찾을 수 없습니다!" << std::endl;
        return 0;
    }

    // ifstream에는 자기 자신을 bool로 캐스팅할 수 있는 캐스팅 연산자가 오버로딩 되어있다.
    // true이기 위해서는 다음 입력 작업이 성공적이어야만 하고 현재 스트림에 오류 플래그가 커져 있지 않아야만 한다.
    while (in) {
        // getline 함수는 파일에서 개행문자(\n)가 나올 때 까지 최대 지정한 크기 -1만큼 읽는다.
        // 하나 적게 읽는 이유는 buf 맨 마지막 문자로 널 종료 문자를 넣어줘야 하기 때문
        // getline 함수는 개행 문자가 나오기 전에 지정한 버퍼의 크기가 다 차게 된다면 failbit 를 키게 된다.
        in.getline(buf, 100);
        
        // 개행문자가 아닌 지정한 문자가 나올때까지 읽는 것으로 바꾸는 법
        //in.getline(buf, 100, '.');

        std::cout << buf << std::endl;
    }

    std::string s;
    while (in) {
        // 버퍼 크기의 한계를 극복하기 위해 string 에서 getline함수 제공
        // getline이 ifstream에 정의되어 있는게 아닌 std::string에 정의되어 있는 함수로 사용 
        // 첫 번째 인자로 istream객체를 받고 두 번째 인자로 입력 받은 문자열을 저장할 string 객체로 받는다.
        getline(in, s);
        std::cout << s << std::endl;
    }

    return 0;
}