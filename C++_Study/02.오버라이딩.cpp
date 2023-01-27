#include <iostream>
#include <string>

class Base {
	std::string s;

public:
	Base() : s("���") { std::cout << "��� Ŭ����" << std::endl; }

	void what() { std::cout << s << std::endl; }
};
class Derived : public Base {
	std::string s;

public:
	Derived() : s("�Ļ�"), Base() { std::cout << "�Ļ� Ŭ����" << std::endl; }

	// Base what() �������̵�
	void what() { std::cout << s << std::endl; }
};
int main() {
	/*
	std::cout << " === ��� Ŭ���� ���� ===" << std::endl;
	Base p;

	p.what();

	std::cout << " === �Ļ� Ŭ���� ���� ===" << std::endl;
	Derived c;

	c.what();

	//////////���� ���/////////////
	=== ��� Ŭ���� ���� ===
	��� Ŭ����
	���
	=== �Ļ� Ŭ���� ���� ===
	��� Ŭ����
	�Ļ� Ŭ����
	�Ļ�
	*/

	// ��ĳ����
	/*
	Base p;
	Derived c;

	std::cout << "=== ������ ���� ===" << std::endl;
	// p_c�� Base�� ����Ű�� �������̹Ƿ� Derived ��ü�� Base�� �ش��ϴ� �κп� ���� ���� �ۿ� ����.
	// �̷��� ������ ĳ����(�Ļ� Ŭ�������� ��� Ŭ������ ĳ�����ϴ� ��)�� �� ĳ�����̶�� �θ���.
	Base* p_c = &c;
	p_c->what();

	//////////���� ���/////////////
	��� Ŭ����
	��� Ŭ����
	�Ļ� Ŭ����
	== = ������ ���� == =
	���
	*/


	// �ٿ�ĳ���� (�����߻�)
	/*
	Base p;
	Derived c;

	std::cout << "=== ������ ���� ===" << std::endl;

	// p_p�� Derived ��ü�� ����Ű�� �������̹Ƿ� Derived��� ���������� 
	// Derived�� what() �Լ��� �����Ϸ��� �ϸ� ���ǵ����� �ʱ� ������ ���� �߻�
	Derived* p_p = &p;
	p_p->what();
	*/

	// ������ �ٿ�ĳ����
	/*
	Base p;
	Derived c;

	std::cout << "=== ������ ���� ===" << std::endl;
	Base* p_p = &c;

	// Derived�� Base�� �����ϸ� �ȵǱ� ������ ���� �߻�
	// ������ p_p�� ����Ű�� ���� Derived��ü �̹Ƿ� ������ Ÿ�� ��ȯ�� ���� ����Ű�� �ȴ�.
	//Derived* p_c = p_p;
	Derived* p_c = static_cast<Derived*>(p_p);

	p_c->what();
	*/

	// ������ �ٿ� ĳ���� (���輺)
	/*
	Base p;
	Derived c;

	std::cout << "=== ������ ���� ===" << std::endl;
	Base* p_p = &p;

	// ���������� ������ ������ ��Ÿ�� ���� �߻�
	Derived* p_c = static_cast<Derived*>(p_p);
	p_c->what();
	*/

	return 0;
}