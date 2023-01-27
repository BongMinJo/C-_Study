// 덱 - 임의의 위치에 원소에 접근할 수 있으며 맨 뒤 원소 추가 / 제거 O(1)
// 맨 앞 원소 추가 / 제거 O(1)
// 임의의 위치에 있는 원소 추가 / 제거 O(n)
// 벡터보다 빠른 이유 - 벡터는 새로운 원소를 추가시 할당된 메모리가 꽉 차면 모든 원소들을 새로운 공간에 복사해야 한다.
// 덱의 경우 원소들이 실제로 메모리 상에서 연속적으로 존재하지 않는다.
// 원소들이 어디에 저장되어 있는지에 대한 정보를 보관하기 위해 추가적인 메모리가 더 필요
// 실행 속도를 위해 메모리를 많이 사용하는 컨테이너

// [] 와 at 함수를 제공하고 있고, 반복자 역시 RandomAccessIterator 타입
#include <deque>
#include <iostream>

template <typename T>
void print_deque(std::deque<T>& dq) {
    // 전체 덱을 출력하기
    std::cout << "[ ";
    for (const auto& elem : dq) {
        std::cout << elem << " ";
    }
    std::cout << " ] " << std::endl;
}
int main() {
    std::deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(30);
    dq.push_front(40);

    std::cout << "초기 dq 상태" << std::endl;
    print_deque(dq);

    std::cout << "맨 앞의 원소 제거" << std::endl;
    dq.pop_front();
    print_deque(dq);
}