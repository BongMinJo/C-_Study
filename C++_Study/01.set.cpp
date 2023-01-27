#include <iostream>
#include <set>

template <typename T>
void print_set(std::set<T>& s) {
    // ���� ��� ���ҵ��� ����ϱ�
    std::cout << "[ ";
    // BidirectionalIterator ���������� �ϳ��� ����
    for (typename std::set<T>::iterator itr = s.begin(); itr != s.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << " ] " << std::endl;
}
int main() {
    std::set<int> s;
    // ��� �߰������� ���� ������ ����
    // ���Ҹ� �߰��ϰų� ����� �۾� O(logN)
    // ���ο� ���Ҹ� �߰��� �� ���ĵ� ���¸� �����ϸ� �߰� 
    s.insert(10);
    s.insert(50);
    s.insert(20);
    s.insert(40);
    s.insert(30);

    std::cout << "������� ���ĵǼ� ���´�" << std::endl;
    print_set(s);

    std::cout << "20 �� s �� �����ΰ���? :: ";
    // ���� ���� �� �ݺ��ڸ� ���� std::set<>::iterator
    // �ƴ� �� s.end() ����
    // O(logN) ���ĵ� ���¸� �����ϱ� ����
    // ���������� Ʈ�� ���� ���� 
    auto itr = s.find(20);
    if (itr != s.end()) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    std::cout << "25 �� s �� �����ΰ���? :: ";
    itr = s.find(25);
    if (itr != s.end()) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    // set �ȿ��� �ߺ��� ���ҵ��� ����
    // �ߺ��� ���Ҹ� ����ϰ� �ʹٸ� ��Ƽ���� ����ϸ� �ȴ�.
    std::set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(20);
    s.insert(10);

    print_set(s);
}