#include <iostream>

class MyString {
    char* string_content;  // ���ڿ� �����͸� ����Ű�� ������
    int string_length;     // ���ڿ� ����

    int memory_capacity;

public:
    //// capacity ��ŭ �̸� �Ҵ���.
    //MyString(int capacity);

    // capacity ��ŭ �̸� �Ҵ���. (explicit Ű���忡 �ָ�)
    explicit MyString(int capacity);

    // ���ڿ��� ���� ����
    MyString(const char* str);

    // ���� ������
    MyString(const MyString& str);

    ~MyString();

    int length() const;
};

MyString::MyString(int capacity) {
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;
    std::cout << "Capacity : " << capacity << std::endl;
}

MyString::MyString(const char* str) {
    string_length = 0;
    while (str[string_length++]) {
    }

    string_content = new char[string_length];
    memory_capacity = string_length;

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}
MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }
void DoSomethingWithString(MyString s) {
    // Do something...
}
int main() { 
    MyString s(3); 
    DoSomethingWithString(MyString("abc"));

    // MyString �� ��������� �������� ���� ��� MyString::MyString(const char* str) �������� �Ͻ��� ��ȯ�� ���� ��ȯ�Ǿ� �����ϵȴ�.
    DoSomethingWithString("abc");

    // ����ڰ� �ǵ����� ���� �Ͻ��� ��ȯ�� �Ͼ 
    // explicit Ű���带 ����� ������ �ʴ� �Ͻ��� ��ȯ�� �� �� ������ �����Ϸ����� ���
    // �Ͻ��� ��ȯ�� ������ �� ���⿡ �Ķ���� Ÿ���� ���� �ʾ� ���� �߻�
    //DoSomethingWithString(3);

    MyString s = "abc";  // MyString s("abc")

    // explicit�� ���� ��� �����Ϸ��� �˾Ƽ� ������ �����ڸ� ��� ȣ��
    //MyString s = 5;      // MyString s(5)

    // explicit�� MyString(int capacity) �� ���� �� ��������� �����ڸ� �θ� ������ ���
    MyString s(5);   // ���
    //MyString s = 5;  // ������ ����!



}