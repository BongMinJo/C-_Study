// 가변 길이 템플릿은 재귀 함수 형태로 구성 -> 재귀 호출 종료를 위한 함수를 따로 만들어야 한다.

// Fold 방식 종류 (I는 초기 값, op는 이항 연산자)
// 단항 우측 Fold (E op ...) (E1op(... op(EN−1op EN)))
// 단항 좌측 Fold (... op E) (((E1op E2) op ...) op EN)
// 이항 우측 Fold (E op ... op I) (E1op(... op(EN−1op(ENop I))))
// 이항 좌측 Fold (I op ... op E) ((((I op E1) op E2) op ...) op EN

#include <iostream>

template <typename... Ints>
int sum_all(Ints... nums) {
	// Fold 형식 
	return (... + nums);
	//return ((((1 + 4) + 2) + 3) + 10);
	// Fold 식은 ()로 감싸야한다.
	//return ... + nums;
}

template <typename Int, typename... Ints>
Int diff_from(Int start, Ints... nums) {
	return (start - ... - nums);
	//return (((((100 - 1) - 4) - 2) - 3) - 10);
}

class A {
public:
	void do_something(int x) const {
		std::cout << "Do something with " << x << std::endl;
	}
};

template <typename T, typename... Ints>
void do_many_things(const T& t, Ints... nums) {
	// 각각의 인자들에 대해 do_something 함수들을 호출한다.
	// 모든 인자들에 대해 각각 t.do_something(arg) 를 실행한 것과 같다.
	(t.do_something(nums), ...);
	//t.do_something(1);
	//t.do_something(3);
	//t.do_something(2);
	//t.do_something(4);
}


int main() {
	// 1 + 4 + 2 + 3 + 10
	std::cout << sum_all(1, 4, 2, 3, 10) << std::endl;

	// 100 - 1 - 4 - 2 - 3 - 10
	std::cout << diff_from(100, 1, 4, 2, 3, 10) << std::endl;

	A a;
	do_many_things(a, 1, 3, 2, 4);
}