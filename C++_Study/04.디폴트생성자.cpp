// ����Ʈ ������ �����غ���
#include <iostream>

class Date {
    int year_;
    int month_;  // 1 ���� 12 ����.
    int day_;    // 1 ���� 31 ����.

public:
    void ShowDate();

    Date() {
        year_ = 2012;
        month_ = 7;
        day_ = 12;
    }
};

void Date::ShowDate() {
    std::cout << "������ " << year_ << " �� " << month_ << " �� " << day_
        << " �� �Դϴ� " << std::endl;
}

int main() {
    Date day = Date();

    // ����Ʈ ������(Default Constructor) -> ���ڸ� �ϳ��� ������ �ʴ� ������
    // Ŭ�������� ����ڰ� ��� �����ڵ� ��������� �������� �ʾ��� ��쿡 �����Ϸ��� �ڵ����� �߰����ִ� ������
    Date day2;

    // ����Ʈ �����ڸ� �̿��ؼ� �ʱ�ȭ �ϴ� ���� �ƴ�
    // ���ϰ��� Date �̰� ���ڰ� ���� �Լ� day3 �� �����ϰ� �� ������ �ν�
    //Date day3();

    day.ShowDate();
    day2.ShowDate();

    return 0;
}

class Test {
public:
    Test() = default;  // ����Ʈ �����ڸ� �����ض�
};