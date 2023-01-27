/* ������ std::array ���� */
#include <iostream>
#include <typeinfo>

template <typename T, unsigned int N>
class Array {
    T data[N];

public:
    // �迭�� �޴� ���۷��� arr
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

    // �迭 wrapper Ŭ����
    Array<int, 3> arr_w(arr);

    arr_w.print_all();

    //Array<int, 5> Array<int, 3>
    // typeid�� ����Ϸ��� <typeinfo> ��������� �߰��ؾ��Ѵ�.
    // �ٸ� ���ø� ���ڷ� �ν��Ͻ�ȭ �Ǿ� ���� �ٸ� �ڵ带 �����ϸ� �ٸ� Ŭ������ Ĵü�� ����� �ȴ�.
    std::cout << (typeid(Array<int, 3>) == typeid(Array<int, 5>)) << std::endl;

    typedef Int<1> one;
    typedef Int<2> two;

    // ������ ����Ǵ� �ñ�� ������ Ÿ��
    typedef add<one, two>::result three;

    std::cout << "Addtion result : " << three::num << std::endl;
}

