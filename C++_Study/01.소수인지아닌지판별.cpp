#include <iostream>

template <int N>
struct INT {
    static const int num = N;
};

template <typename a, typename b>
struct add {
    typedef INT<a::num + b::num> result;
};

template <typename a, typename b>
struct divide {
    typedef INT<a::num / b::num> result;
};

using one = INT<1>;
using two = INT<2>;
using three = INT<3>;

template <typename N, typename d>
struct check_div {

    //
    /*static const bool result =
        (N::num % d::num == 0) || check_div<N, add<d, one>::result>::result;*/

    // result �߿��� �� ���� true �� ��ü�� true
    static const bool result = 
        (N::num % d::num == 0) || check_div<N, typename add<d, one>::result>::result;
};

template <typename N>
struct _is_prime {
    static const bool result = !check_div<N, two>::result;
};

template <>
struct _is_prime<two> {
    static const bool result = true;
};

template <>
struct _is_prime<three> {
    static const bool result = true;
};

// ���ø� �κ� Ư��ȭ �ÿ� �ݵ�� �ٸ� �����ڰ� ���� �ʰ� �ܼ��� �ĺ��ڸ� �Է��ؾ��Ѵ�.
//template <int N>
//struct check_div<N, N / 2> {
//    static const bool result = (N % (N / 2) == 0);
//};

template <typename N>
// �����Ϸ� ���忡�� ::result�� ������ Ÿ������ �����ؾ� �Ѵ�.
// ���� Ÿ�� - ���ø� ���ڿ� ���� ��� Ÿ���� �޶��� �� �ִ� ��
// ���� ���� ��� typename�� �� �ٿ��൵ �ȴ�.
//struct check_div<N, divide<N, two>::result> {
struct check_div<N, typename divide<N, two>::result> {
    static const bool result = (N::num % (N::num / 2) == 0);
};

/*
template <typename T>
// Ŭ���� A�� ���ؼ� func�Լ��� Ư��ȭ �Ѵٸ� t�� int���� �Ǿ�  t �� p�� ���ϴ� ������ �ؼ�
// Ŭ���� B�� ���ؼ� func�Լ��� Ư��ȭ �Ѵٸ� int�� ������ p�� �����ϴ� ������ �ؼ�
// T::t �� Ÿ������ �ƴϸ� ������ ��Ȯ�ϰ� �˷���� �Ѵ�.
int func() {
    T::t* p;
}

class A {
    const static int t;
};

class B {
    using t = int;
};
*/

template <int N>
struct is_prime {
    static const bool result = _is_prime<INT<N>>::result;
};

int main() {
    std::cout << std::boolalpha;
    std::cout << "Is 2 prime ? :: " << is_prime<2>::result << std::endl;
    std::cout << "Is 10 prime ? :: " << is_prime<10>::result << std::endl;
    std::cout << "Is 11 prime ? :: " << is_prime<11>::result << std::endl;
    std::cout << "Is 61 prime ? :: " << is_prime<61>::result << std::endl;
}