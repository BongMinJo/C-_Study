#include <iostream>

// int& p�� �ȵ��� �ʳ�? -> p �� ���ǵǴ� ������ change_val(number) �� ȣ���� �� �̹Ƿ� ��ǻ� int& p = number �� ����
// p�� number �� ���ο� ����
int change_val(int& p) {
	p = 3;

	return 0;
}

void func1() {
	int number = 5;

	std::cout << number << std::endl;
	change_val(number);
	std::cout << number << std::endl;
}