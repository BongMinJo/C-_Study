#include <iostream>
using namespace std;

//int main() {
//	std::cout << "Hello, World!!" << std::endl;
//	return 0;
//}

int main() {
	cout << "Hello, World!!" << endl; // cout endl ��� iostream ��������� std��� �̸� ������ ���ǵǾ� �ִ� �� 
	return 0;
}


// �̸� ������ ���� �̸��� �������� ���� �� �ִ�.
// �ش� �̸� ������ ���ǵ� �͵��� �ش� ���� �ȿ����� ������ �� ����
// static Ű���带 ����� �Ͱ� ���� ȿ��
namespace {
	// �� �Լ��� �� ���� �ȿ����� ����� �� �ֽ��ϴ�.
	// �̴� ��ġ static int OnlyInThisFile() �� �����մϴ�.
	int OnlyInThisFile() {}

	// �� ���� ���� static int x �� �����մϴ�.
	int only_in_this_file = 0;
}  // namespace

int main() {
	OnlyInThisFile();
	only_in_this_file = 3;
}