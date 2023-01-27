// ������ �Է��� �����ϴ� Ŭ����
// operator>>�� istreamŬ������ ���ǵǾ� �ִ� ������
// cin�� istream Ŭ������ ��ü �� �ϳ�

#include <iostream>
#include <string>

int main() {
    std::string s;
    while (true) {

        // ��� ���鹮��(����, ����, ��)�� �Է½ÿ� �����ع�����.
        std::cin >> s;
        std::cout << "word : " << s << std::endl;
    }
    //this is a long sentence
    //word : this
    //word : is
    //word : a
    //word : long
    //word : sentence
    //ABCD EFGH IJKL
    //word : ABCD
    //word : EFGH
    //word : IJKL
    int t;
 
    while (true) {
        std::cin >> t;
        std::cout << "�Է� :: " << t << std::endl;
        if (t == 0) break;
    }
    //3
    //�Է� :: 3
    //4
    //�Է� :: 4
    //5
    //�Է� :: 5
    //6
    //�Է� :: 6
    //7
    //�Է� :: 7

    // ���ڰ� �ƴ� ���ڸ� �Է������� ���� ������ ������ �ȴ�.
    // ios Ŭ�������� ��Ʈ���� ���¸� ����
    // ��Ʈ���� ���¸� �����ϴ� �÷��״� 4���� ����
    // goodbit - ��Ʈ���� ����� �۾��� ������ ��
    // badbit - ��Ʈ���� ���� �Ұ����� ���� �߻� ��
    // failbit - ��Ʈ���� ���� ������ ���� �߻� ��
    // eofbit - �Է� �۾��� EOF ���޽� 
    // ���ڸ� �Է½� failbit�� ������ �Է°��� ���� �ʰ� �����ع�����.
    // �����ع����鼭 ���ۿ� ���� �ִ� 'c\n'�� ���ڿ��� �մ��� �ʴ´�. 

    // operator void*() const;
    // ios ��ü�� void*�� ��ȯ
    // NULL �����Ͱ� �ƴ� ���� �����ϴ� ������ failbit, badbit�� ��� off�϶�
    // �� ��Ʈ���� ���������� ����� �۾��� ������ �� ���� �� 
    // ���ڸ� �Է½� operator>> �� cin ��ü�� failbit�� �ѰԵȴ�.
    // �׸��� std::cin >> t �Ŀ� cin�� ���ϵǴµ� ���ϰ��� while ���� ���ǽ����� ���� ������ �����Ϸ��� ������ Ÿ�� ��ȯ�� ã�� �ȴ�.
    // ios ��ü -> void * -> bool �� 2�� ��ȯ�� ���� while���� �� �������´�.
    while (std::cin >> t) {
        std::cout << "�Է� :: " << t << std::endl;
        if (t == 0) break;
    }

    std::cin >> t;  // ���������� ���ڸ� �Է��ϸ� failbit �� ������
    std::cout << "fail ��Ʈ�� ���� �����̹Ƿ�, �Է¹��� �ʴ´�" << std::endl;
    std::string s;
    std::cin >> s;
    //s
    //fail ��Ʈ�� ���� �����̹Ƿ�, �Է¹��� �ʴ´�

    while (true) {
        std::cin >> t;
        std::cout << "�Է� :: " << t << std::endl;
        if (std::cin.fail()) {
            std::cout << "����� �Է����ּ���" << std::endl;
            std::cin.clear();            // �÷��׵��� �ʱ�ȭ �ϰ� / �÷��׸� goodbit�� �ʱ�ȭ
            std::cin.ignore(100, '\n');  // ���๮�ڰ� ���� �� ���� �����Ѵ� / ���۸� ����.
        }
        if (t == 1) break;
    }
    //a
    //�Է� :: 0
    //����� �Է����ּ���
    //x
    //�Է� :: 0
    //����� �Է����ּ���
    //d
    //�Է� :: 0
    //����� �Է����ּ���
    //asdf
    //�Է� :: 0
    //����� �Է����ּ���
    //2
    //�Է� :: 2
    //1
    //�Է� :: 1
}