#include <iostream>

//change_val �Լ��� ���� p �� number �� �ּҰ��� �����Ͽ�, *p �� ���� number �� �����Ͽ� number �� ���� 3���� ����
int change_val(int* p) {
	*p = 3;

	return 0;
}
void func1() {
	int number = 5;

	std::cout << number << std::endl;
	
	change_val(&number);
	std::cout << number << std::endl;
}

// C++ ������ �ٸ� ������ ����� ����Ű�� ������� �� �ٸ� ����� �����ϴµ�, �̸� �ٷ� ������(���۷��� - reference) 
// ������ Ÿ���� �����ڸ� ������� int*&
void func2() {
	int a = 3;

	// another_a �� a �� �Ǵٸ� �̸� �̶�� �����Ϸ����� �˷��ִ� ��
	// another_a �� ��� �۾��� �����ϵ� �̴� ��ǻ� a �� �� �۾��� �ϴ� ��
	int& another_a = a;

	another_a = 5;
	std::cout << "a : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;

}

// ���۷����� �������� �ٸ� ��
void func3() {
	// ���۷����� �ݵ�� ó���� ������ ������ �� ������ ���� �ʿ�
	//int& another_a;

	// �����ʹ� ��� ����
	int* p;

	///////////////
	//���۷����� �� �� ������ �Ǹ� ����� �ٸ� ���� ������ �� �� ����.
	int a = 10;
	int& another_a = a; // another_a �� ���� a �� ������!

	int b = 3;
	another_a = b; // ?? -> a = b ��ġ

	// &a = b;�� �Ǿ ���� �ȵǴ� ����
	//&another_a = b;

	// �����ʹ� ����Ű�� ������ �����Ӱ� ���� ���� 
	int a = 10;
	int* p = &a; // p �� a �� ����Ų��.

	int b = 3;
	p = &b; // ���� p �� a �� ������ b �� ����Ų��

	/////////////////
	// ���۷����� �޸� �� �������� ���� ���� �ִ�.(�׻��� �ƴ�)
	int a = 10;
	int& another_a = a; 

	// �������� ��� p �� �޸� �󿡼� 8 ����Ʈ�� ����(32 ��Ʈ �ý��ۿ����� 4����Ʈ)
	int a = 10;
	int* p = &a;  // p �� �޸� �󿡼� ����� 8 ����Ʈ�� �����ϰ� �˴ϴ�.

}