#include "header1.h"
#include "header2.h"

int func1() {
	header1::foo();  // header1 �̶� �̸� ������ �ִ� foo �� ȣ��
}

using header1::foo; // header1�̶� �̸� ������ ����ִ� foo�� ȣ���Ҷ� ���
int func2() {
	foo();
}

using namespace header1; // header1 �̸� �����ȿ� ���ǵ� ��� �͵��� header1:: ���� ���
int func3() {
	foo();  // header1 �� �ִ� �Լ��� ȣ��
	bar();  // header1 �� �ִ� �Լ��� ȣ��
}

int func4() {
	header2::foo();  // header2 �� �ִ� �Լ��� ȣ��
	foo();           // header1 �� �ִ� �Լ��� ȣ��
}