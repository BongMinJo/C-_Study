// 템플릿 첫 활용
#include <iostream>
#include <string>

// 아래에 정의되는 클래스에 대해 템플릿을 정의 
// 템플릿 인자로 T를 받게되며 T는 반드시 어떠한 타입의 이름임을 명시
// temploate에 인자로 어떠한 타입을 전달하냐에 따라 Vector를 만든다.
// 클래스 템플릿 인스턴스화 - 클래스 템플릿에 인자를 전달해서 실제 코드를 생성하는 것 
// 템플릿이 인스턴스화 되어야만 컴파일러가 실제 코드 생성

// typename T와 동일한 것 class T라고 T자리에 꼭 클래스가 와야 하는 것은 아니다.
//template <class T>
template <typename T>
class Vector {
    T* data;
    int capacity;
    int length;

public:
    // 생성자
    Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

    // 맨 뒤에 새로운 원소를 추가한다.
    void push_back(T s) {
        if (capacity <= length) {
            T* temp = new T[capacity * 2];
            for (int i = 0; i < length; i++) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }

        data[length] = s;
        length++;
    }

    // 임의의 위치의 원소에 접근한다.
    T operator[](int i) { return data[i]; }

    // x 번째 위치한 원소를 제거한다.
    void remove(int x) {
        for (int i = x + 1; i < length; i++) {
            data[i - 1] = data[i];
        }
        length--;
    }

    // 현재 벡터의 크기를 구한다.
    int size() { return length; }

    ~Vector() {
        if (data) {
            delete[] data;
        }
    }
};

int main() {
    // int 를 보관하는 벡터를 만든다.
    // <> 안에 전달하려는 것 명시
    Vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(2);

    std::cout << "-------- int vector ----------" << std::endl;
    std::cout << "첫번째 원소 : " << int_vec[0] << std::endl;
    std::cout << "두번째 원소 : " << int_vec[1] << std::endl;

    Vector<std::string> str_vec;
    str_vec.push_back("hello");
    str_vec.push_back("world");
    std::cout << "-------- std::string vector -------" << std::endl;
    std::cout << "첫번째 원소 : " << str_vec[0] << std::endl;
    std::cout << "두번째 원소 : " << str_vec[1] << std::endl;

    // bool 데이터 형은 1개 비트 만으로도 충분히 저장할 수 있지만, 8 비트를 사용해서 1개 bool 값을 저장해야 된다
    // 따로 처리 필요
    Vector<bool> int_vec;
}