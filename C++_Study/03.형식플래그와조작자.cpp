#include <string>
#include <iostream>

int main() {
    int t;
    while (true) {
        // setf �Լ� ���� 2������ ���ڸ� 1���� �޴� �Ͱ� ���ڸ� 2�� ���� �� �ִ�.
        // ���ڸ� 1�� �޴� ���� ���ڷ� �� ���� �÷��׸� ���� 
        // 2�� ���ϴ� ���� �� ��° ������ ������ �ʱ�ȭ �ϰ� ù ��° ���ڸ� �����ϴ� ��
        std::cin.setf(std::ios_base::hex, std::ios_base::basefield);
        std::cin >> t;
        std::cout << "�Է� :: " << t << std::endl;
        if (std::cin.fail()) {
            std::cout << "����� �Է����ּ���" << std::endl;
            std::cin.clear();  // �÷��׵��� �ʱ�ȭ �ϰ�
                               // std::cin.ignore(100,'n');//���๮�ڰ� ���� ������
                               // �����Ѵ�
        }
        if (t == 0) break;
    }

    //ff
    //�Է� :: 255
    //0xFF
    //�Է� :: 255
    //123
    //�Է� :: 291
    //ABCDE
    //�Է� :: 703710

    while (true) {
        // ������ - ��Ʈ���� �����Ͽ� �Է� Ȥ�� ��� ����� �ٲ��ִ� �Լ�
        std::cin >> std::hex >> t;
        std::cout << "�Է� :: " << t << std::endl;
        if (std::cin.fail()) {
            std::cout << "����� �Է����ּ���" << std::endl;
            std::cin.clear();           // �÷��׵��� �ʱ�ȭ �ϰ�
            std::cin.ignore(100, 'n');  //���๮�ڰ� ���� ������ �����Ѵ�
        }
        if (t == 0) break;
    }

    //ff
    //�Է� :: 255
    //0xFF
    //�Է� :: 255
    //123
    //�Է� :: 291
    //ABCDE 
    //�Է� :: 703710
}