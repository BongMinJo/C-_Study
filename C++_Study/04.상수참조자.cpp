#include <iostream>

void func1() {
	// ��� �� -> ���ͷ�
	//int& ref = 4;
	
	// ��� �����ڷ� ����� ���ͷ��� ���� ����
	const int& ref = 4;

	int a = ref; // a = 4; �� �����ϰ� ó��
	
}