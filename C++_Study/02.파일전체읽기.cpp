#include <fstream>
#include <iostream>
#include <string>

int main() {

    // ���� ��ü�� �ѹ��� �б�
    // ���� �б� �غ�
    std::ifstream in("test.txt");
    std::string s;

    if (in.is_open()) {
        // ��ġ �����ڸ� ���� ������ �ű��.
        // �� ��° ���ڴ� ���� �� ��ġ�� �ǹ�, ù ��° ���ڴ� �� ��ġ�κ��� �󸶳� ��ŭ ������ �ִ��ĸ� �ǹ�
        in.seekg(0, std::ios::end);

        // �׸��� �� ��ġ�� �д´�. (������ ũ��)
        // tellg �Լ��� ��ġ �������� ��ġ (���� �������κ���) ��ȯ
        int size = in.tellg();

        // �� ũ���� ���ڿ��� �Ҵ��Ѵ�.
        s.resize(size);

        // ��ġ �����ڸ� �ٽ� ���� �� ������ �ű��.
        in.seekg(0, std::ios::beg);

        // ���� ��ü ������ �о ���ڿ��� �����Ѵ�.
        in.read(&s[0], size);
        std::cout << s << std::endl;
    }
    else {
        std::cout << "������ ã�� �� �����ϴ�!" << std::endl;
    }


    // ���� ��ü�� �� �پ� �б�
    std::ifstream in("test.txt");
    char buf[100];

    if (!in.is_open()) {
        std::cout << "������ ã�� �� �����ϴ�!" << std::endl;
        return 0;
    }

    // ifstream���� �ڱ� �ڽ��� bool�� ĳ������ �� �ִ� ĳ���� �����ڰ� �����ε� �Ǿ��ִ�.
    // true�̱� ���ؼ��� ���� �Է� �۾��� �������̾�߸� �ϰ� ���� ��Ʈ���� ���� �÷��װ� Ŀ�� ���� �ʾƾ߸� �Ѵ�.
    while (in) {
        // getline �Լ��� ���Ͽ��� ���๮��(\n)�� ���� �� ���� �ִ� ������ ũ�� -1��ŭ �д´�.
        // �ϳ� ���� �д� ������ buf �� ������ ���ڷ� �� ���� ���ڸ� �־���� �ϱ� ����
        // getline �Լ��� ���� ���ڰ� ������ ���� ������ ������ ũ�Ⱑ �� ���� �ȴٸ� failbit �� Ű�� �ȴ�.
        in.getline(buf, 100);
        
        // ���๮�ڰ� �ƴ� ������ ���ڰ� ���ö����� �д� ������ �ٲٴ� ��
        //in.getline(buf, 100, '.');

        std::cout << buf << std::endl;
    }

    std::string s;
    while (in) {
        // ���� ũ���� �Ѱ踦 �غ��ϱ� ���� string ���� getline�Լ� ����
        // getline�� ifstream�� ���ǵǾ� �ִ°� �ƴ� std::string�� ���ǵǾ� �ִ� �Լ��� ��� 
        // ù ��° ���ڷ� istream��ü�� �ް� �� ��° ���ڷ� �Է� ���� ���ڿ��� ������ string ��ü�� �޴´�.
        getline(in, s);
        std::cout << s << std::endl;
    }

    return 0;
}