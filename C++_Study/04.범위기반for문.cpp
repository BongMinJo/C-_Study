#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
    // ��ü ���͸� ����ϱ�
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end();
        ++itr) {
        std::cout << *itr << std::endl;
    }
}

template <typename T>
void print_vector_range_based(std::vector<T>& vec) {
    // ��ü ���͸� ����ϱ�
    for (const auto& elem : vec) {
        std::cout << elem << std::endl;
    }
}

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    // range-based for ��
    // elem = vec[i];
    // ���� �����ؼ� ���
    for (int elem : vec) {
        std::cout << "���� : " << elem << std::endl;
    }

    std::cout << "print_vector" << std::endl;
    print_vector(vec);
    std::cout << "print_vector_range_based" << std::endl;
    // ��� ���۷����� ����
    print_vector_range_based(vec);

    return 0;
}