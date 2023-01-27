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

    // result 중에서 한 개라도 true 면 전체가 true
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

// 템플릿 부분 특수화 시에 반드시 다른 연산자가 붙지 않고 단순한 식별자만 입력해야한다.
//template <int N>
//struct check_div<N, N / 2> {
//    static const bool result = (N % (N / 2) == 0);
//};

template <typename N>
// 컴파일러 입장에서 ::result가 값인지 타입인지 결정해야 한다.
// 의존 타입 - 템플릿 인자에 따라서 어떠한 타입이 달라질 수 있는 것
// 의존 값의 경우 typename을 안 붙여줘도 된다.
//struct check_div<N, divide<N, two>::result> {
struct check_div<N, typename divide<N, two>::result> {
    static const bool result = (N::num % (N::num / 2) == 0);
};

/*
template <typename T>
// 클래스 A에 대해서 func함수를 특수화 한다면 t는 int값이 되어  t 와 p를 곱하는 식으로 해석
// 클래스 B에 대해서 func함수를 특수화 한다면 int형 포인터 p를 선언하는 것으로 해석
// T::t 가 타입인지 아니면 값인지 명확하게 알려줘야 한다.
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