/* 나만의 std::array 구현 */
#include <iostream>
#include <typeinfo>

template <typename T, unsigned int N>
class Array {
    T data[N];

public:
    // 배열을 받는 레퍼런스 arr
    Array(T(&arr)[N]) {
        for (int i = 0; i < N; i++) {
            data[i] = arr[i];
        }
    }

    T* get_array() { return data; }

    unsigned int size() { return N; }

    void print_all() {
        for (int i = 0; i < N; i++) {
            std::cout << data[i] << ", ";
        }
        std::cout << std::endl;
    }
};

template <int N>
struct Int {
    static const int num = N;
};

template <typename T, typename U>
struct add {
    typedef Int<T::num + U::num> result;
};

int main() {
    int arr[3] = { 1, 2, 3 };

    // 배열 wrapper 클래스
    Array<int, 3> arr_w(arr);

    arr_w.print_all();

    //Array<int, 5> Array<int, 3>
    // typeid를 사용하려면 <typeinfo> 헤더파일을 추가해야한다.
    // 다른 템플릿 인자로 인스턴스화 되어 각기 다른 코드를 생성하며 다른 클래스의 캑체를 만들게 된다.
    std::cout << (typeid(Array<int, 3>) == typeid(Array<int, 5>)) << std::endl;

    typedef Int<1> one;
    typedef Int<2> two;

    // 덧셈이 수행되는 시기는 컴파일 타임
    typedef add<one, two>::result three;

    std::cout << "Addtion result : " << three::num << std::endl;
}

