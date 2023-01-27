// list - ����� ���� ������ ���� �ڷ���
// vector�� �޸� ������ ��ġ�� �ִ� ���ҿ� ������ �� ����.
// ���� ���ҿ� ������ ������ ��ġ�� ���
// ������ ��ġ�� ���Ҹ� �߰��ϰų� �����ϴ� �۾� O(1)

#include <iostream>
#include <list>

template <typename T>
void print_list(std::list<T>& lst) {
    std::cout << "[ ";
    // ��ü ����Ʈ�� ����ϱ� (�� ���� ���� ��� for ���� �� �� �ֽ��ϴ�)
    for (const auto& elem : lst) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
        std::cout << *itr << std::endl;
    }

    // ������ ��ġ ���� ����ų �� ����.
    // �ݺ��ڴ� ���� �� ĭ �� �ۿ� ������ �� ����.
    // �޸� �󿡼� ���ҵ��� ���������� �������� ���� �� �ִ�.
    //itr + 5  // �Ұ���!

    // ����Ʈ�� ���ǵǴ� �ݺ����� Ÿ�� - BidirectionalIterator 
    // ��������� �̵��� �� �ֵ�, �� ĭ �� �ۿ� �̵��� �� ����.
     
    // ���Ϳ��� ���ǵǴ� �ݺ��� Ÿ�� - RandomAccessIterator 
    // ������ ��ġ�� ������ �� �ִ� �ݺ���
    std::cout << "ó�� ����Ʈ�� ���� " << std::endl;
    print_list(lst);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
        // ���� ���� ���Ұ� 20 �̶��
        // �� �տ� 50 �� ����ִ´�.
        if (*itr == 20) {
            lst.insert(itr, 50);
        }
    }

    std::cout << "���� 20 �� ���� �տ� 50 �� �߰� " << std::endl;
    print_list(lst);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
        // ���� 30 �� ���Ҹ� �����Ѵ�.
        // ����Ʈ�� ��� ���Ϳ� �ٸ��� ���Ҹ� ������ �ݺ��ڰ� ��ȿȭ ���� �ʴ´�.
        if (*itr == 30) {
            lst.erase(itr);
            break;
        }
    }

    std::cout << "���� 30 �� ���Ҹ� �����Ѵ�" << std::endl;
    print_list(lst);
}