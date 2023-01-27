/* new 와 delete 의 사용 */
#include <iostream>

void func1() {
	//int 크기의 공간을 할당하여 그 주소값을 p 에 집어 넣었음
	int* p = new int;
	//T* pointer = new T;

	*p = 10;

	std::cout << *p << std::endl;

	delete p;
}

void func2() {
	int a = 5;

	// 지역 변수를 delete 시 heap이 아닌 공간을 해제하려고 한다는 경고 뜸
	delete& a;
}