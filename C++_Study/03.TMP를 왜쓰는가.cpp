// 템플릿 메타 프로그래밍으로 작성된 코드는 모두 컴파일 타임에 모든 연산이 끝난다.
// 프로그램 실행 속도를 향상
// 버그 찾는 것이 힘들다.
// 디버깅이 불가능

#include <iostream>

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
//  _Ratio_add<R1, R2>::type 를 상속받아 Ratio_add를 Ratio 타입처럼 사용할 수 있다.
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

int main() {
	//typedef Ratio<2, 3> rat;
	//typedef Ratio<3, 2> rat2;
	//typedef Ratio_add<rat, rat2> rat3;

	// typedef -> using 으로 변경
	// 직관적으로 사용할 수 있다.
	// 함수 포인터의 경우
	typedef void (*func)(int, int);
	using func = void (*)(int, int);

	// Ratio 클래스의 객체를 생성한 것 같지만 실제로 생성된 객체는 없고 타입을 컴파일러가 만들어냈다.
	using r1 = Ratio<2, 3>;
	using r2 = Ratio<3, 2>;

	using r3 = Ratio_add<r1, r2>;
	std::cout << "2/3 + 3/2 = " << r3::num << " / " << r3::den << std::endl;

	using r4 = Ratio_multiply<r1, r3>;
	std::cout << "13 / 6 * 2 /3 = " << r4::num << " / " << r4::den << std::endl;
}