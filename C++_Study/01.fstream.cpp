// ���Ͽ����� �����
#include <fstream>
#include <iostream>
#include <string>

int main() {
    // ���� �б� �غ�
    // test.txt�� �о�帮�� ��δ� ���־� ��Ʃ��� �󿡼� �����Ͽ��� �� �ҽ������� ����ִ� ��ġ�� ����
    // ifstream ��ü�� �Ҹ��ڿ��� �ڵ������� close
    std::ifstream in("test.txt");
    std::string s;

    if (in.is_open()) {
        in >> s;
        std::cout << "�Է� ���� ���ڿ� :: " << s << std::endl;
    }
    else {
        std::cout << "������ ã�� �� �����ϴ�!" << std::endl;
    }

    // ���ο� ���Ͽ��� ���� ��ü�� �Է� �ޱ� ���� ���� ���� ��Ʈ������ ���� ����
    in.close();
    in.open("other.txt");

    if (in.is_open()) {
        in >> s;
        std::cout << "�Է� ���� ���ڿ� :: " << s << std::endl;
    }
    else {
        std::cout << "������ ã�� �� �����ϴ�!" << std::endl;
    }


    // �����ڿ� �ɼ����� binary ���·� �ްڴٰ� ���
    // �����ڿ� �ɼ����� binary ���·� �ްڴٰ� ���
    std::ifstream in("test.txt", std::ios::binary);
    std::string s;

    int x;
    if (in.is_open()) {
        // 4����Ʈ�� ������ ������� �ǹ�
        // �� ��° ���ڷ� �� ����Ʈ ���� �� ����
        in.read((char*)(&x), 4);
        std::cout << std::hex << x << std::endl;

        char x[10];
        in.read(x, 10);
    }
    else {
        std::cout << "������ ã�� �� �����ϴ�!" << std::endl;
    }

    return 0;
}