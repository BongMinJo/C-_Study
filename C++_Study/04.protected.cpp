#include <iostream>
#include <string>

class Base {
 
    // C++ Ŭ���� ������ ����� ���� ���� �����ڸ� ���� ������ �⺻������ private
    // C/C++ ����ü ����� ���� �⺻���� ���� �����ڴ� public
public:
    std::string parent_string;

    Base() : parent_string("���") { std::cout << "��� Ŭ����" << std::endl; }

    void what() { std::cout << parent_string << std::endl; }
};

// Ŭ���� ��ӹ��� �� 
// public ���·� ��� - ��� Ŭ������ ���� �����ڵ鿡 ���� ���� �״�� �۵� 
// protected ���·� ��� - �Ļ� Ŭ���� ���忡�� public �� protected�� �����ϰ� �������� �״�� ����
// private ���·� ��� - �Ļ� Ŭ���� ���忡�� ��� ���� �����ڵ��� private�� ���� 
class Derived : private Base {
    std::string child_string;

public:
    Derived() : child_string("�Ļ�"), Base() {
        std::cout << "�Ļ� Ŭ����" << std::endl;

        // parent_string�� private�̸� ������ �� ����.
        // parent_string�� protected / public �� �� ������ �� �ִ�.
        // protected - ��ӹ޴� Ŭ���������� ���� �����ϰ� �� ���� ��Ÿ ������ ���� �Ұ��� 
        // parent_string = "�ٲٱ�";
    }

    void what() { std::cout << child_string << std::endl; }
};
int main() {
    Base p;
    // Base ������ parent_string �� public �̹Ƿ�
    // �ܺο��� �翬�� ���� �����ϴ�.
    std::cout << p.parent_string << std::endl;

    Derived c;
    // �ݸ鿡 Derived ������ parent_string ��
    // (private ����� �޾ұ� ������) private ��
    // �Ǿ �ܺο��� ������ �Ұ����ϴ�.
    //std::cout << c.parent_string << std::endl;

    return 0;
}