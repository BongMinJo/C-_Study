#include "header1.h"
#include "header2.h"

//�ڱ� �ڽ��� ���ԵǾ� �ִ� �̸� ���� �ȿ����� ���� �տ� �̸� ������ ������� �ʰ� �����Ӱ� �θ� �� �ִ�.
namespace header1 {
	int func() {
		foo();  // �˾Ƽ� header1::foo() �� ����ȴ�.
	}
}  // namespace header1

//�ٸ� �̸� �������� ȣ��� 
namespace header1 {
	int func() {
		foo();           // �˾Ƽ� header1::foo() �� ����ȴ�.
		header2::foo();  // header2::foo() �� ����ȴ�.
	}
}  // namespace header1