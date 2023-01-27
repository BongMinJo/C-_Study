#include <iostream>
#include <string>

class Base {
	std::string s;

public:
	Base() : s("���") { std::cout << "��� Ŭ����" << std::endl; }

	virtual void what() { std::cout << s << std::endl; }

	virtual void incorrect() { std::cout << "��� Ŭ���� " << std::endl; }
};
class Derived : public Base {
	std::string s;

public:
	Derived() : s("�Ļ�"), Base() { std::cout << "�Ļ� Ŭ����" << std::endl; }

	// �Ļ� Ŭ�������� ��� Ŭ������ ���� �Լ��� �������̵� �ϴ� ��� override Ű���� ���
	void what() override { std::cout << s << std::endl; }

	// �Լ��� ����� �������̵� ���� �ʾҴ�.
	// Derived �� incorrect�� ��� �Լ��̰� Base�� incorrect�� �ƴϱ� ������ �ٸ� �Լ��� ���ֵȴ�.
	// override Ű���带 �� �� ������ ������ �߻��Ѵ�.
	// void incorrect() const override { std::cout << "�Ļ� Ŭ���� " << std::endl; }

	// const Ű���带 ����� ����� ����
	void incorrect() override { std::cout << "�Ļ� Ŭ���� " << std::endl; }
};

int main() {
	Base p;
	Derived c;

	Base* p_c = &c;
	Base* p_p = &p;

	std::cout << " == ���� ��ü�� Base == " << std::endl;
	p_p->incorrect();

	std::cout << " == ���� ��ü�� Derived == " << std::endl;
	p_c->incorrect();
	return 0;
}