#include <iostream>

void func1() {

	// � Ÿ�� T �� ������ Ÿ���� T& -> y �� int& �ϱ� y �� ������ Ÿ���� int&& �� �Ǿ� ���� ������ ?
	// -> C++ ���� �� �������� �����ڸ� ����� ���� ����
	// y �� z ��� x �� ������
	int x;
	int& y = x;
	int& z = y;

	x = 1;
	
	// x : 1 y : 1 z : 1
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;


	y = 2;

	// x : 2 y : 2 z : 2
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

	z = 3;

	// x : 3 y : 3 z : 3
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
}

void func2() {
	int user_input;

	// ���۷����� ����
	std::cin >> user_input;

	// �����ͷ� �ּҰ��� ����
	scanf("%d", &user_input);


}