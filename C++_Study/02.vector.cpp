#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    // 맨 뒤에 원소 추가 - push_back 제거 - pop_back
    vec.push_back(10);  // 맨 뒤에 10 추가
    vec.push_back(20);  // 맨 뒤에 20 추가
    vec.push_back(30);  // 맨 뒤에 30 추가
    vec.push_back(40);  // 맨 뒤에 40 추가

    for (std::vector<int>::size_type i = 0; i < vec.size(); i++) {
        // 임의의 원소 접근 [], at
        std::cout << "vec 의 " << i + 1 << " 번째 원소 :: " << vec[i] << std::endl;
    }
    // vector는 임의의 위치에 있는 원소에 접근, 맨 뒤에 새로운 원소 추가 제거는 O(1)로 수행
    
    // 맨 뒤에 원소를 추가하는 작업은 엄밀히 말하자면 amortized O(1)
    // vector은 현재 가지고 있는 원소의 개수보다 더 많은 공간을 할당
    // 할당된 공간을 다 채웠을 때 새로운 큰 공간을 다시 할당하고 기존의 원소들을 복사해야한다.
    // 이 경우 O(n)이 수행되는데 O(n)으로 수행되는 경우가 매우 드물어 평균은 O(1)로 수행된다.

    // 임의의 위치에 원소를 추가하거나 제거하는 것은 O(n)
    // 어떤 자리에 새로운 원소를 추가하거나 뺄 경우 그 뒤에 오는 원소들을 한 칸 씩 이동시켜 주어야한다.

    // 임의의 위치 원소 접근([], at) : O(1)
    // 맨 뒤에 원소 추가 및 제거(push_back / pop_back) : amortized O(1); (평균적으로 O(1) 이지만 최악의 경우 O(n))
    // 임의의 위치 원소 추가 및 제거(insert, erase) : O(n)
}