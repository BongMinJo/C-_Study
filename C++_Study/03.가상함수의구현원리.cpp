class Parent {
public:

	// 자바에서는 모든 함수들을 디폴트로 가상함수로 만들어서 언제나 동적 바인딩 동적
	// C++에서는 virtual 키워드를 사용해야한다.
	// 가상함수를 사용시 약간의 오버헤드 존재
	// 이로인해 C++에서는 멤버 함수가 디폴트로 가상함수가 되도록 설정하지 않는다.
	virtual void func1();
	virtual void func2();
};
class Child : public Parent {
public:
	// C++ 컴파일러는 가상 함수가 하나라도 존재하는 클래스에 대해 가상 함수 테이블을 만든다.

	virtual void func1();
	void func3();
};

int main() {
	Parent* p = new Parent();
	p->func1();

	Parent* c = new Child();
	// 가상 함수 테이블을 참초하여 Child::func1()을 호출 
	// Parent::func() 오버라이드
	c->func1();
}