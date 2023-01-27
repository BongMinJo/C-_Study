#include <iostream>

class A {
public:
	int a;

	A() { std::cout << "A ������ ȣ��" << std::endl; }
};

class B {
public:
	int b;

	B() { std::cout << "B ������ ȣ��" << std::endl; }
};

// ������ ȣ�� ������ ����ϴ� ������ �¿�ȴ�
// ������ ȣ�� ���� A->B->C
//class C : public A, public B {

// ������ ȣ�� ���� B->A->C
class C : public A, public B {
public:
	int c;

	C() : A(), B() { std::cout << "C ������ ȣ��" << std::endl; }
};
int main() { C c; }