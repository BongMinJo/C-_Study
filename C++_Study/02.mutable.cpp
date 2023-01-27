#include <iostream>

class A {
    // ��� ������ mutable�� �������� �� const �Լ����� �� ���� ����
    mutable int data_;
    //int data_;

public:
    A(int data) : data_(data) {}
    // const ��� �Լ� ���ο��� ��� �������� ���� �ٲٴ� �� �Ұ��� 
    void DoSomething(int x) const {
        data_ = x;  // �Ұ���!
    }

    void PrintData() const { std::cout << "data: " << data_ << std::endl; }
};

int main() {
    A a(10);
    a.DoSomething(3);
    a.PrintData();
}

// mutable�� �� �ٿ� const�� ��������� ���� ���� ������?
// const�� ���� -> �� ��ü�� �̷��� ���� �� �� �ִٴ� �ǹ� / ��ü�� ���� ���¿� ������ ���� ���� 

class Server {
    // .... (����) ....
    mutable Cache cache; // ĳ��!
    // �� �Լ��� �����ͺ��̽����� user_id �� �ش��ϴ� ���� ������ �о ��ȯ�Ѵ�.
    // �����ͺ��̽��� ������Ʈ ���� �ʰ� �����ϴ� �۾��� ���⿡ const �Լ��� ���� 
    // �����ͺ��̽��� ��û�� �� �޾ƿ��� �۾��� �ð��� ���� �ɸ�
    // -> ĳ�ø� ����� ���� ��û�Ǵ� �����͸� ���� �����ͺ��̽����� ���� ã�� �ʾƵ� �޸𸮿��� ������ ��ȸ�� �� �ֵ��� ��
    User GetUserInfo(const int user_id) const {
        // 1. ĳ������ user_id �� �˻�
        Data user_data = cache.find(user_id);

        // 2. ������ ĳ���� �����Ͱ� ���ٸ� �����ͺ��̽��� ��û
        if (!user_data) {
            user_data = Database.find(user_id);

            // �� �� ĳ���� user_data ���
            // ĳ�ø� ������Ʈ �ϴ� �۾��� ������ �� ����. -> ĳ�� ������ ������ �ٲ�ߵȴٴ� �ǹ� 
            // GetUserInfo���� const�� �� �� ���� -> ����� ���忡�� �翬�� const�� ���ǵǾ���ϴ� �Լ� �̱� ����
            //���� �� ��� cache�� mutable�� ����
            cache.update(user_id, user_data); // <-- �Ұ���
        }

        // 3. ���ϵ� ������ User ��ü ����
        return User(user_data);
    }
};