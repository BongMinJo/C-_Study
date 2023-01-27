#include <iostream>

// string.h 는 strlen 때문에 include 했는데, 사실 여러분이 직접 strlen
// 과 같은 함수를 만들어서 써도 됩니다.
#include <string.h>

// C형식의 문자열을 보관시 문자열의 끝부분에 널 문자를 사용해 끝을 확인
// 이를 string_length라는 문자열 길이 변수를 도입해 해결
class MyString {
    char* string_content;  // 문자열 데이터를 가리키는 포인터
    int string_length;     // 문자열 길이

public:
    // 문자 하나로 생성
    MyString(char c);

    // 문자열로 부터 생성
    MyString(const char* str);

    // 복사 생성자
    MyString(const MyString& str);

    ~MyString();

    int length() const;

    void print() const;
    void println() const;
};

MyString::MyString(char c) {
    //동적 할당으로 처리하였기에 소멸자에서 동적 해제 처리 필수
    string_content = new char[1];
    string_content[0] = c;
}
MyString::MyString(const char* str) {
    string_length = strlen(str);
    //동적 할당으로 처리하였기에 소멸자에서 동적 해제 처리 필수
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) {
        string_content[i] = str[i];
    }
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }
}
void MyString::println() const {
    for (int i = 0; i != string_length; i++) {
        std::cout << string_content[i];
    }

    std::cout << std::endl;
}
int main() {
    MyString str1("hello world!");
    MyString str2(str1);

    str1.println();
    str2.println();
}