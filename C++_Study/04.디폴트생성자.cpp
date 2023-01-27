// 디폴트 생성자 정의해보기
#include <iostream>

class Date {
    int year_;
    int month_;  // 1 부터 12 까지.
    int day_;    // 1 부터 31 까지.

public:
    void ShowDate();

    Date() {
        year_ = 2012;
        month_ = 7;
        day_ = 12;
    }
};

void Date::ShowDate() {
    std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
        << " 일 입니다 " << std::endl;
}

int main() {
    Date day = Date();

    // 디폴트 생성자(Default Constructor) -> 인자를 하나도 가지지 않는 생성자
    // 클래스에서 사용자가 어떠한 생성자도 명시적으로 정의하지 않았을 경우에 컴파일러가 자동으로 추가해주는 생성자
    Date day2;

    // 디폴트 생성자를 이용해서 초기화 하는 것이 아님
    // 리턴값이 Date 이고 인자가 없는 함수 day3 을 정의하게 된 것으로 인식
    //Date day3();

    day.ShowDate();
    day2.ShowDate();

    return 0;
}

class Test {
public:
    Test() = default;  // 디폴트 생성자를 정의해라
};