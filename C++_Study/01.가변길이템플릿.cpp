#include <iostream>

// �Ķ���� ���� ���� �Լ��� �켱������ ����.
template <typename T>
void print(T arg) {
	std::cout << arg << std::endl;
}

// ���ø��� �̿�� ������ ������ ���ڸ� �޴� �Լ� ���� ����
// ���ø� �Ķ���� �� - typename �ڿ� ... / 0�� �̻��� ���ø� ����
template <typename T, typename... Types>
// �Լ� �Ķ���� �� - �Լ��� ���ڷ� ... / 0�� �̻��� �Լ� ����
// ���ø��� �Լ� �Ķ���� �� ���� - ���ø��� Ÿ�� �տ� ... �� ���� �Լ��� Ÿ�� �ڿ� ...�� �´�

// �Ķ���� ���� �߷е� ���ڸ� ������ ������ ���ڵ��� ��Ÿ����.
void print(T arg, Types... args) {
	std::cout << arg << ", ";
	print(args...);
}

// �Լ� ���� ������ �ٲܽ� ������ ���� �߻� 
// C++ �����Ϸ��� �Լ��� ������ �� �ڽ��� �տ� ���ǵ� �Լ��� �ۿ� ���� ���ϱ� ����
// print("abc") �����ε��� ã���� �Ķ���� ���� �ִ� �Լ��� ���ϴµ� �� �Լ� �ȿ��� print()�� ȣ��ȴ�.
// print()�� �������� �ʾұ⿡ ������ ������ �߻��Ѵ�.
//template <typename T, typename... Types>
//void print(T arg, Types... args) {
//	std::cout << arg << ", ";
//	print(args...);
//}
//
//template <typename T>
//void print(T arg) {
//	std::cout << arg << std::endl;
//}

int main() {
	// print�� ù��° ���ڴ� 1�̹Ƿ� T�� int�� �߷еǰ� arg���� 1�� ���� �ȴ�.
	// args�� ������ 3.1, "abc"�� ���� �ȴ�.
	print(1, 3.1, "abc");
	

	print(1, 2, 3, 4, 5, 6, 7);
}