// Wrapper Ŭ���� 
// �⺻ �ڷ������� Ŭ������ �����ؼ� ������ �ڷ����� ��ü�� ���
#include <iostream>

class Int {
    int data;
    // some other data

public:
    Int(int data) : data(data) {}
    Int(const Int& i) : data(i.data) {}

    operator int() { return data; }
};
int main() {
    Int x = 3;
    // operator+ operator- ���� �ٽ� ���� ���������Ѵ�.
   // ���� �̹� �����ϴ� ����� �ٽ� ������ �� 
   // �����Ϸ��� Ŭ������ ��ü�� int�� ������ ��ȯ�� �� �ִٸ� opertor+�� �����ϱ� �ʰ� +�� ������ �� �ִ�.
    int a = x + 4;

    // Ÿ�� ��ȯ ������ ����
    // ������ ó�� �Լ��� ���� Ÿ���� ���ָ� �ȵȴ�.
    // operator (��ȯ �ϰ��� �ϴ� Ÿ��) ()

    x = a * 2 + x + 4;
    std::cout << x << std::endl;
}