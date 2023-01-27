#include <iostream>
#include <string>

class Base {
    std::string s;

public:
    Base() : s("���") { std::cout << "��� Ŭ����" << std::endl; }

    void what() { std::cout << s << std::endl; }
};
// C++�� ���� Ŭ�����κ��� ��ӹ��� �� �ִ�.
class Derived : public Base {
    std::string s;

public:
    // Derived�� s�� �Ļ��� �ְ� �ǰ�, Derived �������� ���θ� �����ϱ� ���� Base�� �����ڸ� ���� ȣ���ϰ� �ȴ�.
    // �Ļ� Ŭ���� ���� �ٷ� �Ʒ��� �Ļ� Ŭ������ ����ϱ� ������ Base�� �����ڸ� ���� ȣ���ϰ� �Ǽ� ��� Ŭ������ ���� ����ϰ� �ȴ�.
    Derived() : Base(), s("�Ļ�") {
        std::cout << "�Ļ� Ŭ����" << std::endl;

        // Base ���� what() �� ���� �޾����Ƿ�
        // Derived ���� �翬�� ȣ�� �����ϴ�

        // what() �Լ� ȣ�� �� Derived�� ���ǵ��� �ʾҴٸ�
        // what() �Լ��� ȣ��� �Ļ��� �ƴ϶� ����̶�� ��µǴµ� what �Լ��� ���� s�� ���� ���
        // what() �Լ��� Base�� ���ǵ��ֱ� ������ Derived�� s�� �ƴ϶� Base�� s�� ���

        // what() �Լ� ȣ�� �� Derived�� ���ǵ��ִٸ�
        // �̸��� ������ �ٸ� Ŭ������ ���ǵǾ� �ִ� ���̱� ������ �ٸ� �Լ��� ���
        // �������̵�
        what();
    }

    void what() { std::cout << s << std::endl; }
};
int main() {
    std::cout << " === ��� Ŭ���� ���� ===" << std::endl;
    Base p;

    std::cout << " === �Ļ� Ŭ���� ���� ===" << std::endl;
    Derived c;

    return 0;
}