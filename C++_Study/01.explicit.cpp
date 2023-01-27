#include <iostream>

class MyString {
    char* string_content;  // 문자열 데이터를 가리키는 포인터
    int string_length;     // 문자열 길이

    int memory_capacity;

public:
    //// capacity 만큼 미리 할당함.
    //MyString(int capacity);

    // capacity 만큼 미리 할당함. (explicit 키워드에 주목)
    explicit MyString(int capacity);

    // 문자열로 부터 생성
    MyString(const char* str);

    // 복사 생성자
    MyString(const MyString& str);

    ~MyString();

    int length() const;
};

MyString::MyString(int capacity) {
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;
    std::cout << "Capacity : " << capacity << std::endl;
}

MyString::MyString(const char* str) {
    string_length = 0;
    while (str[string_length++]) {
    }

    string_content = new char[string_length];
    memory_capacity = string_length;

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }
void DoSomethingWithString(MyString s) {
    // Do something...
}
int main() { 
    MyString s(3); 
    DoSomethingWithString(MyString("abc"));

    // MyString 을 명시적으로 생성하지 않을 경우 MyString::MyString(const char* str) 생성자의 암시적 변환을 통해 변환되어 컴파일된다.
    DoSomethingWithString("abc");

    // 사용자가 의도하지 않은 암시적 변환이 일어남 
    // explicit 키워드를 사용해 원하지 않는 암시적 변환을 할 수 없도록 컴파일러에게 명시
    // 암시적 변환을 수행할 수 없기에 파라미터 타입이 맞지 않아 오류 발생
    //DoSomethingWithString(3);

    MyString s = "abc";  // MyString s("abc")

    // explicit가 없는 경우 컴파일러가 알아서 적당한 생성자를 골라서 호출
    //MyString s = 5;      // MyString s(5)

    // explicit로 MyString(int capacity) 를 설정 시 명시적으로 생성자를 부를 때에만 허용
    MyString s(5);   // 허용
    //MyString s = 5;  // 컴파일 오류!



}