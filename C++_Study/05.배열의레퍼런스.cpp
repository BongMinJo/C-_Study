#include <iostream>

// 레퍼런스의 배열 사용 불가
// 배열 -> 주소값이 존재한다라는 의미로 메모리 상에서 존재한다 
// 하지만 레퍼런스는 특별한 경우가 아닌 이상 메모리 상에서 공간 차지 X
// 이런 모순 때문에 금지
void func1() {
	int a, b;
	//int& arr[2] = { a, b };
}

void func2() {
	int arr[3] = { 1, 2, 3 };

	// ref가 arr 참조
	// ref[0] 부터 ref[2] 가 각각 arr[0] 부터 arr[2] 의 레퍼런스
	// 포인터와는 다르게 배열의 레퍼런스의 경우 참조하기 위해선 반드시 배열의 크기를 명시
	int(&ref)[3] = arr;

	ref[0] = 2;
	ref[1] = 3;
	ref[2] = 1;

	std::cout << arr[0] << arr[1] << arr[2] << std::endl; //231

	int arr2[3][2] = { 1, 2, 3, 4, 5, 6 };
	int(&ref2)[3][2] = arr2;
}

