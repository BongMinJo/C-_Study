#include <string>
#include <iostream>

int main() {
    int t;
    while (true) {
        // setf 함수 버전 2가지는 인자를 1개만 받는 것과 인자를 2개 받을 수 있다.
        // 인자를 1개 받는 것은 인자로 준 형식 플래그를 적용 
        // 2개 취하는 것은 두 번째 인자의 내용을 초기화 하고 첫 번째 인자를 적용하는 것
        std::cin.setf(std::ios_base::hex, std::ios_base::basefield);
        std::cin >> t;
        std::cout << "입력 :: " << t << std::endl;
        if (std::cin.fail()) {
            std::cout << "제대로 입력해주세요" << std::endl;
            std::cin.clear();  // 플래그들을 초기화 하고
                               // std::cin.ignore(100,'n');//개행문자가 나올 때까지
                               // 무시한다
        }
        if (t == 0) break;
    }

    //ff
    //입력 :: 255
    //0xFF
    //입력 :: 255
    //123
    //입력 :: 291
    //ABCDE
    //입력 :: 703710

    while (true) {
        // 조작자 - 스트림을 조작하여 입력 혹은 출력 방식을 바꿔주는 함수
        std::cin >> std::hex >> t;
        std::cout << "입력 :: " << t << std::endl;
        if (std::cin.fail()) {
            std::cout << "제대로 입력해주세요" << std::endl;
            std::cin.clear();           // 플래그들을 초기화 하고
            std::cin.ignore(100, 'n');  //개행문자가 나올 때까지 무시한다
        }
        if (t == 0) break;
    }

    //ff
    //입력 :: 255
    //0xFF
    //입력 :: 255
    //123
    //입력 :: 291
    //ABCDE 
    //입력 :: 703710
}