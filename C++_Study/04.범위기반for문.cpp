#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
    // 전체 벡터를 출력하기
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end();
        ++itr) {
        std::cout << *itr << std::endl;
    }
}

template <typename T>
void print_vector_range_based(std::vector<T>& vec) {
    // 전체 벡터를 출력하기
    for (const auto& elem : vec) {
        std::cout << elem << std::endl;
    }
}

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    // range-based for 문
    // elem = vec[i];
    // 값을 복사해서 사용
    for (int elem : vec) {
        std::cout << "원소 : " << elem << std::endl;
    }

    std::cout << "print_vector" << std::endl;
    print_vector(vec);
    std::cout << "print_vector_range_based" << std::endl;
    // 상수 레퍼런스로 접근
    print_vector_range_based(vec);

    return 0;
}