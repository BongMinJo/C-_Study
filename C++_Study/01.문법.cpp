#include <iostream>

using namespace std;

int main() {
    int i = 1, sum = 0;

    // for ��
    for (i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }

    // while ��
    while (i <= 10) {
        sum += i;
        i++;
    }

    // if - else ��
    int lucky_number = 3;
    std::cout << "�� ��� ���� ���߾� ������~" << std::endl;

    int user_input;  // ����� �Է�

    while (1) {
        std::cout << "�Է� : ";
        std::cin >> user_input;
        if (lucky_number == user_input) {
            std::cout << "���߼̽��ϴ�~~" << std::endl;
            break;
        }
        else {
            std::cout << "�ٽ� �����غ�����~" << std::endl;
        }
    }

    // switch case ��
    int user_input;
    cout << "���� ������ ǥ�����ݴϴ�" << endl;
    cout << "1. �̸� " << endl;
    cout << "2. ���� " << endl;
    cout << "3. ���� " << endl;
    cin >> user_input;

    switch (user_input) {
    case 1:
        cout << "Psi ! " << endl;
        break;

    case 2:
        cout << "99 ��" << endl;
        break;

    case 3:
        cout << "����" << endl;
        break;

    default:
        cout << "�ñ��Ѱ� ������~" << endl;
        break;
    }

    return 0;
}