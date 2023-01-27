// 반복자 사용 예시
#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T>& vec) {
    // 전체 벡터를 출력하기
    // iterator이 std::vector<T>의 의존 타입
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

    // 전체 벡터를 출력하기
    // begin() vector의 첫번째 원소를 가리키는 반복자를 리턴
    // end() vector의 마지막 원소 한 칸 뒤를 가리키는 반복자를 리턴 -> 빈 벡터를 표현할 수 있다.

    // vector의 반복자 타입은 std::vector<>::iterator 멤버타입으로 정의
    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
       // * 연산자를 오버로딩해 포인터처럼 동작한다.
        std::cout << *itr << std::endl;
    }

    // int arr[4] = {10, 20, 30, 40}
    // *(arr + 2) == arr[2] == 30;
    // *(itr + 2) == vec[2] == 30;

    std::vector<int>::iterator itr = vec.begin() + 2;
    std::cout << "3 번째 원소 :: " << *itr << std::endl;

    std::cout << "처음 벡터 상태" << std::endl;
    print_vector(vec);
    std::cout << "----------------------------" << std::endl;

    // insert, erase O(n)
    // vec[2] 앞에 15 추가
    vec.insert(vec.begin() + 2, 15);
    print_vector(vec);

    std::cout << "----------------------------" << std::endl;
    // vec[3] 제거
    vec.erase(vec.begin() + 3);
    print_vector(vec);

    std::vector<int>::iterator itr = vec.begin();
    std::vector<int>::iterator end_itr = vec.end();

    // 오류 발생 
    // 기존에 사용하였던 모든 반복자들을 사용할 수 없다.
    // vec.erase(itr) 을 수행하게 되면 더이상 itr 은 유효한 반복자가 아니다.
    /*for (; itr != end_itr; ++itr) {
        if (*itr == 20) {
            vec.erase(itr);
        }
    }*/


    // itr이 유효한 반복자가 아니기 때문에 vec.end()로 올바른 end 반복자 값을 매번 가지고 와도 for문이 끝나지 않게된다.
    /*std::vector<int>::iterator itr = vec.begin();

    for (; itr != vec.end(); ++itr) {
        if (*itr == 20) {
            vec.erase(itr);
            itr = vec.begin();
        }
    }*/


    // 반복자를 쓰지 않고 erase함수에만 반복자를 만들어서 전달
    for (std::vector<int>::size_type i = 0; i != vec.size(); i++) {
        if (vec[i] == 20) {
            vec.erase(vec.begin() + i);
            i--;
        }
    }

    std::cout << "값이 20 인 원소를 지운다!" << std::endl;
    print_vector(vec);


    // itr 은 vec[2] 를 가리킨다.
    std::vector<int>::iterator itr = vec.begin() + 2;

    // vec[2] 의 값을 50으로 바꾼다.
    *itr = 50;

    std::cout << "---------------" << std::endl;
    print_vector(vec);

    std::vector<int>::const_iterator citr = vec.cbegin() + 2;

    // 상수 반복자가 가리키는 값은 바꿀수 없다. 불가능!
    //*citr = 30;


    std::cout << "역으로 vec 출력하기!" << std::endl;
    // itr 은 vec[2] 를 가리킨다.
    // 역반복자는 값이 증가하면 앞쪽 원소로 간다.
    std::vector<int>::reverse_iterator r_iter = vec.rbegin();
    for (; r_iter != vec.rend(); r_iter++) {
        std::cout << *r_iter << std::endl;
    }

    // 끝에서 부터 출력하기
    // segmentation fault 발생 -> vector 의 index 를 담당하는 타입이 부호 없는 정수이기 때문 
    // -1일 경우 해당 타입에서 가장 큰 정수가 된다. for문 종료되지 않는다.
    for (std::vector<int>::size_type i = vec.size() - 1; i >= 0; i--) {
        std::cout << vec[i] << std::endl;
    }

}