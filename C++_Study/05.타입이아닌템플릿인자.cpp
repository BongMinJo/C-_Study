#include <iostream>
#include <array>

// ���ø� ���ڷ� Ÿ�Ը� ���� �� �ִ� ���� �ƴϴ�.

// ���ø� ���ڷ� ������ �� �ִ� Ÿ��
// ���� Ÿ�Ե�(bool, char, int, long ��) float, double ����
// ������ Ÿ��
// enum Ÿ��
// std::nullptr_t(��������)

// Ÿ���� �ƴ� ���ø� ���ڴ� ������ Ÿ�ӿ� ������ �������� �ϴ� �͵��̴�.
template <typename T, int num>
T add_num(T t) {
	return t + num;
}

void print_array(const std::array<int, 5>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void print_array(const T& arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int x = 3;
	std::cout << "x : " << add_num<int, 5>(x) << std::endl;

	// ��ġ C ������ �迭 ó�� {} �� ���� �迭�� ������ �� �ִ�.
	// arr�� ��Ÿ�ӿ��� �������� ũ�Ⱑ �Ҵ�Ǵ� ���� �ƴϴ�.
	// �迭ó�� ������ �ÿ� int 5���� ������ �޸𸮸� ������ ���ÿ� �Ҵ�ȴ�.
	std::array<int, 5> arr = { 1, 2, 3, 4, 5 };
	// int arr[5] = {1, 2, 3, 4, 5}; �� ����

	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	print_array(arr);

	std::array<int, 5> arr = { 1, 2, 3, 4, 5 };
	std::array<int, 7> arr2 = { 1, 2, 3, 4, 5, 6, 7 };
	std::array<int, 3> arr3 = { 1, 2, 3 };

	print_array(arr);
	print_array(arr2);
	print_array(arr3);
}