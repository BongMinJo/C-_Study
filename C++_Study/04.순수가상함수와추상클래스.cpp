#include <iostream>

// ���� ���� �Լ��� �ּ� �Ѱ� �����ϰ� �ִ� / �ݵ�� ��� �Ǿ�� �ϴ� Ŭ������ ������ �߻� Ŭ���� (abstract class)�� �Ѵ�.
// ���赵 ����
class Animal {
public:
	Animal() {}
	virtual ~Animal() {}
	// =0; -> ������ �ϴ��� ���ǵǾ� ���� �ʴ� �Լ� 
	// �ݵ�� �������̵� �Ǿ�߸� �ϴ� �Լ�
	// ���� ���� �Լ�
	virtual void speak() = 0;
};

class Dog : public Animal {
public:
	Dog() : Animal() {}
	void speak() override { std::cout << "�п�" << std::endl; }
};

class Cat : public Animal {
public:
	Cat() : Animal() {}
	void speak() override { std::cout << "�߿˾߿�" << std::endl; }
};

int main() {
	// Animal ��ü ���� �Ұ��� 
	// ���� ���� �Լ��� �ּ� �� �� �̻� �����ϰ� �ִ� Ŭ������ ��ü�� ������ �� ����.
	// �ν��Ͻ�ȭ ��Ű�� ���ؼ� �� Ŭ������ ��� �޴� Ŭ������ ���� ��� ���� ���� �Լ��� �������̵� ���־���Ѵ�.
	/*Animal a;
	a.speak();*/

	Animal* dog = new Dog();
	Animal* cat = new Cat();

	dog->speak();
	cat->speak();
}