#include <iostream>

class A {
    // 멤버 변수를 mutable로 선언했을 시 const 함수에서 값 변경 가능
    mutable int data_;
    //int data_;

public:
    A(int data) : data_(data) {}
    // const 멤버 함수 내부에서 멤버 변수들의 값을 바꾸는 것 불가능 
    void DoSomething(int x) const {
        data_ = x;  // 불가능!
    }

    void PrintData() const { std::cout << "data: " << data_ << std::endl; }
};

int main() {
    A a(10);
    a.DoSomething(3);
    a.PrintData();
}

// mutable을 쓸 바에 const를 떼어버리는 것이 낫지 않을까?
// const로 선언 -> 이 객체는 이러한 일을 할 수 있다는 의미 / 객체의 내부 상태에 영향을 주지 않음 

class Server {
    // .... (생략) ....
    mutable Cache cache; // 캐쉬!
    // 이 함수는 데이터베이스에서 user_id 에 해당하는 유저 정보를 읽어서 반환한다.
    // 데이터베이스로 업데이트 하지 않고 수정하는 작업이 없기에 const 함수로 선언 
    // 데이터베이스에 요청한 후 받아오는 작업은 시간이 오래 걸림
    // -> 캐시를 만들어 자주 요청되는 데이터를 굳이 데이터베이스까지 가서 찾지 않아도 메모리에서 빠르게 조회할 수 있도록 함
    User GetUserInfo(const int user_id) const {
        // 1. 캐쉬에서 user_id 를 검색
        Data user_data = cache.find(user_id);

        // 2. 하지만 캐쉬에 데이터가 없다면 데이터베이스에 요청
        if (!user_data) {
            user_data = Database.find(user_id);

            // 그 후 캐쉬에 user_data 등록
            // 캐시를 업데이트 하는 작업을 수행할 수 없다. -> 캐시 내부의 정보를 바꿔야된다는 의미 
            // GetUserInfo에서 const를 뗄 수 없음 -> 사용자 입장에서 당연히 const로 정의되어야하는 함수 이기 때문
            //따라서 이 경우 cache를 mutable로 선언
            cache.update(user_id, user_data); // <-- 불가능
        }

        // 3. 리턴된 정보로 User 객체 생성
        return User(user_data);
    }
};