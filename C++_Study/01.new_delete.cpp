/* new �� delete �� ��� */
#include <iostream>

void func1() {
	//int ũ���� ������ �Ҵ��Ͽ� �� �ּҰ��� p �� ���� �־���
	int* p = new int;
	//T* pointer = new T;

	*p = 10;

	std::cout << *p << std::endl;

	delete p;
}

void func2() {
	int a = 5;

	// ���� ������ delete �� heap�� �ƴ� ������ �����Ϸ��� �Ѵٴ� ��� ��
	delete& a;
}