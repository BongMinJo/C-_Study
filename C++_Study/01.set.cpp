#include <iostream>
#include <set>

template <typename T>
void print_set(std::set<T>& s) {
    // 셋의 모든 원소들을 출력하기
    std::cout << "[ ";
    // BidirectionalIterator 순차적으로 하나씩 접근
    for (typename std::set<T>::iterator itr = s.begin(); itr != s.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << " ] " << std::endl;
}
int main() {
    std::set<int> s;
    // 어디에 추가할지에 대한 정보가 없다
    // 원소를 추가하거나 지우는 작업 O(logN)
    // 내부에 원소를 추가할 때 정렬된 상태를 유지하며 추가 
    s.insert(10);
    s.insert(50);
    s.insert(20);
    s.insert(40);
    s.insert(30);

    std::cout << "순서대로 정렬되서 나온다" << std::endl;
    print_set(s);

    std::cout << "20 이 s 의 원소인가요? :: ";
    // 원소 존재 시 반복자를 리턴 std::set<>::iterator
    // 아닐 시 s.end() 리턴
    // O(logN) 정렬된 상태를 유지하기 때문
    // 내부적으로 트리 구조 구성 
    auto itr = s.find(20);
    if (itr != s.end()) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    std::cout << "25 가 s 의 원소인가요? :: ";
    itr = s.find(25);
    if (itr != s.end()) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    // set 안에는 중복된 원소들이 없다
    // 중복된 원소를 허락하고 싶다면 멀티셋을 사용하면 된다.
    std::set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(20);
    s.insert(10);

    print_set(s);
}