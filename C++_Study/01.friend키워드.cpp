class A {
private:
    void private_func() {}
    int private_num;

    // friend�� ���ǵ� Ŭ������ �Լ����� ���� Ŭ������ private�� ���ǵ� ������ �Լ��鿡 ������ �� �ִ�.
    // B�� A�� ��� private�� �� �� ������ B�ȿ��� A�� friend�� �������� �ʴ� �̻� A�� B�� privae ��ü�鿡 ���� �Ұ� 
    // B �� A �� ģ��!
    friend class B;

    // func �� A �� ģ��!
    // Ŭ���� �ȿ� �ִٰ� ��� �Լ� �ƴ�
    friend void func();
};

class B {
public:
    void b() {
        A a;

        // ��� private �Լ��� �ʵ�������� ģ���̱� ������ ���� �����ϴ�.
        a.private_func();
        a.private_num = 2;
    }
};

void func() {
    A a;

    // ��� private �Լ��� �ʵ�������� ���� ���������� ģ���̱� ������ ����
    // �����ϴ�.
    a.private_func();
    a.private_num = 2;
}

int main() {}