/*
#include <iostream>
#include <typeinfo>

int sum(int a, int b) { return a + b; }

class SomeClass {
    int data;

public:
    SomeClass(int d) : data(d) {}
    SomeClass(const SomeClass& s) : data(s.data) {}
};

int main() {
    // auto 키워드는 템플릿의 사용으로 복잡해진 타입 이름들을 간단하게 나타낼 수 있는 방법
    auto c = sum(1, 2);  // 함수 리턴 타입으로 부터 int 라고 추측 가능
    auto num = 1.0 + 2.0;  // double 로 추측 가능!

    SomeClass some(10);
    auto some2 = some;

    // 컴파일러는 최대한 단순하게 가능한 방법으로 추론하기 때문에 int 변수로 만들어 버린다.
    auto some3(10);  // SomeClass 객체를 만들까요?

    std::cout << "c 의 타입은? :: " << typeid(c).name() << std::endl;
    std::cout << "num 의 타입은? :: " << typeid(num).name() << std::endl;
    std::cout << "some2 의 타입은? :: " << typeid(some2).name() << std::endl;
    std::cout << "some3 의 타입은? :: " << typeid(some3).name() << std::endl;
}
*/

#include <iostream>
#include <typeinfo>

template <int X, int Y>
struct GCD {
    static const int value = GCD<Y, X% Y>::value;
};

template <int X>
struct GCD<X, 0> {
    static const int value = X;
};

template <int N, int D = 1>
struct Ratio {
private:
    const static int _gcd = GCD<N, D>::value;

public:
    typedef Ratio<N / _gcd, D / _gcd> type;
    static const int num = N / _gcd;
    static const int den = D / _gcd;
};
template <class R1, class R2>
struct _Ratio_add {
    using type = Ratio<R1::num* R2::den + R2::num * R1::den, R1::den* R2::den>;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_subtract {
    using type = Ratio<R1::num* R2::den - R2::num * R1::den, R1::den* R2::den>;
};

template <class R1, class R2>
struct Ratio_subtract : _Ratio_subtract<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_multiply {
    using type = Ratio<R1::num* R2::num, R1::den* R2::den>;
};

template <class R1, class R2>
struct Ratio_multiply : _Ratio_multiply<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_divide {
    using type = Ratio<R1::num* R2::den, R1::den* R2::num>;
};

template <class R1, class R2>
struct Ratio_divide : _Ratio_divide<R1, R2>::type {};

template <typename U, typename V, typename W>
struct Dim {
    using M = U;
    using L = V;
    using T = W;

    using type = Dim<M, L, T>;
};

template <typename U, typename V>
struct add_dim_ {
    typedef Dim<typename Ratio_add<typename U::M, typename V::M>::type,
        typename Ratio_add<typename U::L, typename V::L>::type,
        typename Ratio_add<typename U::T, typename V::T>::type>
        type;
};

template <typename U, typename V>
struct subtract_dim_ {
    typedef Dim<typename Ratio_subtract<typename U::M, typename V::M>::type,
        typename Ratio_subtract<typename U::L, typename V::L>::type,
        typename Ratio_subtract<typename U::T, typename V::T>::type>
        type;
};

template <typename T, typename D>
struct quantity {
    T q;
    using dim_type = D;

    quantity operator+(quantity<T, D> quant) {
        return quantity<T, D>(q + quant.q);
    }

    quantity operator-(quantity<T, D> quant) {
        return quantity<T, D>(q - quant.q);
    }

    template <typename D2>
    quantity<T, typename add_dim_<D, D2>::type> operator*(quantity<T, D2> quant) {
        return quantity<T, typename add_dim_<D, D2>::type>(q * quant.q);
    }

    template <typename D2>
    quantity<T, typename subtract_dim_<D, D2>::type> operator/(
        quantity<T, D2> quant) {
        return quantity<T, typename subtract_dim_<D, D2>::type>(q / quant.q);
    }

    // Scalar multiplication and division
    quantity<T, D> operator*(T scalar) { return quantity<T, D>(q * scalar); }

    quantity<T, D> operator/(T scalar) { return quantity<T, D>(q / scalar); }

    quantity(T q) : q(q) {}
};

template <typename T, typename D>
std::ostream& operator<<(std::ostream& out, const quantity<T, D>& q) {
    out << q.q << "kg^" << D::M::num / D::M::den << "m^" << D::L::num / D::L::den
        << "s^" << D::T::num / D::T::den;

    return out;
}

int main() {
    using one = Ratio<1, 1>;
    using zero = Ratio<0, 1>;

    quantity<double, Dim<one, zero, zero>> kg(2);
    quantity<double, Dim<zero, one, zero>> meter(3);
    quantity<double, Dim<zero, zero, one>> second(1);

    // F 의 타입은 굳이 알필요 없다!
    auto F = kg * meter / (second * second);
    std::cout << "2 kg 물체를 3m/s^2 의 가속도로 밀기 위한 힘의 크기는? " << F
        << std::endl;
}