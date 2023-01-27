#include <iostream>

class Parent {
public:
    Parent() { std::cout << "Parent ������ ȣ��" << std::endl; }
    //~Parent() { std::cout << "Parent �Ҹ��� ȣ��" << std::endl; }
    // virtual Ű���带 ���� p�� �Ҹ��ڸ� ȣ���� ��, Child�� �Ҹ��ڸ� ȣ�� ����
    // Child �Ҹ��ڸ� ȣ���ϸ� Child �Ҹ��ڰ� �˾Ƽ� Parent �Ҹ��ڵ� ȣ��
    // Parent �Ҹ��ڸ� ȣ���ϰ� �Ǹ� Parent�� Child�� �ִ��� ������ �𸣱� ������ Child �Ҹ��� ȣ�� �Ұ�
    virtual ~Parent() { std::cout << "Parent �Ҹ��� ȣ��" << std::endl; }
};
class Child : public Parent {
public:
    Child() : Parent() { std::cout << "Child ������ ȣ��" << std::endl; }
    ~Child() { std::cout << "Child �Ҹ��� ȣ��" << std::endl; }
};
int main() {
    std::cout << "--- ����� Child ������� �� ---" << std::endl;
    { Child c; }
    std::cout << "--- Parent �����ͷ� Child �������� �� ---" << std::endl;
    {
        Parent* p = new Child();
        // Child �Ҹ��ڰ� ȣ����� �ʴ´�.-> �޸� ���� �߻�
        delete p;
    }
}