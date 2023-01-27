// 실제로 입력을 수행하는 클래스
// operator>>는 istream클래스에 정의되어 있는 연산자
// cin은 istream 클래스의 객체 중 하나

#include <iostream>
#include <string>

int main() {
    std::string s;
    while (true) {

        // 모든 공백문자(띄어쓰기, 엔터, 탭)을 입력시에 무시해버린다.
        std::cin >> s;
        std::cout << "word : " << s << std::endl;
    }
    //this is a long sentence
    //word : this
    //word : is
    //word : a
    //word : long
    //word : sentence
    //ABCD EFGH IJKL
    //word : ABCD
    //word : EFGH
    //word : IJKL
    int t;
 
    while (true) {
        std::cin >> t;
        std::cout << "입력 :: " << t << std::endl;
        if (t == 0) break;
    }
    //3
    //입력 :: 3
    //4
    //입력 :: 4
    //5
    //입력 :: 5
    //6
    //입력 :: 6
    //7
    //입력 :: 7

    // 숫자가 아닌 문자를 입력했을시 무한 루프에 빠지게 된다.
    // ios 클래스에서 스트림의 상태를 관리
    // 스트림의 상태를 관리하는 플래그는 4개가 정의
    // goodbit - 스트림에 입출력 작업이 가능할 때
    // badbit - 스트림에 복구 불가능한 오류 발생 시
    // failbit - 스트림에 복구 가능한 오류 발생 시
    // eofbit - 입력 작업시 EOF 도달시 
    // 문자를 입력시 failbit가 켜지고 입력값을 받지 않고 리턴해버린다.
    // 리턴해버리면서 버퍼에 남아 있는 'c\n'이 문자열에 손대지 않는다. 

    // operator void*() const;
    // ios 객체를 void*로 변환
    // NULL 포인터가 아닌 값을 리턴하는 조건이 failbit, badbit가 모두 off일때
    // 즉 스트림에 정상적으로 입출력 작업을 수행할 수 있을 때 
    // 문자를 입력시 operator>> 는 cin 객체의 failbit를 켜게된다.
    // 그리고 std::cin >> t 후에 cin이 리턴되는데 리턴값이 while 문의 조건식으로 들어가기 때문에 컴파일러는 적절한 타입 변환을 찾게 된다.
    // ios 객체 -> void * -> bool 로 2단 변환을 통해 while문을 잘 빠져나온다.
    while (std::cin >> t) {
        std::cout << "입력 :: " << t << std::endl;
        if (t == 0) break;
    }

    std::cin >> t;  // 고의적으로 문자를 입력하면 failbit 가 켜진다
    std::cout << "fail 비트가 켜진 상태이므로, 입력받지 않는다" << std::endl;
    std::string s;
    std::cin >> s;
    //s
    //fail 비트가 켜진 상태이므로, 입력받지 않는다

    while (true) {
        std::cin >> t;
        std::cout << "입력 :: " << t << std::endl;
        if (std::cin.fail()) {
            std::cout << "제대로 입력해주세요" << std::endl;
            std::cin.clear();            // 플래그들을 초기화 하고 / 플래그를 goodbit로 초기화
            std::cin.ignore(100, '\n');  // 개행문자가 나올 때 까지 무시한다 / 버퍼를 비운다.
        }
        if (t == 1) break;
    }
    //a
    //입력 :: 0
    //제대로 입력해주세요
    //x
    //입력 :: 0
    //제대로 입력해주세요
    //d
    //입력 :: 0
    //제대로 입력해주세요
    //asdf
    //입력 :: 0
    //제대로 입력해주세요
    //2
    //입력 :: 2
    //1
    //입력 :: 1
}