// list - 양방향 연결 구조를 가진 자료형
// vector와 달리 임의의 위치에 있는 원소에 접근할 수 없다.
// 시작 원소와 마지막 원소의 위치만 기억
// 임의의 위치에 원소를 추가하거나 제거하는 작업 O(1)

#include <iostream>
#include <list>

template <typename T>
void print_list(std::list<T>& lst) {
    std::cout << "[ ";
    // 전체 리스트를 출력하기 (이 역시 범위 기반 for 문을 쓸 수 있습니다)
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

    // 임의의 위치 원소 가리킬 수 없다.
    // 반복자는 오직 한 칸 씩 밖에 움직일 수 없다.
    // 메모리 상에서 원소들이 연속적으로 존재하지 않을 수 있다.
    //itr + 5  // 불가능!

    // 리스트에 정의되는 반복자의 타입 - BidirectionalIterator 
    // 양방향으로 이동할 수 있되, 한 칸 씩 밖에 이동할 수 없다.
     
    // 벡터에서 정의되는 반복자 타입 - RandomAccessIterator 
    // 임의의 위치에 접근할 수 있는 반복자
    std::cout << "처음 리스트의 상태 " << std::endl;
    print_list(lst);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
        // 만일 현재 원소가 20 이라면
        // 그 앞에 50 을 집어넣는다.
        if (*itr == 20) {
            lst.insert(itr, 50);
        }
    }

    std::cout << "값이 20 인 원소 앞에 50 을 추가 " << std::endl;
    print_list(lst);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
        // 값이 30 인 원소를 삭제한다.
        // 리스트의 경우 벡터와 다르게 원소를 지워도 반복자가 무효화 되지 않는다.
        if (*itr == 30) {
            lst.erase(itr);
            break;
        }
    }

    std::cout << "값이 30 인 원소를 제거한다" << std::endl;
    print_list(lst);
}