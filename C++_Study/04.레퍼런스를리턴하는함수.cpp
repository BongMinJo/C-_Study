// ���۷����� �����ϴ� �Լ�
#include <iostream>

class A {
	int x;

public:
	A(int c) : x(c) {}

	int& access_x() { return x; }
	int get_x() { return x; }
	void show_x() { std::cout << x << std::endl; }
};

int main() {
	A a(5);
	a.show_x();

	// int &c = x;  // ���⼭ x �� a �� x
	int& c = a.access_x();
	c = 4;
	a.show_x();

	// d�� �׳� �����̹Ƿ� ���� ���簡 �Ͼ d���� x�� ���� ��
	int d = a.access_x();
	d = 3;
	a.show_x();

	// �Ʒ��� ����
	// ���۷����� �ƴ� Ÿ���� �����ϴ� ��� ���� ���簡 �̷����
	// �ӽ� ��ü�� �����Ǵµ� �ӽ� ��ü�� ���۷����� ���� �� ����
	// int& e = a.get_x();
	// e = 2;
	// a.show_x();

	int f = a.get_x();
	f = 1;
	a.show_x();

	// ���۷����� �����ϴ� �Լ��� �� �Լ� �κ��� �����ϴ� ���� ������ ġȯ�ص� �ȴ�
	a.access_x() = 3;

	// ���� �߻�
	// �ӻ� ��ü�� ġȯ�Ǹ� �ӽð�ü�� ������ �ϰ� �Ǵ� ����� ��Ȳ �߻�
	//a.get_x() = 3;
}