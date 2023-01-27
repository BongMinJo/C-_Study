// �ݺ��� ��� ����
#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
    // ��ü ���͸� ����ϱ�
    // iterator�� std::vector<T>�� ���� Ÿ��
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end();
        ++itr) {
        std::cout << *itr << std::endl;
    }
}

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    // ��ü ���͸� ����ϱ�
    // begin() vector�� ù��° ���Ҹ� ����Ű�� �ݺ��ڸ� ����
    // end() vector�� ������ ���� �� ĭ �ڸ� ����Ű�� �ݺ��ڸ� ���� -> �� ���͸� ǥ���� �� �ִ�.

    // vector�� �ݺ��� Ÿ���� std::vector<>::iterator ���Ÿ������ ����
    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
       // * �����ڸ� �����ε��� ������ó�� �����Ѵ�.
        std::cout << *itr << std::endl;
    }

    // int arr[4] = {10, 20, 30, 40}
    // *(arr + 2) == arr[2] == 30;
    // *(itr + 2) == vec[2] == 30;

    std::vector<int>::iterator itr = vec.begin() + 2;
    std::cout << "3 ��° ���� :: " << *itr << std::endl;

    std::cout << "ó�� ���� ����" << std::endl;
    print_vector(vec);
    std::cout << "----------------------------" << std::endl;

    // insert, erase O(n)
    // vec[2] �տ� 15 �߰�
    vec.insert(vec.begin() + 2, 15);
    print_vector(vec);

    std::cout << "----------------------------" << std::endl;
    // vec[3] ����
    vec.erase(vec.begin() + 3);
    print_vector(vec);

    std::vector<int>::iterator itr = vec.begin();
    std::vector<int>::iterator end_itr = vec.end();

    // ���� �߻� 
    // ������ ����Ͽ��� ��� �ݺ��ڵ��� ����� �� ����.
    // vec.erase(itr) �� �����ϰ� �Ǹ� ���̻� itr �� ��ȿ�� �ݺ��ڰ� �ƴϴ�.
    /*for (; itr != end_itr; ++itr) {
        if (*itr == 20) {
            vec.erase(itr);
        }
    }*/


    // itr�� ��ȿ�� �ݺ��ڰ� �ƴϱ� ������ vec.end()�� �ùٸ� end �ݺ��� ���� �Ź� ������ �͵� for���� ������ �ʰԵȴ�.
    /*std::vector<int>::iterator itr = vec.begin();

    for (; itr != vec.end(); ++itr) {
        if (*itr == 20) {
            vec.erase(itr);
            itr = vec.begin();
        }
    }*/


    // �ݺ��ڸ� ���� �ʰ� erase�Լ����� �ݺ��ڸ� ���� ����
    for (std::vector<int>::size_type i = 0; i != vec.size(); i++) {
        if (vec[i] == 20) {
            vec.erase(vec.begin() + i);
            i--;
        }
    }

    std::cout << "���� 20 �� ���Ҹ� �����!" << std::endl;
    print_vector(vec);


    // itr �� vec[2] �� ����Ų��.
    std::vector<int>::iterator itr = vec.begin() + 2;

    // vec[2] �� ���� 50���� �ٲ۴�.
    *itr = 50;

    std::cout << "---------------" << std::endl;
    print_vector(vec);

    std::vector<int>::const_iterator citr = vec.cbegin() + 2;

    // ��� �ݺ��ڰ� ����Ű�� ���� �ٲܼ� ����. �Ұ���!
    //*citr = 30;


    std::cout << "������ vec ����ϱ�!" << std::endl;
    // itr �� vec[2] �� ����Ų��.
    // ���ݺ��ڴ� ���� �����ϸ� ���� ���ҷ� ����.
    std::vector<int>::reverse_iterator r_iter = vec.rbegin();
    for (; r_iter != vec.rend(); r_iter++) {
        std::cout << *r_iter << std::endl;
    }

    // ������ ���� ����ϱ�
    // segmentation fault �߻� -> vector �� index �� ����ϴ� Ÿ���� ��ȣ ���� �����̱� ���� 
    // -1�� ��� �ش� Ÿ�Կ��� ���� ū ������ �ȴ�. for�� ������� �ʴ´�.
    for (std::vector<int>::size_type i = vec.size() - 1; i >= 0; i--) {
        std::cout << vec[i] << std::endl;
    }

}