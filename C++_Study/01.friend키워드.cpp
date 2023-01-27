class A {
private:
    void private_func() {}
    int private_num;

    // friend로 정의된 클래스나 함수들은 원래 클래스의 private로 정의된 변수나 함수들에 접근할 수 있다.
    // B는 A의 모든 private을 볼 수 있지만 B안에서 A를 friend로 지정하지 않는 이상 A는 B의 privae 개체들에 접근 불가 
    // B 는 A 의 친구!
    friend class B;

    // func 은 A 의 친구!
    // 클래스 안에 있다고 멤버 함수 아님
    friend void func();
};

class B {
public:
    void b() {
        A a;

        // 비록 private 함수의 필드들이지만 친구이기 때문에 접근 가능하다.
        a.private_func();
        a.private_num = 2;
    }
};

void func() {
    A a;

    // 비록 private 함수의 필드들이지만 위와 마찬가지로 친구이기 때문에 접근
    // 가능하다.
    a.private_func();
    a.private_num = 2;
}

int main() {}